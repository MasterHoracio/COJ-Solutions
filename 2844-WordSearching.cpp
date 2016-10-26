#include <iostream>
#include <string>

using namespace std;

int main(){
	string word, line;
	int pos, ans, len, lenw;

	cin >> word;

	ans = pos = 0;
	lenw = word.length();

	while(!cin.eof()){

		getline(cin,line);
		len = line.length();

		for(int i = 0; i < len; i++){
			if(word[pos] != line[i] && pos != 0)
				pos = 0;
			if(word[pos] == line[i]){
				pos++;
				if(pos == lenw){
					ans++;
					pos = 0;
				}
			}
		}
		pos = 0;
	}

	cout << ans << "\n";
	return 0;
}