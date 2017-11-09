#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long int ull;
vector <ull> primes, almostPrimes;
const ull limit = 1e12 + 100;
const ull maxn = 1e6 + 100;
bool isPrime[maxn];

void computeAlmosPrimes(){
    ull base;
    for(ull i = 2; i < maxn; i++){
        if(!isPrime[i]){
            primes.push_back(i);
            for(ull j = i * i; j < maxn; j += i){
                isPrime[j] = true;
            }
        }
    }

    for(ull i = 0; i < primes.size(); i++){
        base = primes[i];
        for(ull j = base * base; j < limit; j *= base)
            almostPrimes.push_back(j);
    }
}

int main(){
    ull tc, low, up, down, top;
    computeAlmosPrimes();
    sort(almostPrimes.begin(), almostPrimes.end());

    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> low >> up;
        down = lower_bound(almostPrimes.begin(), almostPrimes.end(), low) - almostPrimes.begin();
        top = upper_bound(almostPrimes.begin(), almostPrimes.end(), up) - almostPrimes.begin();
        cout << top - down << endl;
    }

    return 0;
}