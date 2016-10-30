#include <iostream>
#include <string>

using namespace std;

typedef long long int lld;

lld ans;

void toBinary(lld N){
	if(N > 0){
		toBinary(N / 2);
		if(N % 2 != 0)
			ans++;
		cout << N % 2;
	}
}

int main(){
	lld N;

	while(cin >> N){
		if(N == 0)
			break;
		ans = 0;
		cout << "The parity of ";
		toBinary(N);
		cout << " is " << ans << " (mod 2).\n";
	}
	
	return 0;
}