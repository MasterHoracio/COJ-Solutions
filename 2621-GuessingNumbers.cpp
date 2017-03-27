#include <cstdio>

using namespace std;

int main(){
	int n, count = 0;
	
	scanf("%d",&n);
	
	while(n){
		n /= 2;
		count++;
	}
	
	printf("%d\n",count);
	return 0;
}
