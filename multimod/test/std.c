#include<stdint.h>
uint64_t multimod(uint64_t a,uint64_t b,uint64_t m){
	return (unsigned __int128)a * b % m;
}
int main(){
	uint64_t a ,b, m;
	scanf("%llu,%llu,%llu",&a,&b,&m);
	printf("%llu", multimod(a,b,m));
	return 0;
}	
