#include <cstdio>
#include <vector>

#define MAX 410

using namespace std;

vector <int> criba(MAX,1);

vector <int> computePrimes(){
    vector <int> primes;
    
    for(int i = 2; i * i <= 400; i++)
        if(criba[i] == 1)
            for(int j = i * i; j <= 400; j += i)  
                criba[j] = 0;
                
    for(int i = 2; i <= 400; i++)
        if(criba[i] == 1)
            primes.push_back(i);
    return primes;
}

int main()
{
    vector <int> primes;
    int TC, N, pos, ans;
    
    primes = computePrimes();
    
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%d",&N);
        ans = pos = 0;
        while(primes[pos] <= N){
           for(int i = pos; primes[i] <= N; i++)
             if(primes[pos] + primes[i] == N)
               ans++;
           pos++;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
