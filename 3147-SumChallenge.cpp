#include <cstdio>
#include <unordered_map>

using namespace std;

int main(){
	int tc, n, num, sum, zero;
	unordered_map<int, bool> MyMap;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		zero = sum = 0;

		for(int i = 0; i < n; i++){
			scanf("%d",&num);
			sum += num;
			if(sum == 0 || MyMap[sum] ){
				zero = 1;
			}else{
				MyMap[sum] = true;
			}
		}

		(zero) ? printf("YES\n") : printf("NO\n");

		MyMap.clear();
	}
	return 0;
}