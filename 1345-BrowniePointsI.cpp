#include <cstdio>

#define maxn 200000

using namespace std;

typedef struct{
	int x, y;
}Point;

int main(){
	int n, cx, cy,stan, ollie;
	Point pnt[maxn];
	
	while(scanf("%d",&n) && n != 0){
		
		for(int i = 0; i < n; i++){
			scanf("%d %d",&pnt[i].x,&pnt[i].y);
			if(i == n / 2){
				cx = pnt[i].x;
				cy = pnt[i].y;
			}
		}
		
		stan = ollie = 0;
		
		for(int i = 0; i < n; i++){
			if(pnt[i].x > cx){//si esta a la derecha
				if(pnt[i].y > cy)//si esta arriba
					stan++;
				else if(pnt[i].y < cy)//esta abajo
					ollie++;
			}else if(pnt[i].x < cx){//esta a la izquierda
					if(pnt[i].y > cy)//si esta arriba
						ollie++;
					else if(pnt[i].y < cy)//esta abajo
						stan++;
			}
		}
		
		printf("%d %d\n",stan,ollie);
	}
	return 0;
}
