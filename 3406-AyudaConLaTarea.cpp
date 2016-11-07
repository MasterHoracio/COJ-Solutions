#include <iostream>
#include <string>

using namespace std;

int main(){
	string n;
	int TC, len;

	cin >> TC;

	while(TC--){
		cin >> n;
		len = n.length();

		for(int i = 0; i < len; i++)
			n.push_back('0');

		cout << n << "\n";
	}
	return 0;
}
