#include <cstdio>

using namespace std;

void printSpaces(int space){
    for(int i = 0; i < space; i++)
        printf(" ");
}

void printStars(int stars){
    for(int i = 0; i < stars; i++)
        printf("*");
}

void drawTriangle(int H){
    int space, stars;
    space = H - 1;
    stars = 1;
    for(int i = 0; i < H; i++){
        printSpaces(space);
        printStars(stars);
        stars += 2;
        space--;
        printf("\n");
    }
}

void drawParallelogram(int W, int H){
    int spaces = H - 1;
    for(int i = 0; i < H; i++){
        printSpaces(spaces);
        printStars(W);
        spaces--;
        printf("\n");
    }
}

void drawRectangle(int W, int H){
    for(int i = 0; i < H; i++){
        printStars(W);
        printf("\n");
    }
}

int main()
{
    int N, H, W;

    scanf("%d",&N);

    while(N != -1){
        switch(N){

            case 1:
                scanf("%d",&H);
                drawTriangle(H);
            break;

            case 2:
                scanf("%d %d",&W,&H);
                drawParallelogram(W,H);
            break;

            case 3:
                scanf("%d %d",&W,&H);
                drawRectangle(W,H);
            break;
        }
        scanf("%d",&N);
        if(N != -1)
            printf("\n");
    }

    return 0;
}
