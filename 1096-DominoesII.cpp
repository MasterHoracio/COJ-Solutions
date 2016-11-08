#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX 10005

using namespace std;

vector <int> Grafo[MAX];
bool visited[MAX];

int DFS(int initial){
	stack <int> pila;
	int dominos = 0, current;

	if(!visited[initial])
		dominos++;
	visited[initial] = true;

	pila.push(initial);

	while(!pila.empty()){
		current = pila.top();
		pila.pop();
		for(int i = 0; i < Grafo[current].size(); i++){
			if(!visited[Grafo[current][i]]){
				visited[Grafo[current][i]] = true;
				pila.push(Grafo[current][i]);
				dominos++;
			}
		}
	}

	return dominos;
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int TC, n, m, l, x, y, z, ans;

	cin >> TC;

	while(TC--){
		cin >> n >> m >> l;

		fill(visited, visited + n + 1, false);
		for(int i = 1; i <= n; i++)
			Grafo[i].clear();

		for(int i = 0; i < m; i++){
			cin >> x >> y;
			Grafo[x].push_back(y);
		}

		ans = 0;

		for(int i = 0; i < l; i++){
			cin >> z;
			ans += DFS(z);
		}

		cout << ans << "\n";

	}
	return 0;
}