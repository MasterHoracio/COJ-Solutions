#include <cstdio>
#include <map>

#define MAX_VERTEX 10050

using namespace std;

int set[MAX_VERTEX];

int find(int i){
	if(set[i] == i)
		return i;
	return find(set[i]);
}

void Union(int x, int y){
	int px = find(x);
	int py = find(y);
	if(px != py)
		set[py] = set[px];
}

int main(){
	int cases, n, m, x, y;
	map<int,int> repeat;

	scanf("%d",&cases);

	while(cases--){

		scanf("%d %d",&n,&m);

		for(int i = 1; i <= n; i++)
			set[i] = i;

		for(int i = 1; i <= m; i++){
			scanf("%d %d",&x,&y);
			Union(x,y);
		}

		for(int i = 1; i <= n; i++)
			if(!repeat[set[i]])
				repeat[set[i]] = 1;
			
		printf("%lu\n",(repeat.size() * (repeat.size() - 1)) / 2);

		repeat.clear();
		
	}

	return 0;
}