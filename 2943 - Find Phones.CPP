#include <iostream>
#include <vector>
#include <map>

#define MAXN 505

using namespace std;

int parent[MAXN], n_node[MAXN], numbers[MAXN];

void makeSet(int pos){
    parent[pos] = pos;
    n_node[pos] = 1;
}

int find(int a){
    if(parent[a] == a)
        return parent[a];
    find(parent[a]);
}

void _union(int a, int b){
    int fa = find(a);
    int fb = find(b);

    if(fa == fb)
        return;
    
    if(n_node[fb] > n_node[fa]){
        parent[fa] = fb;
    }else if(n_node[fb] < n_node[fa]){
        parent[fb] = fa;
    }else{
        parent[fb] = fa;
        n_node[fa] += n_node[fb];
    }

}

int main(){
    map <int, vector<int> > parents;
    map <int, int> HashNumbers;
    int n, a, b, f;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
        makeSet(i);
    }

    while(cin >> a >> b){
        _union(a, b);
    }

    /*for(int i = 0; i < 4; i++){
        cin >> a >> b;
        _union(a, b);
    }*/

    for(int i = 1; i <= n; i++){
        f = find(i);
        parents[f].push_back(i);
    }

    for(map <int, vector<int> >::iterator it = parents.begin(); it != parents.end(); it++){
        vector <int> tmp = it->second;
        for(int i = 0; i < tmp.size(); i++){
            if(numbers[tmp[i]] != 0){
                HashNumbers[it->first] = numbers[tmp[i]];
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << HashNumbers[find(i)] << endl;
    

    return 0;
}