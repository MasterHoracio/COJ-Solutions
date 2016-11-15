#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	char str[15];
	int n, ans;

	scanf("%d %s",&n,str);

	ans = 0;

	for(int i = 0; i < n; i++)
		if(str[i] >= 97 && str[i] <= 122) 
			ans++;

	printf("%d %d\n",n-ans,ans);

	return 0;
}