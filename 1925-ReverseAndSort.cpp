#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>

#define maxl 15

using namespace std;

typedef long long int lld;

lld reverse(char str[]){
	int len = strlen(str), index = 0;
	lld ans = 0;

	for(int i = 0; i < len; i++)
		ans += (str[i] - '0') * (lld)pow((double)10, (double)index++);

	return ans;
}

int main(){
	priority_queue <lld, std::vector<lld>, std::greater<lld> > numbers;
	char number[maxl];
	int n, len;

	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%s",number);
		numbers.push(reverse(number));
	}

	for(int i = 0; i < n; i++){
		printf("%lld\n",numbers.top());
		numbers.pop();
	}
	
	return 0;	
}