#include <cstdio>
#include <queue>
#define maxn 1005

using namespace std;

int abs(int a){ return a * -1;}

int main(){
	int n, m, index = 0, num, ans = 0, pos;
	priority_queue <int, vector<int>, greater<int> > earning;

	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++){
		scanf("%d",&num);
		if(num < 0){
			earning.push(num);
			index++;
		}
	}

	if(index <= m){
		while(!earning.empty()){
			ans += abs(earning.top());
			earning.pop();
		}
		printf("%d\n",ans);
	}else{
		pos = 0;
		
		while(!earning.empty()){
			ans += abs(earning.top());
			earning.pop();
			pos++;
			if(pos == m)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}