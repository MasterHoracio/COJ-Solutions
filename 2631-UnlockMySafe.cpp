#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solve(int permutations[], int n){
	vector <int> permutation;
	int num, div;
	do{
		num = 0;
		for(int i = 0; i < n; i++)
			num += (int)pow((double)10, (double)i) * permutations[n - i - 1];
			
		permutation.push_back(num);
		
	}while(next_permutation(permutations, permutations + n));
	
	div = permutation.size() / 3;
	if(div < 0)
		div = 0;
	return permutation[div];
}

int main(){
	int tc, n, permutations[8];
	
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			permutations[i] = i + 1;
		printf("%d\n",solve(permutations, n));
	}
	
	return 0;
}

