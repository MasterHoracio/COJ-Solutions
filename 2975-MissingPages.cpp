#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int N, P, izq, der;
	vector <int> missing;

	while(scanf("%d",&N)){

		if(N == 0)
			break;

		scanf("%d",&P);

		izq = 2;	der = N - 1;
		while(izq < P && der > P){
			izq += 2;
			der -= 2;
		}

		if(izq - 1 != P)missing.push_back(izq - 1);
		if(izq != P)missing.push_back(izq);
		if(der != P)missing.push_back(der);
		if(der + 1 != P)missing.push_back(der + 1);

		for(int i = 0; i < 3; i++)
			(i < 2) ? printf("%d ",missing[i]) : printf("%d",missing[i]);
		printf("\n");

		missing.clear();
	}
	return 0;
}