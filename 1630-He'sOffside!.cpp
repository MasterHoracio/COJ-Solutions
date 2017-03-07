#include <stdio.h>

#define ply 12
#define TRUE 1
#define FALSE 0

int partition(int array[], int inf, int sup){
	int piv = array[sup], tmp, i, index = inf;
	
	for(i = inf; i < sup; i++){
		if(array[i] <= piv){
			tmp = array[index];
			array[index] = array[i];
			array[i] = tmp;
			index++;
		}
	}
	tmp = array[index];
	array[index] = array[sup];
	array[sup] = tmp;
	
	return index;
}

void QuickSort(int array[], int inf, int sup){
	if(inf < sup){
		int q = partition(array, inf, sup);
		QuickSort(array, inf, q - 1);
		QuickSort(array, q + 1, sup);
	}
}

int main(){
	int a, d, attackers[ply], defenders[ply], dist, cont, i;
	
	while(scanf("%d %d",&a,&d) && (a != 0 && d != 0)){
		
		for(i = 0; i < a; i++)
			scanf("%d",&attackers[i]);
			
		for(i = 0; i < d; i++)
			scanf("%d",&defenders[i]);
		
		QuickSort(defenders, 0, d - 1);
		
		dist = defenders[1];
		
		cont = TRUE;
		
		for(int i = 0; i < a && cont; i++)
			if(attackers[i] < dist)
				cont = FALSE;
		
		(cont) ? printf("N\n") : printf("Y\n");
	}
	return 0;
}
