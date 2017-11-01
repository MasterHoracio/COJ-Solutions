#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 1e5 + 5;
typedef pair <int, int> pii;

int* computeRightMax(int height[], int sz){
    int *right = new int[sz];
	stack <pii> svg;
	pii temp;
	
	for(int i = sz - 1; i >= 0; i--){
		while(!svg.empty() && svg.top().second <= height[i]){
			svg.pop();
		}
		if(svg.empty()){
			right[i] = 0;
		}else{
			right[i] = svg.top().first;
		}
		
		temp.first = i + 1;
		temp.second = height[i];
		svg.push(temp);
		
	}
	
	return right;
	
}

int main(){
    int n, height[maxn], *look;

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        scanf("%d",&height[i]);

    look = computeRightMax(height, n);

    for(int i = 0; i < n; i++)
        printf("%d\n",look[i]);

    return 0;
}