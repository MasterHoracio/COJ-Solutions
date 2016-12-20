#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	vector <int> spaces;
	vector <int> ans;
	map <int, int> disct;
	map <int, int>::iterator it;
	int w, p, space, sz;
	
	cin >> w >> p;
	
	spaces.push_back(0);
	for(int i = 0; i < p; i++){
		cin >> space;
		spaces.push_back(space);
	}
	spaces.push_back(w);
	
	sz = spaces.size();
	
	for(int i = 0; i < sz - 1; i++){
		for(int j = i + 1; j < sz; j++){
			disct[spaces[j] - spaces[i]]++;
		}
	}
	
	for(it = disct.begin(); it != disct.end(); it++)
		ans.push_back(it->first);
		
	sz = ans.size();
	
	for(int i = 0; i < sz; i++)
		(i + 1 < sz) ? cout << ans[i] << " " : cout << ans[i] << endl;
	
	return 0;
}
