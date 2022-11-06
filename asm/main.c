#include "asm.h"
#include <assert.h>
#include <stdio.h>

int main() {
  char s[5] = {'1','1',0,0,0};
  char d[5];
  asm_jmp_buf buf;
  int r = asm_setjmp(buf);
  if (r == 0) {
    // printf("%d\n",asm_add(1234, 5678) == 6912);
    // printf("%d\n",asm_popcnt(0x0123456789abcdefULL));
    // assert(asm_popcnt(0x000000000000000fULL) == 4);
    // TODO: add more tests here.
    // asm_memcpy(s,d,4);
    printf("%s\n",s);
    asm_longjmp(buf, 123);

  } else {
    assert(r == 123);
    printf("PASSED.\n");
  }
}
