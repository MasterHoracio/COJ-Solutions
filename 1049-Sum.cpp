#include <cstdio>

using namespace std;

int main()
{
    int n;

    scanf("%d",&n);

    (n >= 0) ? printf("%d\n",((n * (n + 1))/2)) : printf("%d\n", (((( (n * -1) * ( (n * -1) + 1))/2)) * -1) + 1 );

    return 0;
}
