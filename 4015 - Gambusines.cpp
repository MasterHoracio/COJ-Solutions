#include <bits/stdc++.h>

using namespace std;

bool visited[101][101];
vector <int> answer;

void DFS(int matrix[101][101], int i, int j, int r, int c, int t){
    queue < pair <int, int> > aux;
    pair <int, int> tmp;
    int counter = 0;
    aux.push(make_pair(i, j));
    visited[i][j] = true;
    while(!aux.empty()){
        tmp = aux.front();
        ++counter;
        aux.pop();
        if(tmp.first + 1 < r && !visited[tmp.first + 1][tmp.second] && matrix[tmp.first + 1][tmp.second] == 1){
            aux.push(make_pair(tmp.first + 1, tmp.second));
            visited[tmp.first + 1][tmp.second] = true;
        }
        if(tmp.first - 1 >= 0 && !visited[tmp.first - 1][tmp.second] && matrix[tmp.first - 1][tmp.second] == 1){
            aux.push(make_pair(tmp.first - 1, tmp.second));
            visited[tmp.first - 1][tmp.second] = true;
        }
        if(tmp.second + 1 < c && !visited[tmp.first][tmp.second + 1] && matrix[tmp.first][tmp.second + 1] == 1){
            aux.push(make_pair(tmp.first, tmp.second + 1));
            visited[tmp.first][tmp.second + 1] = true;
        }
        if(tmp.second - 1 >= 0 && !visited[tmp.first][tmp.second - 1] && matrix[tmp.first][tmp.second - 1] == 1){
            aux.push(make_pair(tmp.first, tmp.second - 1));
            visited[tmp.first][tmp.second - 1] = true;
        }
    }
    if(counter >= t)
        answer.push_back(counter);
}

int main(){
    int t, g, r, c, matrix[101][101], n, benefit = 0;

    scanf("%d %d %d %d",&t,&g,&r,&c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d",&matrix[i][j]);
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(matrix[i][j] == 1 && !visited[i][j]){
                DFS(matrix, i, j, r, c, t);
            }
        }
    }

    n = answer.size();
    for(int i = 0; i < answer.size(); i++)
        benefit += (answer[i] - t) * g;

    printf("%d %d\n",n,benefit);

    return 0;
}