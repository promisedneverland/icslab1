#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#define N 10000000
#define blocksize 100
static bool is_prime[N];
static int  primes[N];

// int sqt(int n)
// {
//   int i = 1;
//   while(i*i < n)
//     i++;
//   return i - 1;
// }
int *sieve(int n) {
  assert(n + 1 < N);
   is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++)
    is_prime[i] = true;

  
  int blocknum = n/blocksize;

  // int nsqrt = sqt(n);
  int cnt = 0;
  for (int i = 2; i * i <= n; i++) {
    if(is_prime[i])
    {
      primes[cnt] = i;
      cnt++;
      for (int j = i + i; j * j  <= n ; j += i) {
        is_prime[j] = false;
      }
    }
   
  }
  int start,sieve_start;
  for(int bid = 0 ; bid < blocknum ; bid++)
  {
   start = bid * blocksize;
   for(int i = 0 ; i < cnt ; i++)
   {
    int p = primes[i];
    sieve_start = max((( start + p - 1 ) / p),p) * p;
    for(int j = sieve_start ; j <= start + blocksize ; j += p)
    {
      is_prime[j] = false;
    }
   }
   
  }

  if(n % blocksize != 0)
  {
    start = blocknum * blocksize;
    for(int i = 0 ; i < cnt ; i++)
    {
      int p = primes[i];
      sieve_start = (( start + p - 1 ) / p) * p;
      for(int j = sieve_start ; j <= n ; j += p)
      {
        is_prime[j] = false;
      }
    }
   
  }

  int *p = primes;
  for (int i = 2; i <= n; i++)
    if (is_prime[i]) {
      *p++ = i;
    }
  *p = 0;


  return primes;
}
