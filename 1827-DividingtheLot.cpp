#include <iostream>
#include <algorithm>

#define MAX 1050

using namespace std;

typedef long long int lld;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	lld TC, pirates, items, lot[MAX], div, ans, cont;
	
	cin >> TC;
	
	while(TC--){
		cin >> pirates >> items;
		ans = cont = 0;
		for(int i = 0; i < items; i++)
			cin >> lot[i];
		sort(lot, lot + items);
		div = ( (items) / (pirates + 1));
		for(int i = items - 1; i >= 0 && cont < div; i--){
			ans += lot[i];
			cont++;
		}
		cout << ans << endl;
	}
	return 0;
}
