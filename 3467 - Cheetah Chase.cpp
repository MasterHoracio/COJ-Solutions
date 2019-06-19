#include <bits/stdc++.h>

using namespace std;

float formula(int d, int c, int g){
    return sqrt((2.0*(float)d)/((float)c-(float)g));
}

int main(){
    int t, d, c, g;

    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d",&d,&c,&g);
        if(g >= c){
            printf("Case #%d: impossible\n",i+1);
        }else{
            printf("Case #%d: %.2f\n",i+1,formula(d,c,g));
        }
    }

    return 0;
}