#include <iostream>
#include <string>

using namespace std;

int main(){
	int len1, len2, indx;
	string str1, str2;
	bool cont;

	while(cin >> str1 >> str2){
		len1 = str1.length();
		len2 = str2.length();

		indx = 0;
		cont = true;

		for(int i = 0; i < len2 && cont; i++){
			if(str2[i] == str1[indx]){
				indx++;
				if(indx == len1)
					cont = false;
			}
		}

		(!cont) ? cout << "Yes\n" : cout << "No\n";

	}
	return 0;
}