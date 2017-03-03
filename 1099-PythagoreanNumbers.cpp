#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int a, b, c;

	while(scanf("%d",&a) && a != 0){
		scanf("%d %d",&b,&c);
		if(a > b && a > c)
			(pow(a, 2) == pow(b,2) + pow(c,2)) ? printf("right\n") : printf("wrong\n");
		else if(b > a && b > c)
			(pow(b, 2) == pow(a,2) + pow(c,2)) ? printf("right\n") : printf("wrong\n");
		else if(c > a && c > b)
			(pow(c, 2) == pow(b,2) + pow(a,2)) ? printf("right\n") : printf("wrong\n");
		else
			printf("wrong\n");
	}
	return 0;
}