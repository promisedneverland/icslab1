#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));
	printf("%lld %lld %lld", rand() , rand() , rand() );
}
