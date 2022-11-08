#include "asm.h"
// #include <stdio.h>
int64_t asm_add(int64_t a, int64_t b) {
  asm(
    "addq %1, %0"
    :"+r" (b)
    :"r" (a)
  ); 
  return b; 
}

int asm_popcnt(uint64_t x) {
  uint64_t res = 0;
  uint64_t mask = 1;
  asm(
    ".L1:\n\t"
    "andq %[x],%[mask]\n\t"
    "shrq $1, %[x]\n\t"
    "addq %[mask], %[res]\n\t"
    "movq $1,%[mask]\n\t"
    "cmpq $0,%[x]\n\t"
    "jne .L1"

    :[res] "+&r" (res),[mask] "+&r"(mask)
    :[x] "r" (x)
    :"cc"
  ); 
  return res; 
}

void *asm_memcpy(void *dest, const void *src, size_t n) {
  // return memcpy(dest, src, n);
  unsigned char* ucdest = (unsigned char*)dest;
  unsigned char* ucsrc = (unsigned char*)src;
  asm volatile(
    "test:\n\t"
    "test %[n],%[n]\n\t"
    "jz end\n\t"
    "movb (%[src]),%%cl\n\t"
    "movb %%cl,(%[dest])\n\t"
    "test %%cl, %%cl\n\t"
    "jz end\n\t"
    "incq %[src]\n\t"
    "incq %[dest]\n\t"
    "decq %[n]\n\t"
    "jmp test\n\t"
    "end:\n\t"
    :[dest] "+&S"(ucdest),[src] "+&r" (ucsrc),[n] "+&r" (n)
    :
    :"cc","memory","cl"
  ); 
  return dest;
}
int asm_setjmp(asm_jmp_buf env) {
  // return setjmp(env);
  int ret = 0;
  asm volatile(
    "leaq (%%rip),%%rcx\n\t"
    "movq %%rcx,8(%[env])\n\t"
    "movq %%rsp,(%[env])\n\t"
    "movl 16(%[env]),%[ret]\n\t"
    : [ret] "=r" (ret) 
    : [env] "r" (env)
    :"memory","rcx"
  ); 
  // printf("env[0] = %lld,env[1] = %lld,ret = %d\n",env[0],env[1],ret);

  return ret;
}

void asm_longjmp(asm_jmp_buf env, int val) {
  // printf("val=%d\n",val);
  asm volatile(
    "movq 8(%[env]),%%rcx\n\t"
    "movq (%[env]),%%rsp\n\t"
    "movl %[val],16(%[env])\n\t"
    "jmp *(%%rcx)"
    : [val] "+r" (val) 
    : [env] "r" (env)
    :"memory","rcx"
  ); 
  
}
