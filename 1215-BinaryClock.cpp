#include <iostream>
#include <string>

using namespace std;

int pot[] = {1,2,4,8,16,32};

int toDecimal(string temp){
	int len, ans = 0;
	
	len = temp.length();
	
	for(int i = len - 1, j = 0; i >= 0; i--, j++)
		if(temp[i] == '1')
			ans += pot[j];
			
	return ans;
}

void convertClock(string bin){
	string temp = "";
	int len;
	
	len = bin.length();
	
	for(int i = 0; i < len; i++){
		temp += bin[i];
		if(i == 1){
			cout << toDecimal(temp);
			temp = "";
		}else if(i == 5){
			cout << toDecimal(temp) << ":";
			temp = "";
		}else if(i == 8){
			cout << toDecimal(temp);
			temp = "";
		}else if(i == 12){
			cout << toDecimal(temp) << ":";
			temp = "";
		}else if(i == 15){
			cout << toDecimal(temp);
			temp = "";
		}else if(i == 19){
			cout << toDecimal(temp) << "\n";
			temp = "";
		}
	}
}

int main(){
	string str, bin;
	int tc, len;
	bool asc;
	
	cin >> tc;
	
	for(int i = 1; i <= tc; i++){
		cin >> str;
		
		bin = "";
		
		len = str.length();
		
		for(int j = 0; j < len; j++)
			if(str[j] == ')')
				(str[j - 1] == '(') ? bin += '0' : bin += '1';
		
		cout << "Case " << i << ": ";
		convertClock(bin);
	}
	return 0;
}
