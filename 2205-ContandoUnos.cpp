#include <cstdio>

#define MAX 1005

using namespace std;

int memo[MAX];

void dp(){
	int ones, temp;
	memo[1] = 1;
	for(int i = 2; i <= 1000; i++){
		temp = i;
		ones = 0;
		while(temp){
			if(temp & 1)
				ones++;
			temp >>=1;
		}
		memo[i] = memo[i - 1] + ones;
	}
}

int main(){
	int TC, inf, sup; dp();

	scanf("%d",&TC);

	while(TC--){
		scanf("%d %d",&inf,&sup);
		(inf == 1) ? printf("%d\n",memo[sup]) : printf("%d\n",memo[sup] - memo[inf - 1]);
	}
	return 0;
}