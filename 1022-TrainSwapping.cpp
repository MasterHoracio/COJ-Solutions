#include <cstdio>

#define MAX 55

using namespace std;

int burbuja(int train[], int len){
	int ans = 0, temp;

	for(int i = 0; i < len; i++){
		for(int j = i + 1; j < len; j++){
			if(train[i] > train[j]){
				ans++;
				temp = train[i];
				train[i] = train[j];
				train[j] = temp;
			}
		}
	}

	return ans;
}

int main(){
	int TC, len, train[MAX];

	scanf("%d",&TC);

	while(TC--){

		scanf("%d",&len);

		for(int i = 0; i < len; i++)
			scanf("%d",&train[i]);

		printf("Optimal train swapping takes %d swaps.\n",burbuja(train,len));
	}

	return 0;
}