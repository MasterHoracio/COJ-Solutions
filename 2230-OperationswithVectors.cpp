#include <iostream>
#include <algorithm>

#define rep(inicio, fin) for(int i = inicio; i < fin; i++)

using namespace std;

bool cmp(int i,int j) { return (i>j); }

int main(){
	int n, a[10], b[10], suma, sumb, ans;
	
	cin >> n;
	ans = suma = sumb = 0;
	
	rep(0,n){
		cin >> a[i];
		suma += a[i];
	}
		
	rep(0,n){
		cin >> b[i];
		sumb += b[i];
	}
		
	if(suma < sumb){
		sort(a, a+n);
		sort(b, b+n, cmp);
	}else{
		sort(a, a+n, cmp);
		sort(b, b+n);
	}
		
	rep(0,n)
		ans += a[i]*b[i];
		
	cout << ans << endl;
	
	return 0;
}
