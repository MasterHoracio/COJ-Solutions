#include <cstdio>

#define MAX 110

using namespace std;

int A[MAX][MAX], B[MAX][MAX], RES[MAX][MAX];
int i, j, k;

void solve(int N, int M, int R, int C){
	if(M != R){
		printf("The matrices can not be multiplied\n");
	}else{
		for(i = 0; i < N; i++){
			for(j = 0; j < C; j++){
				for(k = 0; k < R; k++){
					RES[i][j] += A[i][k] * B[k][j];
				}	
				printf("%d ",RES[i][j]);
			}
			printf("\n");
		}
	}
}

int main(){
	int N, M, R, C;

	scanf("%d %d",&N,&M);

	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			scanf("%d",&A[i][j]);

	scanf("%d %d",&R,&C);

	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
			scanf("%d",&B[i][j]);

	solve(N,M,R,C);	

	return 0;
}