#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    bool check;
    int station[1450], n, fuel;

    while(scanf("%d",&n)){

        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d",&station[i]);

        check = true;

        sort(station,station + n);

        for(int i = 1; i < n && check; i++)
            if( (station[i] - station[i-1]) > 200)
                check = false;

        if( (1422 - station[n-1]) > 200)
            check = false;

        if( ( (1422 - station[n-1]) * 2) > 200)
            check = false;


        (check == true) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");

    }

    return 0;
}
