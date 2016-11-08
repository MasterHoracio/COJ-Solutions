#include <iostream>

using namespace std;

void solve(int A, int B, int C, int D, int postman){
	bool dog1, dog2;
	int temp, cont;

	cont = 1;
	temp = A;

	while(1){
		if(postman <= temp)
			break;
		(cont % 2 != 0) ? temp += B: temp += A;
		cont++;
	}

	(cont % 2 != 0) ? dog1 = true: dog1 = false;

	cont = 1;
	temp = C;

	while(1){
		if(postman <= temp)
			break;
		(cont % 2 != 0) ? temp += D: temp += C;
		cont++;
	}

	(cont % 2 != 0) ? dog2 = true: dog2 = false;


	if(dog1 && dog2)
		cout << "both" << "\n";
	else if(dog1 || dog2)
		cout << "one" << "\n";
	else
		cout << "none" << "\n";

}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A, B, C, D, P, M, G;

	cin >> A >> B >> C >> D >> P >> M >> G;

	solve(A,B,C,D,P);
	solve(A,B,C,D,M);
	solve(A,B,C,D,G);

	return 0;
}