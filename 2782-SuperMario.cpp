#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef struct{
	int x, y, dist;
}pos;

char board[12][12];
int visited[12][12];

int BFS(pos start, int n){
	queue <pos> camino;
	pos aux, temp;

	for(int i = 0; i < n; i++)
		fill(visited[i],visited[i] + n, -1);

	camino.push(start);
	visited[start.y][start.x] = 1;

	while(!camino.empty()){

		aux = camino.front();
		camino.pop();

		if(board[aux.y][aux.x] == '#')
			return aux.dist;
		if(aux.y + 1 < n && board[aux.y + 1][aux.x] != '*' && visited[aux.y + 1][aux.x] == -1){
			temp.y = aux.y + 1;
			temp.x = aux.x;
			temp.dist = aux.dist + 1;
			camino.push(temp);
			visited[aux.y + 1][aux.x] = 1;
		}
		if(aux.y - 1 >= 0 && board[aux.y - 1][aux.x] != '*' && visited[aux.y - 1][aux.x] == -1){
			temp.y = aux.y - 1;
			temp.x = aux.x;
			temp.dist = aux.dist + 1;
			camino.push(temp);
			visited[aux.y - 1][aux.x] = 1;
		}
		if(aux.x + 1 < n && board[aux.y][aux.x + 1] != '*' && visited[aux.y][aux.x + 1] == -1){
			temp.y = aux.y;
			temp.x = aux.x + 1;
			temp.dist = aux.dist + 1;
			camino.push(temp);
			visited[aux.y][aux.x + 1] = 1;
		}
		if(aux.x - 1 >= 0 && board[aux.y][aux.x - 1] != '*' && visited[aux.y][aux.x - 1] == -1){
			temp.y = aux.y;
			temp.x = aux.x - 1;
			temp.dist = aux.dist + 1;
			camino.push(temp);
			visited[aux.y][aux.x - 1] = 1;
		}
	}
	return -1;
}


int main(){
	pos start;
	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
			if(board[i][j] == 'm'){
				start.x = j;
				start.y = i;
				start.dist = 0;
			}
		}
	}

	cout << BFS(start, n) << "\n";

	return 0;
}