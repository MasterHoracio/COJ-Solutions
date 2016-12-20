#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lld;

lld cubes[500];

void memo(){
	for(int i = 0; i < 500; i++)
		cubes[i] = pow(i + 1,3);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	lld n, idx, ans;
	
	memo();
	
	while(cin >> n && n != 0){
		ans = idx = 0;
		while(n >= cubes[idx]){
			if( n % cubes[idx] == 0)
				ans++;
			idx++;
		}
		cout << ans << endl;
	}
	
	return 0;
}
