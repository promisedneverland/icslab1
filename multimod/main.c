#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

uint64_t multimod(uint64_t, uint64_t, uint64_t);

void test(uint64_t a, uint64_t b, uint64_t m) {
  #define U64 "%" PRIu64
  printf(U64 " * " U64 " mod " U64 " = " U64 "\n", a, b, m, multimod(a, b, m));
}

int main() {
  uint64_t a ,b, m;
	scanf(U64 U64 U64,&a,&b,&m);
  test(a,b,m);
  // test(123, 456, 789);
  // test(123, 456, -1ULL);
  // test(-2ULL, -2ULL, -1ULL); // should be 1
}
