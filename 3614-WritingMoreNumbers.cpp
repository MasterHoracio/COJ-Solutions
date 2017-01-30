#include <iostream>
#include <string>
#include <map>

using namespace std;

void compute(map<int, string> &spelling){
	spelling[0] = "zero";		spelling[1] = "one";
	spelling[2] = "two";		spelling[3] = "three";
	spelling[4] = "four";		spelling[5] = "five";
	spelling[6] = "six";		spelling[7] = "seven";
	spelling[8] = "eight";		spelling[9] = "nine";
	spelling[10] = "ten";		spelling[11] = "eleven";
	spelling[12] = "twelve";	spelling[13] = "thirteen";
	spelling[14] = "fourteen";	spelling[15] = "fifteen";
	spelling[16] = "sixteen";	spelling[17] = "seventeen";
	spelling[18] = "eighteen";	spelling[19] = "nineteen";
	spelling[20] = "twenty";	spelling[30] = "thirty";
	spelling[40] = "forty";		spelling[50] = "fifty";
	spelling[60] = "sixty";		spelling[70] = "seventy";
	spelling[80] = "eighty";	spelling[90] = "ninety";
}

int main(){
	map <int, string> spelling;
	int tc, len, n;
	string str;

	cin >> tc;
	compute(spelling);

	while(tc--){
		cin >> str;
		len = str.length();
		if(len == 1){
			cout << spelling[stoi(str)] << endl;
		}else{
			n = stoi(str);
			if(n < 20)
				cout << spelling[n] << endl;
			else if(str[1] == '0')
				cout << spelling[n] << endl;
			else
				cout << spelling[ (str[0] - '0') * 10] << "-" << spelling[str[1] - '0'] << endl;
		}
	}
	return 0;
}