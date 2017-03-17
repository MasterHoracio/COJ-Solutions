#include <cstdio>

using namespace std;

typedef long long int lld;

lld gcd(lld a, lld b){
	if(b == 0)
		return a;
	gcd(b, a % b);
}

int main(){
	lld a, b, c, GCD;
	
	while(scanf("%lld %lld %lld",&a,&b,&c)){
		if(a == 0 && b == 0 && c == 0)
			break;
		GCD = (a > b) ? gcd(a, b) : gcd(b, a);
		(c % GCD == 0) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
