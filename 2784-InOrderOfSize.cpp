#include <cstdio>

#define MAX 10005

using namespace std;

int partition(int gladiators[], int inf, int sup){
	int x, temp, i;

	x = gladiators[sup];
	i = inf - 1;

	for(int j = inf; j < sup; j++){
		if(gladiators[j] <= x){
			i += 1;
			temp = gladiators[i];
			gladiators[i] = gladiators[j];
			gladiators[j] = temp;
		}
	}
	temp = gladiators[i + 1];
	gladiators[i + 1] = gladiators[sup];
	gladiators[sup] = temp;

	return i + 1;
}

void QuickSort(int gladiators[], int inf, int sup){
	if(inf < sup){
		int q = partition(gladiators, inf, sup);
		QuickSort(gladiators,inf,q - 1);
		QuickSort(gladiators,q + 1, sup);
	}
}

int main(){
	int n, gladiators[MAX];

	while(scanf("%d",&n) != EOF){

		for(int i = 0; i < n; i++)
			scanf("%d",&gladiators[i]);

		QuickSort(gladiators,0,n-1);

		(n == 1) ? printf("%d",gladiators[n - 1]) : printf("%d ",gladiators[n - 1]);
		for(int i = 0; i < n - 1; i++)
			(i < n - 2) ? printf("%d ",gladiators[i]) : printf("%d",gladiators[i]);
		printf("\n");
	}
	return 0;
}