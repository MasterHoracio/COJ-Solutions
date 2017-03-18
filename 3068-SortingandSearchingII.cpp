#include <cstdio>
#include <map>

#define maxn 50050

using namespace std;

int main(){
	int n, q1, q2, num, index = 1, sortedNumbers[maxn];
	map <int, int>::iterator it;
	map <int, int> numbers;

	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d",&num);
		numbers[num]++;
	}

	scanf("%d %d",&q1,&q2);

	for(int i = 0; i < q1; i++){
		scanf("%d",&num);
		(!numbers[num]) ? printf(":(\n") : printf(":)\n");
	}

	for(it = numbers.begin(); it != numbers.end(); it++)
		for(int i = 0; i < it -> second; i++)
			sortedNumbers[index++] = it -> first;

	for(int i = 0; i < q2; i++){
		scanf("%d",&num);
		printf("%d\n",sortedNumbers[num]);
	}		

	return 0;
}