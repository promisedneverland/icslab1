#include "asm.h"


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
    "shr $1, %[x]\n\t"
    "addq %[mask], %[res]\n\t"
    "movq $1,%[mask]\n\t"
    "cmpq $0,%[x]\n\t"
    "jne .L1"

    :[res] "+r" (res),[mask] "=r"(mask)
    :[x] "r" (x)
    :"cc"
  ); 
  return res; 
}

void *asm_memcpy(void *dest, const void *src, size_t n) {
  // return memcpy(dest, src, n);
  return NULL;
}

int asm_setjmp(asm_jmp_buf env) {
  // return setjmp(env);
  return 0;
}

void asm_longjmp(asm_jmp_buf env, int val) {
  // longjmp(env, val);
  return ;
}
