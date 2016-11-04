#include <iostream>

#define MAX 105

using namespace std;

int table[MAX][MAX];

void solve(int n){
	int temp = 1, ren, col, ans = 1, aux;

	for(int i = n - 1; i >= 0; i--){
		col = i;
		ren = 0;
		for(int j = temp; j >= 1; j--){
			table[ren][col] = ans;
			col++;
			ren++;
			ans++;
		}
		temp++;
	}

	ans = n * n;
	aux = 0;
	temp = 1;

	for(int i = n - 1; i >= 1; i--){
		ren = n - 1;
		col = aux;
		for(int j = temp; j >= 1; j--){
			table[ren][col] = ans;
			col--;
			ren--;
			ans--;
		}
		aux++;
		temp++;
	}

}

int main(){
	int n;

	cin >> n;

	solve(n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			(j + 1 < n) ? cout << table[i][j] << " " : cout << table[i][j];
		cout << "\n";
	}

	return 0;
}