#include <cstdio>
#include <vector>
#include <algorithm>

#define MN 10005

using namespace std;

vector <int> Grafo[MN];
bool visited[MN];
int deuda[MN];

int DFS(int indx){

	if(visited[indx])
		return 0;

	int sum = deuda[indx];

	visited[indx] = true;

	for(int i = 0; i < Grafo[indx].size(); i++)
		sum += DFS(Grafo[indx][i]);

	return sum;
}

int main(){
	int tc, n, m, x, y, pago;
	bool bien;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&m);

		bien = true;

		for(int i = 0; i < n; i++)
			scanf("%d",&deuda[i]);

		for(int i = 0; i < m; i++){
			scanf("%d %d",&x,&y);
			Grafo[x].push_back(y);
			Grafo[y].push_back(x);
		}

		fill(visited, visited + n, false);

		for(int i = 0; i < n; i++){
			if(!visited[i]){
				pago = DFS(i);
				if(pago != 0){
					bien = false;
					break;
				}
			}
		}

		(!bien) ? printf("IMPOSSIBLE\n") : printf("POSSIBLE\n");

		for(int i = 0; i < n; i++)
			Grafo[i].clear();

	}

	return 0;
}