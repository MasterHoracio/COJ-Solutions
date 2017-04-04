#include <cstdio>

using namespace std;

typedef long long int lld;

int main(){
	lld tc, n;
	
	scanf("%lld",&tc);
	
	while(tc--){
		scanf("%lld",&n);
		printf("%lld\n",((n * n) + n + 2)/2);
	}
	
	return 0;
}
