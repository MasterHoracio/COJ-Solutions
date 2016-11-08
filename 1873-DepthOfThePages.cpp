#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 110

using namespace std;

vector <int> Grafo[MAX];
bool visited[MAX];
int distancia[MAX];

void BFS(int source, int destiny){
	queue <int> cola;
	int temp;

	visited[source] = true;
	distancia[source] = 1;
	cola.push(source);

	while(!cola.empty()){

		temp = cola.front();
		cola.pop();

		for(int i = 0; i < Grafo[temp].size(); i++){

			if(!visited[Grafo[temp][i]]){
				visited[Grafo[temp][i]] = true;
				distancia[Grafo[temp][i]] = distancia[temp] + 1;
				cola.push(Grafo[temp][i]);
			}

		}

	}

}

int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);

	int TC, N, L, Q, S, D, V;

	cin >> TC;

	while(TC--){
		cin >> N >> L >> Q;

		for(int i = 0; i <= N; i++)
			Grafo[i].clear();

		fill(visited,visited + N + 1, false);
		fill(distancia,distancia + N + 1, -1);

		for(int i = 1; i <= L; i++){
			cin >> S >> D;
			Grafo[S].push_back(D);
		}

		BFS(1,N);

		for(int i = 1; i <= Q; i++){
			cin >> V;
			cout << distancia[V] << "\n";
		}

	}

	return 0;
}