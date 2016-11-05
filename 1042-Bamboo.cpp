#include <cstdio>

using namespace std;

int main(){
	int TC, n;
	float altura, cateto, ans, sum;

	scanf("%d",&TC);
	n = TC;
	sum = 0.0;

	while(TC--){
		scanf("%f %f",&altura,&cateto);

		ans = ( (altura * altura - cateto * cateto) / (2 * altura) );
		sum += ans;

		printf("%.1f\n",ans);
	}
	printf("%.1f",sum / n);

	return 0;
}