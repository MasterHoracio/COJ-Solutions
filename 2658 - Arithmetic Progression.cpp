#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
    ll tc, f, l, s, bound, times, dif, start;

    scanf("%lld",&tc);
    for(int i = 0; i < tc; i++){
        scanf("%lld %lld %lld",&f,&l,&s);
        bound = f + l;
        times = s / bound;
        if(s % bound == 0){
            times = times * 2;
        }else{
            times = (times * 2) + 1;
        }
        dif = abs(l - f)/(abs((times - 2) - 3));
        printf("%lld\n",times);
        start = f - (dif * 2);
        for(int j = 0; j < times; j++){
            (j + 1 < times) ? printf("%lld ",start) : printf("%lld\n",start);
            start += dif;
        }
    }

    return 0;
}