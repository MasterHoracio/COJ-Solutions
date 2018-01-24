#include <bits/stdc++.h>

using namespace std;

bool rolandTurn(int []);
bool patrickTurn(int []);

int reactions[5][4] = {
    {2, 1, 0, 2},
    {1, 1, 1, 1},
    {0, 0, 1, 1},
    {0, 3, 0, 0},
    {1, 0, 0, 1}
};

bool posibleReaction(int index, int s_particles[]){
    bool posible = true;
    for(int i = 0; i < 4 && posible; i++)
        if(s_particles[i] < reactions[index][i])
            posible = false;
    
    return posible;
}

bool endGame(int s_particles[]){
    for(int k = 0; k < 5; k++)
        if(posibleReaction(k, s_particles))
            return false;
    return true;
}

bool rolandTurn(int s_particles[]){
    bool aux = true;
    int temp[4];
    if(endGame(s_particles)){
        return true;
    }else{
        for(int k = 0; k < 5; k++){
            if(posibleReaction(k, s_particles)){
                for(int l = 0; l < 4; l++)
                    temp[l] = s_particles[l] - reactions[k][l];
                aux = aux && patrickTurn(temp);
            }
        }
        return aux;
    }
}

bool patrickTurn(int s_particles[]){
    int temp[4];
    for(int k = 0; k < 5; k++){
        if(posibleReaction(k, s_particles)){
            for(int l = 0; l < 4; l++)
                temp[l] = s_particles[l] - reactions[k][l];
            if(rolandTurn(temp))
                return true;
        }
    }
    return false;
}

int main(){
    int tc, s_particles[4];

    scanf("%d",&tc);

    for(int i = 0; i < tc; i++){
        for(int j = 0; j < 4; j++)
            scanf("%d",&s_particles[j]);
        if(patrickTurn(s_particles))
            printf("Patrick\n");
        else
            printf("Roland\n");
    }

    return 0;
}