#include <cstdio>

using namespace std;

int main(){
	int tc, n, odd, even, num;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);

		even = odd = 0;

		for(int i = 0; i < n; i++){
			scanf("%d",&num);
			(num % 2 == 0) ? even++ : odd++;
		}

		printf("%d even and %d odd.\n",even,odd);
	}
	return 0;
}