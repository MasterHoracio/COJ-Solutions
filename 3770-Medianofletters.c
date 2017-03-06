#include <stdio.h>
#include <string.h>

#define maxn 1005

int partition(char A[], int inf, int sup){
	char piv = A[sup], temp;
	int index = inf, i;
	for(i = inf; i < sup; i++){
		if(A[i] <= piv){
			temp = A[index];
			A[index] = A[i];
			A[i] = temp;
			index++;
		}
	}
	temp = A[sup];
	A[sup] = A[index];
	A[index] = temp;

	return index;
}

void QuickSort(char A[], int inf, int sup){
	int q;
	if(inf < sup){
		q = partition(A, inf, sup);
		QuickSort(A, inf, q - 1);
		QuickSort(A, q + 1, sup);
	}
}

int main(){
	char string[maxn];
	int n;

	scanf("%d",&n);
	scanf("%s",string);

	QuickSort(string, 0, n - 1);

	printf("%c\n",string[(n / 2)]);

	return 0;
}