#include <iostream>
#include <algorithm>
#include <string>

#define fastIO "cin.tie(0); ios_base::sync_with_stdio(false)"

using namespace std;

typedef long long int lld;

int main(){
	fastIO;
	string number;
	lld len, indx, ans, curr;

	while(cin >> number && number != "0"){
		len = number.length();
		sort(number.begin(), number.end());

		ans = indx = 0;
		while(number[indx] == '0')
			indx++;

		swap(number[0], number[indx]);

		do{
			if(number[0] != '0'){
				curr = 0;
				for(int i = 0; i < len; i++)
					curr = (curr * 10) + number[i] - '0';
				ans += curr;
			}
		}while(next_permutation(number.begin(), number.end()));

		cout << ans << endl;
	}

	return 0;
}