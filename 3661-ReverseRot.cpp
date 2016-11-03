#include <iostream>
#include <string>
#include <map>

using namespace std;

string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

map <char,int> computeMap(){
	map <char, int> characters;
	for(int i = 0; i < alp.length(); i++)
		characters[alp[i]] = i + 1;
	return characters;
}

int main(){
	map <char, int> alphabet;
	int rot, len, ascii;
	string str, reverse;
	char temp;

	alphabet = computeMap();

	while(cin >> rot){

		if(rot == 0)
			break;

		str = reverse = "";

		cin >> str;
		len = str.length();

		for(int i = len - 1; i >= 0; i--)
			reverse += str[i];

		for(int i = 0; i < len; i++){
			ascii = alphabet[reverse[i]];
			(ascii + rot <= 28) ? cout << alp[ (ascii + rot) - 1] : cout << alp[ ((ascii + rot) - 28) - 1];
		}

		cout << "\n";

	}
	return 0;
}
