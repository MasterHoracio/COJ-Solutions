#include <cstdio>

using namespace std;

typedef long long int lld;

lld sumatoria(lld num){ return ( (num * (num + 1)) / 2 ); }

lld binarySearch(lld num){
	lld inf = 0, sup = 50000, mid;

	while(inf <= sup){
		mid = inf + ((sup - inf) / 2);
		if(sumatoria(mid) == num)
			return mid + 1;
		else if(sumatoria(mid) < num)
			inf = mid + 1;
		else if(sumatoria(mid)  > num)
			sup = mid - 1;
	} 

	return inf;
}

int main(){
	lld num, pages;

	while(scanf("%lld",&num) && num != 0){
		pages = binarySearch(num);
		printf("%lld %lld\n",sumatoria(pages) - num, pages);
	}

	return 0;
}