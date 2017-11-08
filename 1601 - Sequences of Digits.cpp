#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int tc, digits[10], count[10], last, search;

    cin >> tc;

    for(int i = 0; i < tc; i++){
        for(int i = 0; i < 10; i++)
            cin >> count[i];
        fill(digits, digits + 10, -1);
        for(int i = 9; i >= 0; i--){
            last = search = 0;
            for(int j = 0; j < 10; j++){
                if(digits[j] != -1){
                    search++;
                    continue;
                }
                if(count[j] == search)
                    last = j;
            }
            digits[last] = i;
        }
        for(int i = 0; i < 10; i++)
            (i + 1 < 10) ? cout << digits[i] << " " : cout << digits[i] << endl;
    }

    return 0;
}