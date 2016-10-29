#include <cstdio>

using namespace std;

int gcd(int a, int b){ if(b == 0) return a; else gcd(b, a % b);}

int main()
{
    int N, ans;

    while(scanf("%d",&N) != EOF){
        ans = 0;
        for(int i = N - 1; i >= 1; i--)
            if(gcd(i,N) == 1)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
