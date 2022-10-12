#include <stdint.h>

uint64_t multimod(uint64_t a, uint64_t b, uint64_t m) {
  uint64_t res = 0;
  
  for(uint64_t i=0;i<a;i++){
	res += b;
	res %= m;	
  }
  return res;
}
