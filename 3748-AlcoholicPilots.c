#include <stdio.h>

long long int min(long long int a, long long int b){
	if(a < b)
		return a;
	return b;
}

long long int max(long long int a, long long int b){
	if(a > b)
		return a;
	return b;
}

long long int gcd(long long int a, long long int b){
	if(a == 0)
		return b;
	else
		return gcd(b % a, a);
}

int main(){
	long long int v1, d1, v2, d2, num, den, tc = 1, GCD;
	long double t1, t2;

	while(scanf("%lld %lld %lld %lld",&v1,&d1,&v2,&d2)){
		if(v1 == 0 && d1 == 0 && v2 == 0 && d2 == 0)
			break;
		t1 = (long double)d1 / (long double)v1;
		t2 = (long double)d2 / (long double)v2;

		(t1 < t2) ? printf("Case #%lld: You owe me a beer!\n",tc) : printf("Case #%lld: No beer for the captain.\n",tc);

		den = v1 * v2;

		num = ((den / v1) * d1) + ((den / v2) * d2);
		den *= 2;

		GCD = gcd(min(den,num),max(den,num));

		num /= GCD;
		den /= GCD;

		(num % den == 0) ? printf("Avg. arrival time: %lld\n",num / den) : printf("Avg. arrival time: %lld/%lld\n",num ,den);
		tc++;
	}
	return 0;
}