#include <cstdio>

using namespace std;

int main(){
	int n, l, c;
	double ans = 0.0;
	
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d",&l,&c);
		if(ans < ( ((double)l * 0.7) + ((double)c * 0.3) ) )
			ans = ((double)l * 0.7) + ((double)c * 0.3);
	}
	
	printf("%.2lf",ans);
	
	return 0;
}
