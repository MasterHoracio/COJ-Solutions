#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
	int x, y;
}point;

int main(){
	int TC, cols[5], rows[5], diagonr, diagonl, num, ans;
	point temp, board[76];
	bool check;

	scanf("%d",&TC);

	while(TC--){
		temp.x = temp.y = -1;
		fill(cols,cols+5,5);
		fill(rows,rows+5,5);
		fill(board,board+76,temp);
		diagonl = diagonr = cols[2] = rows[2] = 4;
		check = true;
		ans = 0;

		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(i == 2 && j == 2)
					continue;
				scanf("%d",&num);
				temp.x = j;
				temp.y = i;
				board[num] = temp;
			}
		}

		for(int i = 0; i < 75; i++){
			scanf("%d",&num);
			if(board[num].x == -1 && board[num].y == -1){
				if(check)
					ans++;
				continue;
			}else{
				if(check){
					temp = board[num];
					cols[temp.x]--;
					rows[temp.y]--;
					ans++;
					if( (temp.x == 0 && temp.y == 0) ||  (temp.x == 1 && temp.y == 1) || (temp.x == 3 && temp.y == 3) || (temp.x == 4 && temp.y == 4) )
						diagonr--;
					if( (temp.x == 4 && temp.y == 0) ||  (temp.x == 3 && temp.y == 1) || (temp.x == 1 && temp.y == 3) || (temp.x == 0 && temp.y == 4) )
						diagonl--;
					if(diagonr == 0 || diagonl == 0 || cols[temp.x] == 0 || rows[temp.y] == 0)
						check = false;
				}
			}
		}
		printf("BINGO after %d numbers announced\n",ans);
	}

	return 0;
}