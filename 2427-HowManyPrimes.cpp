#include <cstdio>
#include <vector>

#define MAX 1000001

using namespace std;

int main(){
	int inf, sup;
	vector <int> criba (MAX, 1);

	for(int i = 2; i * i < MAX; i++)
		if(criba[i] == 1)
			for(int j = i * i; j < MAX; j += i)
				criba[j] = 0;

	for(int i = 1; i < MAX; i++)
		criba[i] += criba[i - 1];

	while(scanf("%d %d",&inf,&sup) && (inf != 0 || sup != 0)){
		printf("%d\n",criba[sup] - criba[inf - 1]);
	}

	return 0;
}