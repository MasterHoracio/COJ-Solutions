#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 110

using namespace std;


int matrix[MAX][MAX];


int main()
{
    int renglones[MAX], columnas[MAX], n;
    vector <int> fr, fc;

    while(scanf("%d",&n) && n != 0){

        fill(renglones,renglones + n, 0);
        fill(columnas,columnas + n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d",&matrix[i][j]);
                if(matrix[i][j] == 1)
                    renglones[i]++;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[j][i] == 1)
                    columnas[i]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(renglones[i] % 2 == 0 && columnas[i] % 2 == 0){
                continue;
            }else{
                if(renglones[i] % 2 != 0)
                    fr.push_back(i + 1);
                if(columnas[i] % 2 != 0)
                    fc.push_back(i + 1);
            }
        }

        if(fr.empty() && fc.empty()){
            printf("OK\n");
        }else if(fr.size() == 1 && fc.size() == 1){
            printf("Change bit (%d,%d)\n",fr[0],fc[0]);
        }else{
            printf("Corrupt\n");
        }

        fr.clear();
        fc.clear();
    }
    return 0;
}
