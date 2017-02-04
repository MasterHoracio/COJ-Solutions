#include <cstdio>

#define MAX 100005

using namespace std;

bool triangular[MAX];

int formula(int n){ return ((n * (n + 1)) / 2);}

int main(){
	int n, j;

	for(int i = 0; formula(i - 1) <= MAX; i++){ triangular[formula(i)] = true; }


	while(scanf("%d",&n) != EOF){
		if(triangular[n]){
			printf("1\n");
		}else{
			for(j = 0; formula(j - 1) <= n; j++){
				if(triangular[n - formula(j)]){
					break;
				}
			}
			(n - formula(j) >= 0) ? printf("2\n") : printf("3\n");
		}
	}

	return 0;
}