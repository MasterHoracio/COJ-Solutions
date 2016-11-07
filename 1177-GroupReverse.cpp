#include <iostream>
#include <string>

using namespace std;

int main(){
	string original, reverse;
	int G, len, leng, inc;

	while(cin >> G && G != 0){
		reverse = "";

		cin >> original;
		len = original.length();

		leng = len / G;
		inc = 0;

		for(int i = 0; i < G; i++){
			for(int j = (inc + leng) - 1; j >= inc; j--){
				reverse += original[j];
			}
			inc += leng;
		}

		cout << reverse << "\n";

	}
	return 0;
}