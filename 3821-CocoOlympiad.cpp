#include <cstdio>

using namespace std;

int main(){
	int n, num,  min, max, max_so_far, sum;
	
	scanf("%d",&n);
	
	max_so_far = -1;
	
	for(int i = 1; i <= n; i++){
		min = 101;
		sum = max = 0;
		for(int j = 0; j < 10; j++){
			scanf("%d",&num);
			sum += num;
			if(num < min)
				min = num;
			if(num > max)
				max = num;
		}
		printf("%d %d\n",i,sum - (max + min));
		if(sum - (max + min) > max_so_far)
			max_so_far = sum - (max + min);
	}
	
	printf("%d\n",max_so_far);
	
	return 0;
}
