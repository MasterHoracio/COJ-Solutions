#include <cstdio>

using namespace std;

int pieces[] = {1, 1, 2, 2, 2, 8};

int main(){
	int TC, num;

	scanf("%d",&TC);

	while(TC--){
		for(int i = 0; i < 6; i++){
			scanf("%d",&num);
			(i < 5) ? printf("%d ",pieces[i]-num) : printf("%d",pieces[i]-num);
		}printf("\n");
	}
	
	return 0;
}