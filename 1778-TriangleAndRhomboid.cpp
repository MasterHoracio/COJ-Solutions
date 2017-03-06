#include <cstdio>

using namespace std;

int main(){
	double a, b;
	int tc;

	scanf("%d",&tc);

	while(tc--){
		scanf("%lf %lf",&a,&b);
		printf("%.8lf\n", ( ((b / 2) * (a / 4)) / 2 ) + ( (a / 2) * (b / 4) ) );
	}
}