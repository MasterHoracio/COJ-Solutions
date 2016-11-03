#include <cstdio>

using namespace std;

int main(){
	int TC, A, B;

	scanf("%d",&TC);

	while(TC--){
		scanf("%d %d",&A,&B);
		printf("%.2f\n",(float)A / (float) B);
	}
	
	return 0;
}