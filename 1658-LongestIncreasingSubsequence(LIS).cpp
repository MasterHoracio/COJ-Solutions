#include <cstdio>

using namespace std;

int max(int a, int b){if(a > b) return a; return b;}

int main(){
	int tc, n, sub[1010], dp[1010], _max;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&sub[i]) , dp[i] = 1;

		for(int i = 1; i < n; i++)
			for(int j = 0; j < i; j++)
				if(sub[i] > sub[j])
					dp[i] = max(dp[i], dp[j] + 1);

		_max = -1;

		for(int i = 0; i < n; i++)
			if(dp[i] > _max)
				_max = dp[i];

		printf("%d\n",_max);

	}
	return 0;
}