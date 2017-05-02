#include <cstdio>
#include <vector>

#define MAX_SIEVE 150
#define _MAX_DP 20010

using namespace std;

vector <int> sieve(){
	vector <int> memo(155, 1), primes;
	for(int i = 2; i <= MAX_SIEVE; i++){
		if(memo[i] == 1){
			primes.push_back(i);
			for(int j = i * i; j <= MAX_SIEVE; j += i)
				memo[j] = 0;
		}
	}
	return primes;
}

int _MAX_FACTOR(vector <int> primes, int number){
	int _max = -1;
	for(int i = 0; primes[i] * primes[i] <= number; i++){
		if(number % primes[i] == 0){
			_max = primes[i];
			while(number % primes[i] == 0){
				number /= primes[i];
			}
		}
	}
	if(number > 1){
		_max = number;
	}
	return _max;
}

int main(){
	int n, _max, _dp[_MAX_DP], num, _max_num;
	vector <int> primes;

	primes = sieve();
	_dp[1] = 1;
	for(int i = 2; i <= 20000; i++)
		_dp[i] = _MAX_FACTOR(primes, i);

	scanf("%d",&n);
	_max = -1;

	for(int i = 0; i < n; i++){
		scanf("%d",&num);
		if(_dp[num] > _max){
			_max = _dp[num];
			_max_num = num;
		}
	}

	printf("%d\n",_max_num);

	return 0;
}