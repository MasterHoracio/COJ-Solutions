#include <cstdio>
#include <cstring>
#include <cmath>

#define maxn 55

using namespace std;

typedef long long int lld;

lld primes[maxn], ans[maxn];

void sieve(){
	for(int i = 1; i <= 50; i++)
		primes[i] = 1;

	for(int i = 2; i * i <= 50; i++)
		if(primes[i] == 1)
			for(int j = i * i; j <= 50; j += i)
				primes[j] = 0;
}

void solve(){
	lld mult = 1;
	for(int i = 2; i <= 50; i++){
		if(primes[i])
			mult *= i;
		ans[i] = mult;
	}
}



int main(){
	int n;

	sieve();
	solve();

	while(scanf("%d",&n) && n != 0){
		printf("%lld\n",ans[n]);
	}
}