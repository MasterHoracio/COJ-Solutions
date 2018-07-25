#include <bits/stdc++.h>

using namespace std;

const int max_nodos = 350;

void DFS(vector <int> grafo[], map <string, int> nodo_control, map <int, string> nombre_control, map <string, long double> &blood, int start){
	queue < pair<int, long double> > auxiliar;
	pair<int, long double> temporal;
	long double nivel = 1.0;
	auxiliar.push(make_pair(start, nivel));
	while(!auxiliar.empty()){
		temporal = auxiliar.front();
		auxiliar.pop();
		for(int i = 0; i < grafo[temporal.first].size(); i++){
			auxiliar.push(make_pair(grafo[temporal.first][i], (temporal.second * 0.5)));
			blood[nombre_control[grafo[temporal.first][i]]] += (temporal.second * 0.5);
		}
	}
}

int main(){
	string hijo, padre_uno, padre_dos, fundador, answ;
	map <int, string> nombre_control;
	map <string, long double> blood;
	map <string, int> nodo_control;
	vector <int> grafo[max_nodos];
	int n, m, n_nodo = 1;
	long double maximo;

	cin >> n >> m >> fundador;
	nombre_control[n_nodo] = fundador;
	nodo_control[fundador] = n_nodo++;
	for(int i = 0; i < n; i++){
		cin >> hijo >> padre_uno >> padre_dos;
		if(!nodo_control[hijo]){ nombre_control[n_nodo] = hijo; nodo_control[hijo] = n_nodo++;}
		if(!nodo_control[padre_uno]){ nombre_control[n_nodo] = padre_uno; nodo_control[padre_uno] = n_nodo++;}
		if(!nodo_control[padre_dos]){ nombre_control[n_nodo] = padre_dos; nodo_control[padre_dos] = n_nodo++;}
		grafo[nodo_control[padre_uno]].push_back(nodo_control[hijo]);
		grafo[nodo_control[padre_dos]].push_back(nodo_control[hijo]);
	}

	DFS(grafo, nodo_control, nombre_control, blood, 1);
	maximo = -1.0;
	for(int i = 0; i < m; i++){
		cin >> hijo;
		if(blood[hijo] > maximo){
			maximo = blood[hijo];
			answ = hijo;
		}
	}
	cout << answ << endl;

	return 0;
}