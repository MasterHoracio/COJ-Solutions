#include <cstdio>
#include <cstring>

#define maxn 7500

using namespace std;

int set[5]{1,5,10,25,50};
int memo[maxn][5];

int solve(int n, int p){
	if(n == 0)
		return 1;
	if(n < 0 || p < 0)
		return 0;
	if(memo[n][p] != -1)
		return memo[n][p];
		
	memo[n][p] = solve(n, p - 1) + solve(n - set[p], p);
	
	return memo[n][p];
}

int main(){
	//freopen("input.txt","r",stdin);
	int n;
	
	memset(memo, -1, sizeof(memo));
	
	while(scanf("%d",&n) != EOF){
		printf("%d\n",solve(n,4));
	}
	
	//fclose(stdin);
	return 0;
}
