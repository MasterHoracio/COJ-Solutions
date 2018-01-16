#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;

bool visited[maxn][maxn];
char board[maxn][maxn];

void dfs(int i, int j, int r, int c){
    queue < pair<int, int> > sv;
    pair<int, int> temp;

    sv.push(make_pair(i, j));
    visited[i][j] = true;

    while(!sv.empty()){
        temp = sv.front();
        sv.pop();
        if(temp.first + 1 < r && board[temp.first + 1][temp.second] == '0' && !visited[temp.first + 1][temp.second]){
            sv.push(make_pair(temp.first + 1, temp.second));
            visited[temp.first + 1][temp.second] = true;
        }
        if(temp.first - 1 >= 0 && board[temp.first - 1][temp.second] == '0' && !visited[temp.first - 1][temp.second]){
            sv.push(make_pair(temp.first - 1, temp.second));
            visited[temp.first - 1][temp.second] = true;
        }
        if(temp.second + 1 < c && board[temp.first][temp.second + 1] == '0' && !visited[temp.first][temp.second + 1]){
            sv.push(make_pair(temp.first, temp.second + 1));
            visited[temp.first][temp.second + 1] = true;
        }
        if(temp.second - 1 >= 0 && board[temp.first][temp.second - 1] == '0' && !visited[temp.first][temp.second - 1]){
            sv.push(make_pair(temp.first, temp.second - 1));
            visited[temp.first][temp.second - 1] = true;
        }
    }

}

int count_sides(int i, int j, int r, int c){
    int count = 0, state = 1, curr_i = i, curr_j = j;
    bool cycle = false;

    while(!cycle){
        if(state == 1){
            if(curr_i - 1 >= 0 && board[curr_i - 1][curr_j] == '0'){
                curr_i -= 1;
                state = 4;
                count += 1;
            }else if(curr_j + 1 < c && board[curr_i][curr_j + 1] == '0'){
               curr_j += 1;
            }else{
                state = 2;
                count += 1;
            }
        }else if(state == 2){
            if(curr_j + 1 < c && board[curr_i][curr_j + 1] == '0'){
                curr_j += 1;
                state = 1;
                count += 1;
            }else if(curr_i + 1 < r && board[curr_i + 1][curr_j] == '0'){
                curr_i += 1;
            }else{
                state = 3;
                count += 1;
            }
        }else if(state == 3){
            if(curr_i + 1 < r && board[curr_i + 1][curr_j] == '0'){
                curr_i += 1;
                state = 2;
                count +=1;
            }else if(curr_j - 1 >= 0 && board[curr_i][curr_j - 1] == '0'){
                curr_j -= 1;
            }else{
                state = 4;
                count += 1;
            }
        }else if(state == 4){
            if(curr_j - 1 >= 0 && board[curr_i][curr_j - 1] == '0'){
                curr_j -= 1;
                state = 3;
                count += 1;
            }else if(curr_i - 1 >= 0 && board[curr_i - 1][curr_j] == '0'){
                curr_i -= 1;
            }else{
                state = 1;
                count += 1;
            }
        }

        if(state == 4 && curr_i == i && curr_j == j)
            cycle = true;
    }

    return count + 1;
}

int main(){
    vector < pair<int, int> > cords;
    map <int, int> count;
    int r, c;

    scanf("%d %d",&r,&c);
    getchar();

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            board[i][j] = getchar();
        }getchar();
    }

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == '0' && !visited[i][j]){
                cords.push_back(make_pair(i, j));
                dfs(i, j, r, c);
            }
        }
    }

    for(int i = 0; i < cords.size(); i++)
        count[count_sides(cords[i].first, cords[i].second, r, c)]++;

    printf("%d %d %d\n",count[4], count[6], count[8]);

    return 0;
}