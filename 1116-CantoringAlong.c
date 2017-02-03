#include <stdio.h>
#include <math.h>

#define MAX 13

void output(int n, int fractals[]){
	int i;
	if(n == 0){printf("-"); return;}
	
	output(n - 1, fractals);
	for(i = 0; i < fractals[n - 1]; i++)
		printf(" ");
	output(n - 1, fractals);
}

int main(){
	int n, i, fractals[MAX];

	for(i = 0; i < MAX; i++){fractals[i] = pow(3,i);}

	while(scanf("%d",&n) != EOF){
		output(n, fractals);
		printf("\n");
	}

	return 0;
}