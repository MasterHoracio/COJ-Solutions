#include <cstdio>
#include <cstring>

#define maxn 100005

using namespace std;

int main(){
	char string[maxn], pattern[maxn];
	int n, l, pos, ans;
	
	scanf("%d",&n);
	scanf("%s",string);
	
	scanf("%d",&l);
	scanf("%s",pattern);
	
	ans = pos = 0;
	
	for(int i = 0; i < n; i++){
		if(string[i] == pattern[pos]){
			pos++;
			if(pos == l){
				ans++;
				pos = 0;
			}
		}
	}
	
	(ans != 0) ? printf("%d\n",n - (ans * l)) : printf("-1\n");
	
	return 0;
}
