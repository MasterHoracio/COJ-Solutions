#include <cstdio>

using namespace std;

int main()
{
    int n, add, number;
    float average;

    while(scanf("%d",&n) != EOF){

        add = 0;

        for(int i = 0; i < n; i++){
            scanf("%d",&number);
            add += number;
        }
        average = (float)add / (float)n;
        printf("%.2f\n",average);
    }

    return 0;
}
