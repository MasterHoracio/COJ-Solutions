#include <bits/stdc++.h>

using namespace std;

long double dp[101][601];

long double solve(int n, int m){
  if(m < 0 || n < 0){return 0;}
  if(n == 0 && m == 0){
    return 1;
  }else if(n == 0 && m != 0){
    return 0;
  }
  if(dp[n][m] != -1){return dp[n][m];}
  long double result = 0;
  for(int i = 1; i <= 6; i++){
    result += solve(n - 1, m - i)/6;
  }
  dp[n][m] = result;
  return dp[n][m];
}

int main(){
  int tc, n, m;
  cin >> tc;
  for(int i = 0; i < 101; i++)
    for(int j = 0; j < 601; j++)
      dp[i][j] = -1;
  for(int i = 0; i < tc; i++){
    cin >> n >> m;
    cout << fixed << setprecision(2) << solve(n, m) << endl;
  }
  return 0;
}
