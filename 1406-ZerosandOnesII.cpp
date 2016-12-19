#include <iostream>
#include <string>

#define MAX 1000050

using namespace std;

int count[2][MAX];

bool check(int inf, int sup){
	if(count[0][inf] == count[0][sup] || count[1][inf] == count[1][sup])
		return true;
	return false;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string str;
	int len, queries, inf, sup, temp, tc = 1;
	
	while(cin >> str){
		
		(str[0] == '1') ? count[1][0] = 1 : count[1][0] = 0;
		(str[0] == '0') ? count[0][0] = 1 : count[0][0] = 0;
		
		len = str.length();
		
		for(int i = 1; i < len; i++){
			if(str[i] == '1'){
				count[1][i] = count[1][i - 1] + 1;
				count[0][i] = count[0][i - 1];
			}else{
				count[1][i] = count[1][i - 1];
				count[0][i] = count[0][i - 1] + 1;
			}
		}
			
		cin >> queries;
		
		cout << "Case " << tc++ << ":\n";
		
		for(int i = 1; i <= queries; i++){
			cin >> inf >> sup;
			if(inf > sup){
				temp = inf;
				inf = sup;
				sup = temp;
			}
			(check(inf,sup)) ? cout << "Yes\n" : cout << "No\n";
		}
	}
	return 0;
}
