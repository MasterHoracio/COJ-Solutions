#include <cstdio>
#include <cstring>

#define MOD 1000000000
#define MAX 1002

using namespace std;

int subset[MAX], MEMO[MAX][MAX], N;

int computeWays(int index, int sumatoria){

    if(index == N && sumatoria == 0)
        return 1;
    if(index == N && sumatoria != 0)
        return 0;
    if(MEMO[index][sumatoria] != -1)
        return MEMO[index][sumatoria];

    MEMO[index][sumatoria] = (computeWays(index + 1, (sumatoria + subset[index])%3 )%MOD + computeWays(index + 1, sumatoria%3)%MOD)%MOD;

    return MEMO[index][sumatoria]%MOD;
}

int main()
{
    int ans;

    while(scanf("%d",&N) != EOF){

        for(int i = 0; i < N; i++)
            scanf("%d",&subset[i]);
            
        memset(MEMO, -1, sizeof(MEMO));

        ans = computeWays(0,0) - 1;
        printf("%d\n",ans);
    }

    return 0;
}
