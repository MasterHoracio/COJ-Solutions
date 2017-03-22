#include <cstdio>
#include <queue>

#define maxn 1005

using namespace std;

char board[maxn][maxn];

struct Nodo{
	int x, y, cost;
	char state;
	Nodo(int _x, int _y, int _cost, char _state){
		x = _x; y = _y; cost = _cost; state = _state;
	}
	Nodo(){
		x = 0; y = 0; cost = 0; state = '.';
	}
};

int BFS(queue <Nodo> &path, int row, int col){
	int x, y, costo;
	char estado;

	while(!path.empty()){
		x = path.front().x;
		y = path.front().y;
		costo = path.front().cost;
		estado = path.front().state;

		path.pop();

		if( (estado == 'J') && (x == 0 || y == 0 || x == row - 1 || y == col - 1))
			return costo + 1;

		if( (x + 1 < row) && board[x + 1][y] == '.'){
			board[x + 1][y] = estado;
			path.push(Nodo(x + 1, y, costo + 1, estado));
		}

		if( (x - 1 >= 0) && board[x - 1][y] == '.'){
			board[x - 1][y] = estado;
			path.push(Nodo(x - 1, y, costo + 1, estado));
		}

		if( (y + 1 < col) && board[x][y + 1] == '.'){
			board[x][y + 1] = estado;
			path.push(Nodo(x, y + 1, costo + 1, estado));
		}

		if( (y - 1 >= 0) && board[x][y - 1] == '.'){
			board[x][y - 1] = estado;
			path.push(Nodo(x, y - 1, costo + 1, estado));
		}

	}

	return -1;
}

int main(){
	int tc, row, col, answ;
	queue <Nodo> path;
	struct Nodo Joe;

	scanf("%d %d",&row,&col);
	getchar();

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == 'J'){
				Joe = Nodo(i, j, 0, 'J');
				board[i][j] = '.';
			}else if(board[i][j] == 'F'){
				path.push(Nodo(i, j, 0, 'F'));
			}
		}
		getchar();
	}

	path.push(Joe);

	answ = BFS(path, row, col);

	(answ < 0) ? printf("IMPOSSIBLE\n") : printf("%d\n",answ);

	return 0;
}