#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int tree[maxn];

void update(int indx, int limit, int number){
    while(indx <= limit){
        tree[indx] += number;
        indx += (indx & -indx);
    }
}

int sum(int indx){
    int result = 0;
    while(indx){
        result += tree[indx];
        indx -= (indx & -indx);
    }
    return result;
}

int main(){
    int tc, n, q, op, val, index, up, low, stacks[maxn];

    scanf("%d",&tc);
    for(int i = 1; i <= tc; i++){
        scanf("%d %d",&n,&q);
        memset(tree, 0, sizeof(tree));
        for(int j = 1; j <= n; j++){
            scanf("%d",&stacks[j]);
            update(j, n, stacks[j]);
        }
        printf("Case %d:\n",i);
        for(int j = 1; j <= q; j++){
            scanf("%d",&op);
            if(op == 1){
                scanf("%d",&index);
                printf("%d\n",stacks[index + 1]);
                update(index + 1, n, -stacks[index + 1]);
                stacks[index + 1] = 0;
            }else if(op == 2){
                scanf("%d %d",&index,&val);
                stacks[index + 1] += val;
                update(index + 1, n, val);
            }else{
                scanf("%d %d",&low,&up);
                printf("%d\n",sum(up + 1) - sum(low));
            }
        }
    }
    return 0;
}