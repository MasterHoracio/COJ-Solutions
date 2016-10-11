#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string decode(string line){
	int left, right;

	if(line.size() == 0)
		return "";
	else if(line.size() == 1){
		if(isalpha(line[0])){
			if(line[0] == 'a')
				line[0] = 'z';
			else if(line[0] == 'A')
				line[0] = 'Z';
			else
				line[0] -= 1;
		}
		return line;
	}

	left = (line.size() - 1) / 2;
	right = line.size() - 1 - left;

	string left_line = line.substr(1,left);
	string right_line = line.substr(left+1,right);
	string mid_line = line.substr(0,1);

	return decode(left_line) + decode(mid_line) + decode(right_line);
}

int main(){
	string line;

	while(getline(cin,line)){
		cout << decode(line) << "\n";
	}

	return 0;
}