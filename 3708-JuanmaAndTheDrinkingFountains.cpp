#include <cstdio>

#define maxniv1 201
#define maxniv2 202
#define maxniv3 203
#define maxniv4 204

using namespace std;

typedef long long int lld;

lld niv1[maxniv1]{0,1,2,3};
lld niv2[maxniv2]{0,1,2,3,7};
lld niv3[maxniv3]{0,1,2,4,8,15};
lld niv4[maxniv4]{0,1,2,4,8,16,31};

void solve(){
	for(int i = 4; i < maxniv1; i++){
		niv1[i] = i;
		niv2[i + 1] = niv2[i] + niv1[i];
		niv3[i + 2] = niv3[i + 1] + niv2[i + 1];
		niv4[i + 3] = niv4[i + 2] + niv3[i + 2];
	}
}



int main(){
	lld tc, n;
	solve();
	
	scanf("%lld",&tc);
	
	while(tc--){
		scanf("%lld",&n);
		printf("%lld\n",niv4[n]);
	}
	return 0;
}
