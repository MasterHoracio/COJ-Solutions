#include <cstdio>

#define MAX 46
#define rep(n,m) for(int i = n; i <= m; i++)

using namespace std;

typedef long long int lld;

lld male[MAX];
lld bees[MAX];

void MEMO(){
	male[0] = 0;
	bees[0] = 1;
	rep(1,MAX){
		male[i] = bees[i - 1];
		bees[i] = male[i] + male[i - 1] + 1;
	}
}

int main(){
	lld n;
	MEMO();
	while(scanf("%lld",&n) && n != -1){
		printf("%lld %lld\n",male[n],bees[n]);
	}
	return 0;
}
