#include <cstdio>

using namespace std;

int main(){
	int a, b, c, dif1, dif2;

	while(scanf("%d %d %d",&a,&b,&c)){
		if(a == 0 && b == 0 && c == 0)
			break;
		dif1 = b - a;
		dif2 = c - b;

		(dif1 == dif2) ? printf("AP %d\n",c + dif1) : printf("GP %d\n",c * (b / a));
	}
	return 0;
}