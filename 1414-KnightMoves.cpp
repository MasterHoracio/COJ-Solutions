#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct{
	int x, y, costo;
} nodo;

int KnightMoveX[] = {1,  1,  -1,  -1,  2,  2,  -2,  -2};
int KnightMoveY[] = {2, -2,   2,  -2,  1, -1,   1,  -1};
int MEMO[8][8];

int BFS(int x1, int y1, int x2, int y2){
	nodo nod, curr;
	queue<nodo> q;
	nod.x = x1;	nod.y = y1; nod.costo = 0;
	MEMO[x1][y1] = 1;
	q.push(nod);

	while(!q.empty()){
		curr = q.front();	q.pop();
		if(curr.x == x2 && curr.y == y2)
			return curr.costo;
		for(int i = 0; i < 8; i++){
			nod.x = curr.x + KnightMoveX[i];
			nod.y = curr.y + KnightMoveY[i];
			nod.costo = curr.costo + 1;
			if(nod.x >= 0 && nod.y >= 0 && nod.x < 8 && nod.y < 8 && MEMO[nod.x][nod.y] == -1){
				MEMO[nod.x][nod.y] = 1;
				q.push(nod);
			}
		}
	}
}

int main(){
	string xy1, xy2;
	int x1, y1, x2, y2;

	while(cin >> xy1 >> xy2){
		if(xy1 == "##" && xy2 == "##")
			break;
		x1 = xy1[0] - 'a';
		y1 = xy1[1] - '0' - 1;
		x2 = xy2[0] - 'a';
		y2 = xy2[1] - '0' - 1;
		for(int i = 0; i < 8; i++)
			fill(MEMO[i], MEMO[i] + 8, -1);

		cout << "To get from " << xy1 <<" to " << xy2 << " takes " << BFS(x1,y1,x2,y2) << " knight moves." << "\n";
		
	}
	return 0;
}