#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
typedef long long ll;
ll dp[3][maxn];
int mods[maxn];

ll solve(string number){
    ll answ = 0, len = number.length(), curr;
    
    memset(mods, 0, sizeof(mods));
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < len; i++){
        curr = number[i] - '0';
        mods[i + 1] = (mods[i] + curr) % 3;
    }

    dp[0][0] = 1;

    for(int i = 0; i < len; i++){
        curr = mods[i + 1];
        for(int j = 0; j < 3; j++){
            dp[j][i + 1] = dp[j][i] + (j == curr);
            answ += (j == curr) ? dp[j][i + 1] - 1: 0;
        }
    }

    return answ;
}

int main(){
    vector <string> numbers;
    string cadena, aux;
    ll len, pos, cont;

    cin >> cadena;

    len = cadena.length();

    for(int i = 0; i < len; i++){
        if(cadena[i] >= '0' && cadena[i] <= '9'){
            aux += cadena[i];
        }else{
            if(aux.length() != 0)
                numbers.push_back(aux);
            aux = "";
            pos = i;
            while(pos < len && cadena[pos] >= 'a' && cadena[pos] <= 'z'){
                pos++;
            }
            i = pos - 1;
        }
    }

    if(aux.length() != 0)
        numbers.push_back(aux);

    cont = 0;

    for(int i = 0; i < numbers.size(); i++){
        cont += solve(numbers[i]);
    }

    cout << cont << endl;

    return 0;
}