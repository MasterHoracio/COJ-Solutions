#include <cstdio>
#include <cstring>
#include <cmath>

#define maxn 3005

using namespace std;

void sieve(int primes[]){
	
	for(int i = 1; i <= 3000; i++)
		primes[i] = 1;

	for(int i = 2; i * i <= 3000; i++)
		if(primes[i] == 1)
			for(int j = i * i; j <= 3000; j += i)
				primes[j] = 0;

}

bool solve(int primes[], int n){
	int sq = sqrt(n), count = 0;
	for(int i = 2; i <= sq; i++){
		if(n % i == 0){
			if(n / i != i){
				if(primes[n / i] == 1)
					count++;
				if(primes[i] == 1)
					count++;
			}else{
				if(primes[i] == 1)
					count++;
			}
		}
	}
	return (count == 2);
}

int main(){
	int n, ans = 0, primes[maxn];

	sieve(primes);

	scanf("%d",&n);

	for(int i = 1; i <= n; i++)
		if(solve(primes, i))
			ans++;

		printf("%d\n",ans);

	return 0;
}