#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int numbers[3], temp;
	char str[3];

	scanf("%d %d %d",&numbers[0],&numbers[1],&numbers[2]);
	getchar();
	scanf("%s",str);

	sort(numbers,numbers+3);

	for(int i = 0; i < 3; i++){
		if(str[i] == 'A')
			(i < 2) ? printf("%d ",numbers[0]) : printf("%d",numbers[0]);
		else if(str[i] == 'B')
			(i < 2) ? printf("%d ",numbers[1]) : printf("%d",numbers[1]);
		else
			(i < 2) ? printf("%d ",numbers[2]) : printf("%d",numbers[2]);
	}

	printf("\n");

	return 0;

}