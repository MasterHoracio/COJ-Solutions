#include <bits/stdc++.h>

using namespace std;

priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > boss;
priority_queue <int, vector<int>, greater<int> > tmp;

int solve(){
    int start, add, difone;
    pair <int, int> door;

    start = add = 0;

    while(!boss.empty()){
        door = boss.top();
        boss.pop();

        if(start >= door.first){
            start += 1;
        }else{
            if(tmp.empty()){
                add += (door.first - start);
                start += (door.first - start);
                start += 1;
            }else{
                while(!tmp.empty()){
                    if(door.first >= tmp.top()){
                        if(start >= tmp.top()){
                            start += 2;
                        }else{
                            add += (tmp.top() - start);
                            start += (tmp.top() - start);
                            start += 2;
                        }
                        tmp.pop();
                    }else{
                        break;
                    }
                }
                if(start >= door.first){
                    start += 1;
                }else{
                    add += (door.first - start);
                    start += (door.first - start);
                    start += 1;
                }
            }
        }

        if(start >= door.second){
            start += 2;
        }else{
            tmp.push(door.second);
        }

    }

    while(!tmp.empty()){
        if(start >= tmp.top()){
            start += 2;
        }else{
            add += (tmp.top() - start);
            start += (tmp.top() - start);
            start += 2;
        }
        tmp.pop();
    }
    
    return add;
}

int main(){
    pair <int, int> door;
    int tc, n;

    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> door.first >> door.second;
            boss.push(door);
        }
        cout << solve() << endl;
    }
    return 0;
}