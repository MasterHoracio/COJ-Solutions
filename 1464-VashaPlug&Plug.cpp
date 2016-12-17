#include <iostream>
#include <string>

using namespace std;

int main(){
	string str, ans;
	int len, tc;
	bool bien;
	
	cin >> tc;
	
	while(tc--){
		cin >> str;
		ans = "";
		bien = false;
		
		while(!bien){
			bien = true;
			int len = str.length();
			for(int i = 0; i < len; i++){
				if(i + 1 < len){
					if(str[i] == str[i + 1]){
						i++;
						bien = false;
						continue;
					}
				}
				ans += str[i];
			}
			str = ans;
			ans = "";
		}
		
		cout << str << "\n";
	}
	return 0;
}
