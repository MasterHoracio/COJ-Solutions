#include <bits/stdc++.h>

using namespace std;

const int max_x = (100 * 2) - 1;
const int max_y = 100;
bool visited[max_y][max_x];
char board[max_y][max_x];

int DFS(int x, int y, int n){
    queue < pair<int, int> > save;
    pair <int, int> temp;
    int count_cans = 1;
    visited[y][x] = true;
    save.push(make_pair(x, y));
    while(!save.empty()){
        temp = save.front();
        board[temp.second][temp.first] = 'X';
        save.pop();
        if(temp.first - 1 >= 0 && temp.second - 1 >= 0 && board[temp.second - 1][temp.first - 1] == '1' && !visited[temp.second - 1][temp.first - 1]){
            save.push(make_pair(temp.first - 1, temp.second - 1));
            visited[temp.second - 1][temp.first - 1] = true;
            count_cans++;
        }if(temp.first + 1 < (n * 2) - 1 && temp.second - 1 >= 0 && board[temp.second - 1][temp.first + 1] == '1' && !visited[temp.second - 1][temp.first + 1]){
            save.push(make_pair(temp.first + 1, temp.second - 1));
            visited[temp.second - 1][temp.first + 1] = true;
            count_cans++;
        }
    }
    return count_cans;
}

int main(){
    int n, c, x, y, index = 0, r_x, r_y;

    scanf("%d %d",&n,&c);
    memset(board, '0', sizeof(board));
    memset(visited, false, sizeof(visited));
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i + 1; j++)
            board[i][index + (j * 2)] = '1';
        ++index;
    }

    for(int i = 0; i < c; i++){
        scanf("%d %d",&x,&y);
        r_x = x - 1;
        r_y = (n - 1) - (y - 1);
        if(board[r_y][r_x] == '0' || visited[r_y][r_x] == true){
            printf("0\n");
        }else{
            printf("%d\n",DFS(r_x, r_y, n));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < (2 * n) - 1; j++)
            printf("%c",board[i][j]);
        printf("\n");
    }

    return 0;
}
