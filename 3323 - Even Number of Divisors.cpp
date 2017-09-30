#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long int a, b;
	
	while(cin >> a >> b && (a != 0 && b != 0)){
		cout << ((b - a) + 1) - ((long long int)(floor(sqrt(b)) + 1) - (long long int)ceil(sqrt(a))) << endl;
	}
	
	return 0;
}
