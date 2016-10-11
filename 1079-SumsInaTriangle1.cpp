#include <cstdio>
#include <algorithm>

#define MAX 105

using namespace std;

int triangle[MAX][MAX];
int sum[MAX][MAX];

int dp(int row, int col, int n){

	if(row == n)
		return 0;

	if(sum[row][col] != -1)
		return sum[row][col];

	sum[row][col] = max( dp(row+1,col,n) + triangle[row][col], dp(row+1,col+1,n) + triangle[row][col]);

	return sum[row][col];
}


int main(){
	int cases, n;

	scanf("%d",&cases);

	while(cases--){

		scanf("%d",&n);

		for(int i = 0; i < n; i++)
			fill(sum[i],sum[i]+n,-1);

		for(int i = 0; i < n; i++)
			for(int j = 0; j <= i; j++)
				scanf("%d",&triangle[i][j]);

		printf("%d\n",dp(0,0,n));
	}

	return 0;
}
