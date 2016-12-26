#include <iostream>
#include <string>
#include <map>

using namespace std;

map <int, int> factors;
map <int, int>::iterator it;

void primeFactors(int n){
	int aux = 2;
	while(aux * aux <= n){
		if(n % aux == 0){
			while(n % aux == 0){
				factors[aux]++;
				n /= aux;
			}
		}else{
			aux++;
		}
	}
	if(n > 1)
		factors[n]++;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, a, b;
	
	while(cin >> n){
		primeFactors(n);
		for(it = factors.begin(); it != factors.end(); it++){
			a = it->first;
			b = it->second;
			cout << "(" << a << "(" << b << "))";
		}
		cout << endl;
		factors.clear();
	}
	
	return 0;
}
