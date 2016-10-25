#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long lld;

int main(){
	lld ans, num1, num2;
	string N, M;

	while( cin >> N){
		ans = 0;
		while(N != "0"){
			M = N;
			sort(M.begin(), M.end());
			num1 = stoll(N);
			num2 = stoll(M);
			num1 -= num2;
			N = to_string(num1);
			ans++;
		}
		cout << ans << "\n";
	}




	return 0;
}