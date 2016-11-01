#include <cstdio>
#include <cmath>

using namespace std;

int sumDivisors(int N){
	int sq = sqrt(N), ans = 0;
	for(int i = 1; i <= sq; i++){
		if(N % i == 0 && i != N/i)
			ans += i + N/i;
		else if(N % i == 0)
			ans += i;
	}
	return ans - N;
}

int main(){
	int TC, N;

	scanf("%d",&TC);

	while(TC--){
		scanf("%d",&N);
		printf("%d\n",sumDivisors(N));
	}

	return 0;
}