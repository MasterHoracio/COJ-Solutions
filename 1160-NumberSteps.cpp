#include <cstdio>

using namespace std;

int main(){
	int TC, x, y;

	scanf("%d",&TC);

	while(TC--){

		scanf("%d %d",&x,&y);
		
		if(x == 0){
			(y == x) ? printf("0\n") : printf("No Number\n");
		}else if(x == 1){
			(y == x) ? printf("1\n") : printf("No Number\n");
		}else if(x % 2 == 0){
			if(y == x)
				printf("%d\n",2*x);
			else if(y == (x - 2))
				printf("%d\n",(2*x)-2);
			else
				printf("No Number\n");
		}else{
			if(y == x)
				printf("%d\n",(2*x)-1);
			else if(y == (x - 2))
				printf("%d\n",(2*x)-3);
			else
				printf("No Number\n");
		}
	}
	return 0;
}