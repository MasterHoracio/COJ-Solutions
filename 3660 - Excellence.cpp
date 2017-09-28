#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;

int main(){
	int n, arr[maxn], mini;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	mini = arr[n / 2] + arr[(n / 2) - 1]; 
	
	for(int i = 0; i < (n / 2); i++){
		mini = min(mini, arr[i] + arr[n - i - 1]);
	}
	
	cout << mini << endl;
	
	return 0;
}
