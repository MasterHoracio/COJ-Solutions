#include <cstdio>

#define MAX 1010

using namespace std;

int binariPalindrome[MAX]; 

int isPalindrome(int numero){
	int temp = numero, aux = 0;
	while(temp){
		aux = (aux << 1) + (temp & 1);
		temp >>= 1;
	}
	return numero == aux;
}

void computePalindrome(){
	int pos = 0;
	for(int i = 1; i <= 201000; i++)
		if(isPalindrome(i))
			binariPalindrome[pos++] = i;
}

int main(){
	int TC, left, inf, sup;

	computePalindrome();

	scanf("%d",&TC);

	while(TC--){
		scanf("%d %d",&inf,&sup);

		left = 0;

		while(binariPalindrome[left] < inf)
			left++;

		while(binariPalindrome[left] <= sup){
			printf("%d",binariPalindrome[left]);
			if(binariPalindrome[left + 1] <= sup)
				printf(" ");
			left++;
		}

		printf("\n");
	}

	return 0;
}