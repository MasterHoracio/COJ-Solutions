#include <iostream>
#include <map>

using namespace std;

int main(){
	map <int, int> mp;
	map <int, int>::iterator  it;
	int n, num;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> num;
		mp[num]++;
		if(mp[num] == 2)
			mp.erase(num);
	}

	it = mp.begin();
	mp.clear();
	cout << it->first << "\n";

	return 0;
}