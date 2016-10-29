#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int TC, len;
	char str[1005];

	scanf("%d",&TC);

	while(TC--){
		scanf("%s",str);
		len = strlen(str);
		if(len == 1)
			(str[len - 1] % 4 == 0) ? printf("YES\n") : printf("NO\n");
		else
			( (str[len - 1] + (str[len - 2] * 10) ) % 4 == 0) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}