#include <cstdio>
#include <map>

using namespace std;

int main(){
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	map <int, int> x;
	map <int, int> y;
	map <int, int>::iterator it;

	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

	x[x1]++;	x[x2]++;	x[x3]++;
	y[y1]++;	y[y2]++;	y[y3]++;

	for(it = x.begin(); it != x.end(); it++)
		if(it->second == 1)
			x4 = it->first;

	for(it = y.begin(); it != y.end(); it++)
		if(it->second == 1)
			y4 = it->first;

	printf("%d %d\n",x4,y4);

	x.clear();	y.clear();

	return 0;
}