#include <stdio.h>

#define maxn 20005

int partition(int list[], int inf, int sup){
	int piv = list[sup], temp, i, index = inf;

	for(int i = inf; i < sup; i++){
		if(list[i] >= piv){
			temp = list[index];
			list[index] = list[i];
			list[i] = temp;
			index++;
		}
	}
	temp = list[index];
	list[index] = piv;
	list[sup] = temp;

	return index;
}

void QuickSort(int list[], int inf, int sup){
	if(inf < sup){
		int q = partition(list, inf, sup);
		QuickSort(list, inf, q - 1);
		QuickSort(list, q + 1, sup);
	}
}

int main(){
	int tc, n, list[maxn], i;
	long long ans;

	scanf("%d",&tc);

	while(tc--){
		ans = 0;
		scanf("%d",&n);

		for(i = 0; i < n; i++)
			scanf("%d",&list[i]);

		QuickSort(list, 0, n - 1);

		for(i = 2; i < n; i += 3)
			ans += list[i];

		printf("%lld\n",ans);
	}

	return 0;
}