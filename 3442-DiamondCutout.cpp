#include <cstdio>
#include <cstring>

#define maxn 25

using namespace std;

int main(){
	int len, center = 1, div, inf, sup;
	char cadena[maxn];

	scanf("%s",cadena);

	len = strlen(cadena);

	if(len % 2 != 0){
		div = len / 2;
		for(int i = 0; i < len; i++){
			if(i <= div){//top
				if(i == 0){
					printf("%s\n",cadena);
				}else{
					inf = (len - center) / 2;
					sup = inf + (center - 1);
					for(int j = 0; j < len; j++){
						(j >= inf && j <= sup) ? printf(" ") : printf("%c",cadena[j]);
					}printf("\n");
					center += 2;
				}
			}else{//bottom
				if(i == div + 1){
					center -= 4;
				}else{
					center -= 2;
				}
				if(i == len - 1){
					printf("%s\n",cadena);
				}else{
					inf = (len - center) / 2;
					sup = inf + (center - 1);
					for(int j = 0; j < len; j++){
						(j >= inf && j <= sup) ? printf(" ") : printf("%c",cadena[j]);
					}printf("\n");
				}
			}
		}
	}else{
		printf("error\n");
	}

}