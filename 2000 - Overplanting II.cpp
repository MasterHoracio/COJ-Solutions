#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll maxn = 1010;
typedef struct{
    ll x1, y1;
    ll x2, y2;
}rectangle;
rectangle rect[maxn];

int main(){
    ll n, area, sx, pos, nrec, top, bot, curr;
    vector < pair<ll, ll> > ys;
    vector <ll> xs;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
        xs.push_back(rect[i].x1);
        xs.push_back(rect[i].x2);
    }

    sort(xs.begin(), xs.end());
    area = 0;

    for(int i = 0; i < n * 2; i++){
        sx = xs[i];
        if(i != 0 && sx == xs[i - 1])
            continue;
        for(int j = 0; j < n; j++){//x in range of the rectangle
            if(rect[j].x1 <= sx && rect[j].x2 > sx){
                ys.push_back(make_pair(rect[j].y2, 1));
                ys.push_back(make_pair(rect[j].y1, -1));
            }
        }
        if(ys.size() == 0)
            continue;
        sort(ys.begin(), ys.end());
        curr = pos = 0;
        while(pos < ys.size()){
            bot = ys[pos].first;
            nrec = ys[pos].second;
            while(nrec > 0){//all rectangles that intersect
                nrec += ys[++pos].second;
            }
            top = ys[pos].first;
            curr += top - bot;
            ++pos;
        }
        
        pos = i + 1;
        while(pos < n * 2 && xs[pos] == xs[i])
            ++pos;
        area += curr * (xs[pos] - xs[i]);
        ys.clear();
        i = pos - 1;
    }

    cout << area << endl;

    return 0;
}