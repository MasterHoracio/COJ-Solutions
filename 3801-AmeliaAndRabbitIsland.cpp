#include <cstdio>

#define MOD 0xF4240

using namespace std;

typedef long long int lld;

int main(){
	lld tc, n, r1, r2, acum, wek;
	
	scanf("%lld",&tc);
	
	while(tc--){
		scanf("%lld %lld %lld",&n,&r1,&r2);
		wek = 4;
		acum = r2;
		for(int i = 3; i <= n; i++){
			acum = r1 % MOD * r2 % MOD;
			acum %= MOD;
			r1 = r2 % MOD;
			r2 = acum % MOD;
			wek += 3;
		}
		printf("At week %lld we obtain %lld new rabbits.\n",wek,acum);
	}
	return 0;
}
