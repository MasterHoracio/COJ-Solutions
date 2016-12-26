#include <iostream>
#include <string>

#define M 10

using namespace std;

char cuadrado[M][M];

bool check(int i, int j, int n){
	bool bien = true;
	if(j + 1 < n)//derecha
		if(cuadrado[i][j] == cuadrado[i][j + 1])
			return false;
	if(j - 1 >= 0)//izquierda
		if(cuadrado[i][j] == cuadrado[i][j - 1])
			return false;
	if(i + 1 < n)//abajo
		if(cuadrado[i][j] == cuadrado[i + 1][j])
			return false;
	if(i - 1 >= 0)//arriba
		if(cuadrado[i][j] == cuadrado[i - 1][j])
			return false;
	return true;
}

int main(){
	string str;
	int TC, n;
	bool cont;
	
	cin >> TC;
	
	while(TC--){
		cin >> n;
		cont = true;
		
		for(int i = 0; i < n; i++){
			cin >> str;
			for(int j = 0; j < n; j++)
				cuadrado[i][j] = str[j];
		}
		
		for(int i = 0; i < n && cont; i++)
			for(int j = 0; j < n && cont; j++)
				cont = check(i, j, n);
				
		(cont) ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}
