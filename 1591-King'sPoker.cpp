#include <cstdio>

using namespace std;

int main(){
	int A, B, C, comun, ncomun;

	while(scanf("%d %d %d",&A,&B,&C)){
		if(A == 0 && B  == 0 && C == 0)
			break;
		if(A == B && A == C){
			comun = A;
			(comun == 13) ? printf("*\n") : printf("%d %d %d\n",comun + 1,comun + 1,comun + 1);
		}else if(A ==  B || B == C || A == C){
			if(A == B) { comun = A; ncomun = C;}
			else if(A == C) {comun = A; ncomun = B;}
			else if(B == C) {comun = B; ncomun = A;}
			if(ncomun == 13){
				ncomun = 1;
				printf("%d %d %d\n",ncomun,comun + 1,comun + 1);
			}else if(ncomun + 1 == comun){
				if(comun == 13){
					printf("1 1 1\n");
				}else{
					ncomun += 2;
					printf("%d %d %d\n",comun,comun,ncomun);
				}
			}else{
				(ncomun + 1 > comun) ? printf("%d %d %d\n",comun,comun,ncomun + 1) : printf("%d %d %d\n",ncomun + 1,comun,comun);
			}
			
		}else{
			printf("1 1 2\n");
		}

	}
	return 0;
}