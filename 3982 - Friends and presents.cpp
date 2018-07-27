#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

bool eval(lld number, lld c1, lld c2, lld x, lld y){
	lld divc1, divc2, aux, common, pc1, pc2;

	divc1 = number / x;
	divc2 = number / y;
	aux = number / (x * y);

	common = number - ((divc1 + divc2) - aux);

	pc1 = (number - (number / x)) - common;
	pc2 = (number - (number / y)) - common;

	pc1 -= c1;
	if(pc1 < 0){common -= (pc1 * -1);}
	pc2 -= c2;
	if(pc2 < 0){common -= (pc2 * -1);}

	return (common >= 0);
}

int main(){
	lld c1, c2, x, y, l = 1, r = 1e18, mid;

	scanf("%lld %lld %lld %lld",&c1, &c2, &x, &y);
	while(l < r){
		mid = l + ((r - l)/2);
		if(eval(mid, c1, c2, x, y)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	printf("%lld\n",r);

	return 0;
}