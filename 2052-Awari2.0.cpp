#include <iostream>

#define MAX 510

using namespace std;

bool check(int cajas[], int n){
	for(int i = 1; i <= n; i++)
		if(cajas[i] != 0)
			return false;
	return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, cajas[MAX], aux;
	bool bien, ans;
	
	while(cin >> n && n != -1){
		for(int i = 1; i <= n; i++)
			cin >> cajas[i];
			
		ans = bien = true;
			
		while(bien){
			bien = false;
			aux = 0;
			
			for(int i = 1; i <= n; i++){
				if(cajas[i] == i){
					cajas[i] = 0;
					bien = true;
					aux = i;
					break;
				}
			}
			for(int i = aux - 1; i >= 1; i--)
				cajas[i] += 1;
		}
		
		(check(cajas, n)) ? cout << "S" << endl : cout << "N" << endl;
		
	}
	return 0;
}
