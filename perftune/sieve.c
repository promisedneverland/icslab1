#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#define N 10000000
#define blocksize 100
static bool is_prime[N];
static int  primes[N];

int sqrt(int n)
{
  int i = 1;
  while(i*i < n)
    i++;
  return i - 1;
}
int *sieve(int n) {
  assert(n + 1 < N);
  for (int i = 0; i <= n; i++)
    is_prime[i] = true;

  int blocknum = n/blocksize + 1;
 
  int nsqrt = sqrt(n);

  for (int i = 2; i <= n; i++) {
    if(is_prime[i])
    for (int j = i + i; j <= n; j += i) {
      is_prime[j] = false;
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