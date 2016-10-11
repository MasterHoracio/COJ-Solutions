#include <cstdio>

using namespace std;

int main(){
	int Gunnar, Emma, num;

	Gunnar = Emma = 0;

	for(int i = 0; i < 4; i++){
		scanf("%d",&num);
		Gunnar += num;
	}

	for(int i = 0; i < 4; i++){
		scanf("%d",&num);
		Emma += num;
	}

	(Gunnar > Emma) ? printf("Gunnar\n") : (Emma > Gunnar) ? printf("Emma\n") : printf("Tie\n");

	return 0;
}