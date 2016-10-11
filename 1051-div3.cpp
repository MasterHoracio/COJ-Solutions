#include <cstdio>

using namespace std;

typedef long long int lld;

int main(){
	lld n;

	scanf("%lld",&n);

	if(n % 3 == 0){
		printf("%lld\n",((n / 3) + 1) );
	}else{
		while(n % 3 != 0)
			n++;
		printf("%lld\n",(n / 3) );
	}
	return 0;
}