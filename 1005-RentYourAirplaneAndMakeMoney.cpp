#include <cstdio>
#include <algorithm>

#define  maxn 10010

using namespace std;

typedef long long int lld;

typedef struct{
	lld start, end, profit;
}orders;

orders ord[maxn];
lld dp[maxn];

lld max(lld a, lld b){if(a > b) return a; return b;}

bool compare(const orders a, const orders b){
	return a.start < b.start;
}

int _lower_bound(int low, int hig, int num){
	int mid;
	while(low < hig){
		mid = (low + hig)/2;
		if(num <= ord[mid].start)
			hig = mid;
		else
			low = mid + 1;
	}
	return low;
}

int main(){
	int tc, n;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%lld %lld %lld",&ord[i].start, &ord[i].end, &ord[i].profit), ord[i].end += ord[i].start;
		sort(ord, ord + n, compare);
		dp[n] = 0;
		for(int i = n - 1; i >= 0; i--)
			dp[i] = max(dp[i + 1], dp[_lower_bound(i,n,ord[i].end)] + ord[i].profit);
		printf("%lld\n",dp[0]);
	}
	return 0;
}