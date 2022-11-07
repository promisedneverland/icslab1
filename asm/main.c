#include "asm.h"
#include <assert.h>
#include <stdio.h>

int main() {
  char s[5] = {'1','0',0,'4','5'};
  char d[5];
  asm_jmp_buf buf = {};
  int r = asm_setjmp(buf);
  if (r == 0) {
    // printf("%d\n",asm_add(1234, 5678) == 6912);
    // printf("%d\n",asm_popcnt(0x0123456789abcdefULL));
    // assert(asm_popcnt(0x000000000000000fULL) == 4);
    // TODO: add more tests here.
    // asm_memcpy(&d,&s,1);
    // printf("%s\n",d);
    
    printf("inif\n");
    asm_longjmp(buf, 123);
  } else {
    printf("inelse\n");
    assert(r == 123);
    printf("PASSED.\n");
  }
}
