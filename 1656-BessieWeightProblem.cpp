#include <cstdio>
#include <algorithm>

#define MAX 503

using namespace std;

int weight[MAX];
int dp[45003];
int H, N;

int compute_max(int i, int W){

	if(i > N - 1)
		return 0;

	if(weight[i] > W)
		return compute_max(i + 1, W);

	if(dp[W] != -1)
		return dp[W];

	return dp[W] = max( compute_max(i + 1, W) , compute_max(i + 1, W - weight[i]) + weight[i] );
}

int main(){
	scanf("%d %d",&H, &N);

	for(int i = 0; i < N; i++)
		scanf("%d",&weight[i]);

	fill(dp, dp + H + 1, -1);

	printf("%d\n",compute_max(0,H));

	return 0;
}