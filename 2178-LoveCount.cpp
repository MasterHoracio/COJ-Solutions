#include <cstdio>

#define maxn 55

using namespace std;

int partition(int impares[], int inf, int sup){
	int piv = impares[sup], index = 0, temp;

	for(int i = 0; i < sup; i++){
		if(impares[i] >= piv){
			temp = impares[index];
			impares[index] = impares[i];
			impares[i] = temp;
			index++;
		}
	}

	temp = impares[index];
	impares[index] = impares[sup];
	impares[sup] = temp;

	return index;
}

void QuickSort(int impares[], int inf, int sup){
	if(inf < sup){
		int q = partition(impares, inf, sup);
		QuickSort(impares, inf, q - 1);
		QuickSort(impares, q + 1, sup);
	}
}

int main(){
	int n, par, impar, num, impares[maxn], sum;

	scanf("%d",&n);

	sum = par = impar = 0;

	for(int i = 0; i < n; i++){
		scanf("%d",&num);
		if(num % 2 == 0)
			par += num;
		else
			impares[impar++] = num;
	}

	if(impar == 0){
		printf("-1\n");
	}else{
		QuickSort(impares, 0, impar - 1);

		if(impar <= 2){
			sum = impares[0];
		}else{
			sum = impares[0];
			for(int i = 1; i < impar; i += 2){
				if(i + 1 < impar)
					sum += impares[i] + impares[i + 1];
				else
					break;
			}
		}
		printf("%d\n",sum + par);
	}

	return 0;
}