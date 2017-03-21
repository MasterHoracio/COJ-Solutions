#include <cstdio>
#include <cstring>

#define maxn 1005

using namespace std;

int main(){
	char cadena1[maxn], cadena2[maxn];
	int tc, len1, len2, div;
	bool bien;
	
	scanf("%d",&tc);
	
	while(tc--){
		
		scanf("%s %s",cadena1, cadena2);
		
		len1 = strlen(cadena1);
		len2 = strlen(cadena2);
		
		if(len1 != len2){
			printf("NO\n");
		}else{
			bien = true;
			for(int i = 0; i < len1 && bien; i++){
				if(cadena1[i] != cadena2[i]){
					if(cadena1[len1 - i - 1] != cadena2[i] || cadena2[len1 - i - 1] != cadena1[i])
						bien = false;
				}
			}
			(bien) ? printf("YES\n") : printf("NO\n");
		}
	}
	
	return 0;
}
