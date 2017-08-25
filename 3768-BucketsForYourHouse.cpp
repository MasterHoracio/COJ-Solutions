#include <cstdio>

using namespace std;

const int maxn = 1e5 + 10;

int computeSolution(int n, int k, int buckets[]){
	int max, sum, indx;
	
	indx = 0;
	max = maxn;
	sum = buckets[0];
	
	if(sum == k){
		return 1;
	}
	
	for(int i = 1; i <= n; i++){
		while(sum > k && indx <= i - 1){
			sum -= buckets[indx];
			indx++;
		}
		if(sum == k){
			sum -= buckets[indx];
			if(max > (i - indx))
				max = (i - indx);
			indx++;
		}
		if(sum < k){
			sum += buckets[i];
		}
	}
	return max;
}

int main(){
	int n, k, buckets[maxn], ans;
	
	scanf("%d %d",&n,&k);
	
	for(int i = 0; i < n; i++)
		scanf("%d",&buckets[i]);
		
	ans = computeSolution(n, k, buckets);
	
	(ans != maxn) ? printf("%d\n",ans) : printf("-1\n");
	
	return 0;
}
