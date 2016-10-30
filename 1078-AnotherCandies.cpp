#include <cstdio>

using namespace std;

int main(){
	int TC, N, ans, num;

	scanf("%d",&TC);

	while(TC--){
		scanf("%d",&N);
		ans = 0;
		for(int i = 0; i < N; i++){
			scanf("%d",&num);
			ans += num;
		}
		(ans % N == 0) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}