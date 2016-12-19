#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair <int, int> pii;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	map <int, int> sticks;
	map <int, int>::iterator it;
	vector <pii> frames;
	int n, stick, ans, div;
	bool rec;
	
	while(cin >> n){
		
		ans = 0;
		rec = false;
		
		for(int i = 0; i < n; i++){
			cin >> stick;
			sticks[stick]++;
		}
		
		for(it = sticks.begin(); it != sticks.end(); it++)
			frames.push_back(make_pair(it->first,it->second));
			
		for(int i = frames.size() - 1; i >= 0; i--){
			if(frames[i].second >= 4){
				div = frames[i].second / 4;
				ans += div;
				frames[i].second %= 4;
			}
			if(frames[i].second >= 2){
				if(!rec){
					rec = true;
				}else{
					rec = false;
					ans++;
				}
			}
		}
		
		cout << ans << endl;
		
		frames.clear();
		sticks.clear();
	}
	
	return 0;
}
