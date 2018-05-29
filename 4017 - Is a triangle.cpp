#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;
const lld maxn = 1e9 + 5;

lld formula(lld number){ return (number * (number + 1))/2; }

lld search(lld n){
    lld mid, up = maxn, low = 1, res;
    while(up >= low){
        mid = low + ((up - low)/ 2);
        res = formula(mid);
        if(res == n){
            return mid;
        }else if(res > n){
            up = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    lld tc, n;
    scanf("%lld",&tc);
    for(int i = 0; i < tc; i++){
        scanf("%lld",&n);
        printf("%lld\n",search(n));
    }
    return 0;
}