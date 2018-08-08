#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef struct{
    ll bajo, alto;
}rango;

rango r[50001];

ll binarySearch(ll low, ll up, ll number){
    ll mid;
    while(low <= up){
        mid = low + ((up - low) / 2);
        if(r[mid].bajo <= number && r[mid].alto >= number){
            return mid;
        }else if(r[mid].bajo > number){
            up = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    ll n, q, number;

    scanf("%lld %lld",&n,&q);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&number);
        r[i].bajo = (i == 1) ? 0 : r[i - 1].alto + 1;
        r[i].alto = (r[i].bajo + number) - 1;
    }

    for(int i = 1; i <= q; i++){
        scanf("%lld",&number);
        printf("%lld\n",binarySearch(1, n, number));
    }

    return 0;
}
