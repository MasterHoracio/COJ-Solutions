#include <cstdio>
#include <cmath>
#include <queue>

#define T 1
#define F 0

using namespace std;

struct compare{
	bool operator()(const int &a, const int &b){
		return a > b;
	}
};

int SumOfDivisors(int n, priority_queue <int, vector<int>, compare> &PQ){
	int sq = sqrt(n), sum = 0;
	for(int i = 1; i <= sq; i++){
		if(n % i == 0){
			if(n / i != i){
				sum += n / i;
				if(n / i != n)
					PQ.push(n / i);
			}
			sum += i;
			PQ.push(i);
		}
	}
	return sum - n;
}

int main(){
	priority_queue <int, vector<int>, compare> PQ;
	int n, one;

	while(scanf("%d",&n) && n != -1){
		if(SumOfDivisors(n, PQ) == n){
			one = T;
			printf("%d = ",n);
			while(!PQ.empty()){
				if(one){
					printf("%d",PQ.top());
					one = F;
				}else{
					printf(" + %d",PQ.top());
				}
				PQ.pop();
			}printf("\n");
		}else{
			printf("%d is NOT perfect.\n",n);
			while(!PQ.empty())
				PQ.pop();
		}
	}
	return 0;
}