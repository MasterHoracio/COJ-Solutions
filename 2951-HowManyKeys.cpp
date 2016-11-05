#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map <string, int> k;

int main(){
	int keys;
	string key;

	cin >> keys;

	while(keys--){
		cin >> key;
		sort(key.begin(),key.end());
		k[key]++;
	}

	cout << k.size() << "\n";

	k.clear();

	return 0;
}
