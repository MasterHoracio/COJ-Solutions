#include <stdio.h>
#include <string.h>

#define MAX 95
#define NEG -1

int abs(int n){	if(n < 0) return n * NEG; else return n;}

int main(){
	int n, b, i, j, numbers[MAX], ans;
	char visited[MAX];

	while(scanf("%d %d",&n,&b) && (n != 0 && b != 0)){

		memset(visited, 'n', n + 1);

		ans = 0;

		for(i = 0; i < b; i++){
			scanf("%d",&numbers[i]);
			if(visited[numbers[i]] == 'n')
				ans++;
			visited[numbers[i]] = 'y';
		}

		for(i = 0; i < b; i++){
			for(j = i + 1; j < b; j++){
				if(abs(numbers[i] - numbers[j]) >= 0 && abs(numbers[i] - numbers[j]) <= n){
					if(visited[abs(numbers[i] - numbers[j])] == 'n'){
						ans++;
						visited[abs(numbers[i] - numbers[j])] = 'y';
					}
				}
			}
		}

		(ans == n + 1) ? printf("Y\n") : printf("N\n");
	}
	return 0;
}