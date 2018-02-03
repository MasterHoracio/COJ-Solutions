#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll limit = 110005;
const ll maxs = 1e6 + 5;
vector <ll> primes;
bool isPrime[maxs];

void sieve(){
    for(ll i = 2; i < maxs; i++){
        if(isPrime[i] == false){
            primes.push_back(i);
            for(ll j = i * i; j < maxs; j += i)
                isPrime[j] = true;
        }
    }
}

void factorize(map <int, int> &mapa, int number){
    int index = 0, aux;
    while(primes[index] * primes[index] <= number){
        if(number % primes[index] == 0){
            aux = 0;
            while(number % primes[index] == 0){
                number /= primes[index];
                ++aux;
            }
            mapa[primes[index]] += aux;
        }
        ++index;
    }
    if(number > 1){
        mapa[number] += 1;
    }
}

int main(){
    ll tc, n, m, top, bot, number;
    map <int , int>::iterator it;
    map <int , int> A, B;

    sieve();
    scanf("%lld",&tc);
    for(int i = 0; i < tc; i++){
        scanf("%lld %lld",&n,&m);
        for(int j = 0; j < n; j++){
            scanf("%lld",&number);
            factorize(A, number);
        }
        for(int j = 0; j < m; j++){
            scanf("%lld",&number);
            factorize(B, number);
        }
        top = bot = 1;
        for(it = A.begin(); it != A.end(); it++){
            if(B[it->first]){
                if(it->second > B[it->first]){
                    A[it->first] -= B[it->first];
                    B[it->first] = 0;
                }else if(it->second < B[it->first]){
                    B[it->first] -= A[it->first];
                    A[it->first] = 0;
                }else{
                    A[it->first] = 0;
                    B[it->first] = 0;
                }
            }
        }
        for(it = A.begin(); it != A.end(); it++)
            top *= pow(it->first, it->second);
        for(it = B.begin(); it != B.end(); it++)
            bot *= pow(it->first, it->second);
        printf("Case #%d: %lld / %lld\n",i + 1, top, bot);
        A.clear();
        B.clear();
    }

    return 0;
}