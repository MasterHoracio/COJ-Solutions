#include <cstdio>

using namespace std;

int main(){
	int H1, M1, H2, M2;

	while(scanf("%d %d %d %d",&H1,&M1,&H2,&M2) && (H1 != 0 || M1 != 0 || H2 != 0 || M2 != 0) )
		( ((H2*60) + M2) > ((H1*60) + M1) ) ? printf("%d\n",((H2*60) + M2) - ((H1*60) + M1)) : printf("%d\n",( ((60 * 24) - ((H1*60) + M1) ) + ((H2*60) + M2)) );

	return 0;
}