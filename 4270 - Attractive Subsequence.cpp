 #include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld count_sequences(lld n, int seq[], lld lef, lld rig){
    lld zeros_lef = 0, zeros_rig = 0, auxiliar;
    auxiliar = lef - 1;
    while(auxiliar >= 0 && seq[auxiliar] == 0){
        zeros_lef += 1;
        auxiliar -= 1;
    }
    auxiliar = rig + 1;
    while(auxiliar < n && seq[auxiliar] == 0){
        zeros_rig += 1;
        auxiliar += 1;
    }
    return (zeros_lef + zeros_rig + 1) + (zeros_lef * zeros_rig);
}

lld solve_sequences(lld n, lld k, int seq[], int seq_aux[], int map_index[], lld n_aux){
    lld count = 0, lef = 0, rig, acum = 0;
    for(int i = 0; i < n_aux; i++){
        rig = i;
        acum += seq_aux[i];
        if(acum == k){
            count += count_sequences(n, seq, map_index[lef], map_index[rig]);
        }else if(acum > k){
            for(int j = lef; j <= rig && acum > k; j++){
                acum -= seq_aux[j];
                if(acum <= k){
                    lef = (j + 1 < n_aux) ? j + 1: j;
                    if(acum == k){
                        count += count_sequences(n, seq, map_index[lef], map_index[rig]);
                    }
                }
            }
        }
    }
    return count;
}

int main(){
    int seq[100001], seq_aux[100001], map_index[100001], query[1001];
    lld tc, n, q, n_aux, ans;

    scanf("%lld",&tc);
    for(int i = 0; i < tc; i++){
        scanf("%lld %lld",&n,&q);
        n_aux = 0;
        for(int j = 0; j < n; j++){
            scanf("%d",&seq[j]);
            if(seq[j] != 0){
                seq_aux[n_aux] = seq[j];
                map_index[n_aux] = j;
                n_aux += 1;
            }
        }
        for(int j = 0; j < q; j++)
            scanf("%lld",&query[j]);
        for(int j = 0; j < q; j++){
            ans = solve_sequences(n, query[j], seq, seq_aux, map_index, n_aux);
            (j + 1 == q) ? printf("%lld\n",ans) : printf("%lld ",ans);
        }
    }

    return 0;
}
