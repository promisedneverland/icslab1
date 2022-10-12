#include <stdint.h>
#include <stdio.h>
uint64_t m264;
uint64_t mod(uint64_t a,uint64_t b)
{
  uint64_t tmp = b;
  while( a >= b )
  {
    tmp = b;
    while((tmp<<1) < a && !(tmp & ((uint64_t)1<<63)))
      tmp <<= 1;
    a -= tmp;
  }
  return a;
}                                                           
uint64_t add(uint64_t *res, uint64_t b, uint64_t m)
{
  *res = mod(*res,m);
  b = mod(b,m);
  if(*res + b < b)
  {
    return b - m + *res;
  }
  else 
  {
    return mod((*res + b), m);
  }
}

uint64_t mult(uint64_t mi, uint64_t b, uint64_t m)
{
  uint64_t res = 0;
  for(int i = mi;i >= 1;i--)
  {
    if(b & ((uint64_t)1<<63))
    {
      add(&res, mult(i-1,m264, m), m);

    }
    
      b << 1;
      b = mod(b,m);
    
  }
  return add(&res, b, m);
}

uint64_t multimod(uint64_t a, uint64_t b, uint64_t m) {
  uint64_t tmp = 0;
  tmp = ~tmp;
  tmp = mod(tmp,m);
  tmp += 1;
  m264 = tmp;

  uint64_t res = 0;
  uint64_t mask = 1;
  a = mod(a,m);
  b = mod(b,m);

  for(int i=0;i<64;i++){
    if(mask & a)
      add(&res, mult(i, b, m), m);

    mask <<= 1;
  }
  // for(uint64_t i=0;i<a;i++){
	// res += b;
	// res %= m;	
  // }
  return res;
}
