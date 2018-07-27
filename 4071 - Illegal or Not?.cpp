#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, ai, di, curr, count[1827], dp[1827];
	bool check = true;

	scanf("%d",&n);
	memset(count, 0, sizeof(count));
	for(int i = 0; i < n; i++){
		scanf("%d %d",&ai,&di);
		for(int j = ai; j <= di; j++)
			count[j] = 1;
	}
	
	dp[0] = 0;
	for(int i = 1; i < 1827; i++)
		dp[i] = count[i] + dp[i - 1];
	
	for(int i = 180; i < 1827 && check; i++){
		curr = dp[i] - dp[i - 180];
		if(curr > 90){check = false;}
	}

	(check) ? printf("Yes\n") : printf("No\n");

	return 0;
}