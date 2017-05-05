#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int lld;

int main(){
	lld num, pot, least;
	int tc;

	scanf("%d",&tc);

	while(tc--){
		scanf("%lld",&num);
		pot = 0;
		while(num != 0){
			if(num & 1){
				least = pow(2, pot);
				break;
			}
			num = num >> 1;
			++pot;
		}
		printf("%lld\n",least);
	}
	return 0;
}