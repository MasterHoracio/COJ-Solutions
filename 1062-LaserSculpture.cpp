#include <cstdio>

using namespace std;

int blocks[10005];

int main(){
	int ancho, altura, ans;

	while(scanf("%d %d",&altura,&ancho) && (altura != 0 && ancho != 0) ){

		scanf("%d",&blocks[0]);
		ans = altura - blocks[0];

		for(int i = 1; i < ancho; i++){
			scanf("%d",&blocks[i]);
			if( (blocks[i - 1] - blocks[i]) > 0)
				ans += (blocks[i - 1] - blocks[i]);
		}

		printf("%d\n",ans);
		
	}

	return 0;
}