#include <bits/stdc++.h>

using namespace std;
const int maxn = 2505;
int dp[maxn];

int solve(int n, int m){
  int memo[maxn];
  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    memo[i] = dp[i];
    for(int j = 0; j <= i; j++){
      if(memo[i] > m + dp[j] + memo[i - j]){
        memo[i] = m + dp[j] + memo[i - j];
      }
    }
  }
  return memo[n];
}

int main(){
  int n, m, cost;
  scanf("%d %d",&n,&m);
  for(int i = 1; i <= n; i++){
    scanf("%d",&cost);
    dp[i] = (i == 1) ? m + cost : cost + dp[i - 1];
  }

  printf("%d\n",solve(n, m));

  return 0;
}
