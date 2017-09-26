#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;
const lld inf = 1e9;
const int bad = -1; 
lld a;

bool computeLeft(lld b, lld x){
	lld pot = 1, temp = b - 1;
	if(temp < 1){
		return false;
	}else{
		for(int i = 0; i < x && temp >= 1; i++){
			temp -= pot;
			pot *= 2;
		}
	}
	if(temp >= 1){
		a = temp;
		return true;
	}else{
		return false;
	}
}

bool computeRight(lld b, lld x){
	lld pot = 1, temp = b + 1;
	if(temp < 1){
		return false;
	}else{
		for(int i = 0; i < x && temp <= inf; i++){
			temp += pot;
			pot *= 2;
		}
	}
	if(temp <= inf){
		a = temp;
		return true;
	}else{
		return false;
	}
}

int main(){
	lld tc, b, x;
	
	cin >> tc;
	
	while(tc--){
		cin >> b >> x;
		if(x == 0){
			if(b > 1){
				cout << b - 1 << endl;
			}else{
				cout << b + 1 << endl;
			}
		}else{
			if(computeLeft(b, x)){
				cout << a << endl;
			}else if(computeRight(b , x)){
				cout << a << endl;
			}else{
				cout << bad << endl;
			}
		}
	}
	
	return 0;
}
