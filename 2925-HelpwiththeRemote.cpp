#include <cstdio>

using namespace std;

int main(){
	int tc, a, b, ans;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&a,&b);
		if(b >= a){
			printf("%d\n",b - a);
		}else{
			ans = 0;
			while(a > b){
				a /= 2;
				ans++;
			}
			printf("%d\n",ans + (b - a));
		}
	}
	return 0;
}