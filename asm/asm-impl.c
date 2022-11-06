#include "asm.h"

#define inc(x) asm ("incl %[t];"\
       : [t] "+r"(x));
  
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
    "cmpb %%cl, $0\n\t"
    "movb $0,(%[dest])\n\t"
    "jz end\n\t"
    "movb (%[src]),%%cl\n\t"
    "movb %%cl,(%[dest])\n\t"
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
  return 0;
}

void asm_longjmp(asm_jmp_buf env, int val) {
  // longjmp(env, val);
  return ;
}
