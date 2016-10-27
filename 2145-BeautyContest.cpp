#include <cstdio>

#define MAX 1000000
#define MIN -1000000

using namespace std;

int main(){
	int TC, score, ans, min, max;

	scanf("%d",&TC);

	for(int i = 1; i <= TC; i++){
		ans = 0;
		max = MIN;
		min = MAX;
		for(int i = 0; i < 10; i++){
			scanf("%d",&score);
			ans += score;
			if(max < score)
				max = score;
			if(min > score)
				min = score;
		}
		printf("%d %d\n",i,ans-max-min);
	}

	return 0;
}