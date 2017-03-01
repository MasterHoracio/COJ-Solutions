#include <cstdio>
#include <cstring>

#define max 10000000
#define maxn 1000005

using namespace std;

int set[4] {1, 3, 5, 6};
int memo[maxn][4];

int min(int a, int b){ if(a < b) return a; return b;}

int solve(int n, int p){
	if(n == 0)
		return 1;
	if(n < 0 || (p < 0 && n >= 1))
		return max;
	if(memo[n][p] != -1)
		return memo[n][p];
		
	memo[n][p] = min(solve(n, p - 1), solve(n - set[p], p) + 1);
	
	return memo[n][p];
}



int main(){
	int tc, n;
	
	memset(memo, -1, sizeof(memo));
	scanf("%d",&tc);
	
	for(int i = 1; i <= tc; i++){
		scanf("%d",&n);
		printf("Case %d: %d\n",i,solve(n, 3) - 1);
	}
	
	return 0;
}
