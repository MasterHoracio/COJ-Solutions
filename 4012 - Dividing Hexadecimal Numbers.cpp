#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int main(){
    int len, par, imp, cnt = 0;
    map <char, int> mp;
    char str[maxn];
    
    for(char c = '0'; c <= '9'; c++)
        mp[c] = cnt++;
    for(char c = 'A'; c <= 'F'; c++)
        mp[c] = cnt++;
    
    while(scanf("%s",str) != EOF){
        len = strlen(str);
        par = imp = 0;
        for(int i = 0; i < len; i++){
            if((i + 1) % 2 == 0)
                par += mp[str[i]];
            else
                imp += mp[str[i]];
        }
        (abs(par - imp) % 17 == 0) ? printf("yes\n") : printf("no\n");
    }

    return 0;
}