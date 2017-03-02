#include <cstdio>
#include <cmath>

#define PI 3.141592653589793

using namespace std;

int main(){
	double radio, angulo, perimetroi, perimetroc;
	int tc, n;
	
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%lf %d",&radio,&n);
		
		angulo = ((n - 2) * PI / n ) / 2;
		
		perimetroi = n * 2 * radio * cos(angulo);
		perimetroc = n * 2 * radio / tan(angulo);
		
		printf("%.4lf %.4lf\n",perimetroi, perimetroc);
		
	}
	return 0;
}
