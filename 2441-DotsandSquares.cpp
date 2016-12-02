#include <iostream>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int TC, rows, cols;

	cin >> TC;

	while(TC--){
		cin >> rows >> cols;
		( (cols + (rows - 2)) % 2 == 0) ? cout << "Second\n" : cout << "First\n";
	}
}