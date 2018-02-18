#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
map <ll, ll> memo;
ll primes[11];

void solve(ll start, ll mult, ll limit, ll inf, ll sup){
    if(mult > sup)
        return;
    if(mult >= inf && mult <= sup)
        memo[mult] = 1;
    for(int i = start; i < limit; i++){
        if(primes[i] * mult <= sup){
            solve(i, mult * primes[i], limit, inf, sup);
        }
    }
}

int main(){
    ll n, inf, sup, len, indx;

    while(scanf("%lld",&n) && n != 0){
        for(int i = 0; i < n; i++)
            scanf("%lld",&primes[i]);
        scanf("%lld %lld",&inf,&sup);
        solve(0, 1, n, inf, sup);
        len = memo.size();
        indx = 0;
        if(len > 0){
            for(map <ll, ll>::iterator it = memo.begin(); it != memo.end(); it++){
                (indx + 1 < len) ? printf("%lld,",it->first) : printf("%lld\n",it->first);
                ++indx;
            }
        }else{
            printf("none\n");
        }
        memo.clear();
    }

    return 0;
}