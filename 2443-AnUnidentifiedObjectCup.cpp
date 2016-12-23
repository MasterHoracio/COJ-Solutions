#include <cstdio>
#include <vector>

using namespace std;

vector <int> sieve(){
	vector <int> criba(101,1);
	
	criba[0] = criba[1] = 1;
	for(int i = 2; i * i <= 100; i++){
		if(criba[i] == 1){
			for(int j = i * i; j <= 100; j += i)
				criba[j] = 0;
		}
	}
	return criba;
}

int main(){
	vector <int> criba;
	int N, K, num, ans, max, pmax, nmax;
	
	criba = sieve();
	
	scanf("%d %d",&N,&K);
	max = pmax = nmax = -1;
	for(int i = 0; i < N; i++){
		ans = 0;
		for(int j = 0; j < K; j++){
			scanf("%d",&num);
			if(criba[num] == 1)
				ans++;
		}
		if(ans > max){
			max = ans;
			pmax = i + 1;
			nmax = 1;
		}else if(ans == max){
			nmax++;
		}
	}
	(nmax == 1) ? printf("Object %d wins with %d rare characteristics\n",pmax,max) : printf("No winner\n");
	
	return 0;
}
