#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    int TC, C, ans[9];
    string coins, aux;
    map <string,int> game;

    game["TTT"] = 1;
    game["TTH"] = 2;
    game["THT"] = 3;
    game["THH"] = 4;
    game["HTT"] = 5;
    game["HTH"] = 6;
    game["HHT"] = 7;
    game["HHH"] = 8;

    cin >> TC;

    while(TC--){

        cin >> C >> coins;

        fill(ans,ans+9,0);

        for(int i = 0; i <= 40 - 3; i++){
            aux = "";
            for(int j = i; j < i + 3; j++)
                aux += coins[j];
            ans[game[aux]]++;
        }

        cout << C << " ";
        for(int i = 1; i < 9; i++)
            (i < 8) ? cout << ans[i] << " " : cout << ans[i];
        cout << "\n";

    }

    return 0;
}
