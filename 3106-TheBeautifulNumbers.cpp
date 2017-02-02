#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string number){
	int lo = 0, hi = number.length() - 1;
	while(lo < hi){
		if(number[lo] != number[hi])
			return false;
		lo++;
		hi--;
	}
	return true;
}

int main(){
	string numberOne, numberTwo;

	cin >> numberOne >> numberTwo;

	numberOne += numberTwo;

	(isPalindrome(numberOne)) ? cout << "Yes" << endl : cout << "No" << endl;

	return 0;
}