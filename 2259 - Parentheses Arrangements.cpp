#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef unsigned long long int ll;
const int maxn = 1e3 + 1;

ll catalan[maxn];

void computeCatalanNumbers(){
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i < maxn; i++){
        catalan[i] = 0;
        for(int j = 0; j < i; j++)
            catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;
        catalan[i] %= MOD;
    }
}

int main(){
    ll tc, n;

    scanf("%lld",&tc);
    computeCatalanNumbers();
    for(int i = 0; i < tc; i++){
        scanf("%lld",&n);
        printf("%lld\n",catalan[n]);
    }

    return 0;
}