#include <cstdio>

using namespace std;

int main(){
	double number;
	int tc, n;
	
	scanf("%d",&tc);
	
	while(tc--){
		number = 0.0;
		for(int i = 0; i < 10; i++){
			scanf("%d",&n);
			number += (double)n * 0.85;
		}
		printf("%.3lf\n",number);
	}
	
	return 0;
}
