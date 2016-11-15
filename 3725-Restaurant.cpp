#include <cstdio>

using namespace std;

int min(int a, int b){ if(a < b) return a; else return b; }

int max(int a, int b){ if(a > b) return a; else return b; }

int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main(){
	int l, b, mi, ma, ans, TC;
    
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%d %d",&l,&b);

        mi = min(l, b);
        ma = max(l, b);

        ans = gcd(ma, mi);

        printf("%d\n",(l * b)/(ans*ans));
    }
	
	return 0;
}
