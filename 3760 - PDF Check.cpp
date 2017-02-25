#include <cstdio>
#include <cmath>

using namespace std;

int check(int num){
	int sq = sqrt(num), ans = 0;
	for(int i = 1; i <= sq; i++){
		if(num % i == 0){
			if(i != num / i){
				ans += i;
				ans += num / i;
			}else{
				ans += num / i;
			}
		}
	}
	return ans - num;
}

int main(){
	int tc, a, b;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&a,&b);
		if(b == check(a)){
			printf("YES\n");
		}else if(a == check(b)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}