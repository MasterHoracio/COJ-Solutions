#include <cstdio>
#include <cstring>

using namespace std;

bool esPar(char str[], int len){
	if(str[len - 1] % 2 == 0) 
		return true;
	else
		return false;
}

int main(){
	int TC, len, sum;
	char str[1005];

	scanf("%d",&TC);

	while(TC--){
		scanf("%s",str);

		len = strlen(str);
		sum = 0;
		
		for(int i = 0; i < len; i++)
			sum += str[i] + '0';

		(sum % 3 == 0 && esPar(str, len)) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}