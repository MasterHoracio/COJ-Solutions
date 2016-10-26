#include <cstdio>
#include <cmath>

using namespace std;

int MEMO[2510];

void compute_divisors(){
    int sq, ans, i, j;

    for(i = 1; i <= 2500; i++){
        sq = sqrt(i);
        ans = 0;
        for(j = 1; j <= sq; j++){
            if(i % j == 0 && j != i/j)
                ans += 2;
            else if(i % j == 0)
                ans++;
        }
        MEMO[i] = ans;
    }
}

int main()
{
    int TC, N, pos, aux;

    compute_divisors();

    scanf("%d",&TC);

    while(TC--){
        scanf("%d",&N);
        aux = N;
        for(int i = N; i >= 1; i--){
            if(MEMO[i] >= MEMO[aux]){
                pos = i;
                aux = i;
            }
        }
        printf("%d\n",pos);
    }

    return 0;
}
