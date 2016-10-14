#include <cstdio>

using namespace std;

int main(){
	int TC, ans;

	scanf("%d",&TC);

	while(TC--){

		scanf("%d",&ans);

		if(ans % 2 == 0)
			while(ans % 2 == 0)
				ans /= 2;
		else
			while(ans % 2 != 0)
				ans *= 2;

		printf("%d\n",ans);
	}

	return 0;
}