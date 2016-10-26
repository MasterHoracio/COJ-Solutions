#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char encoded[5000], ascii[255];
    int TC;

    scanf("%d",&TC);

    for(int i = 1; i <= TC; i++){

        getchar();
        gets(encoded);

        for(int i = 65; i < 91; i++)
            ascii[i] = getchar();

        printf("%d ",i);
        for(int i = 0; i < strlen(encoded); i++)
            (encoded[i] == ' ') ? printf(" "): printf("%c",ascii[encoded[i]]);
        printf("\n");
    }


    return 0;
}
