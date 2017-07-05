#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

#define LIMITS 10000005

using namespace std;

typedef long long int lld;

bool sieve[LIMITS];
vector <int> primes;

void computeSieve() {
    for (lld p = 2; p < LIMITS; p++) {
        if (!sieve[p]) {
            primes.push_back(p);
            for (lld x = p * p; x < LIMITS; x += p) {
                sieve[x] = true;
            }
        }
    }
}

bool isPalindrome(int number){
	int temp = number, reverse = 0, pot = 1, carry;
	stack <int> rev;
	while(temp){
		carry = temp % 10;
		rev.push(carry);
		temp /= 10;
	}
	while(!rev.empty()){
		reverse += rev.top() * pot;
		pot *= 10;
		rev.pop();
	}
	return number == reverse;
}

void computePalindromes(vector <int> &primes, vector <int> &palindrome){
	for(int i = 0; i < primes.size(); i++)
		if(isPalindrome(primes[i]))
			palindrome.push_back(primes[i]);
}

int main(){
	int query, lo, hi, count = 0, past = 0, upper, lower;
	vector <int> palindrome;
	
	computeSieve();
	computePalindromes(primes, palindrome);
	
	scanf("%d",&query);
	
	for(int i = 0; i < query; i++){
		scanf("%d %d",&lo,&hi);
		upper = upper_bound(palindrome.begin(), palindrome.end(), hi) - palindrome.begin();
		lower = lower_bound(palindrome.begin(), palindrome.end(), lo) - palindrome.begin();
		printf("%d\n",upper - lower);
	}
	
	return 0;
}
