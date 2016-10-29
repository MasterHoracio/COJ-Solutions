#include <cstdio>

#define MOD 100

using namespace std;

typedef long long int lld;

lld MEMO[1002], ans;

void dp(){
    for(int i = 1; i <= 1000; i++)
        MEMO[i] = i * (i + 1) * (i + 2);
}

int main()
{
    int TC, inf, sup;

    dp();

    scanf("%d",&TC);

    while(TC--){
        scanf("%d %d",&inf,&sup);
        ans = 0;
        for(int i = inf; i <= sup; i++)
            ans += MEMO[i];
        printf("%d\n",ans%MOD);
    }

    return 0;
}
