#include <cstdio>

#define MAX 110

using namespace std;

double computeArea(int m, char board[MAX]){
	double ans = 0.0;
	bool open = false;

	for(int j = 0; j < m; j++){
		if( (board[j] == '/' && !open) ||  (board[j] == '\\' && !open) ){
			ans += 0.5;
			open = true;
		}else{
			if(board[j] == '.' && open){
				ans += 1.0;
			}else if((board[j] == '/' && open) ||  (board[j] == '\\' && open)){
				ans += 0.5;
				open = false;
			}
		}
	}

	return ans;
}

int main(){
	int n, m;
	double ans = 0.0;
	bool open = false;
	char board[MAX];

	scanf("%d %d",&n,&m);


	for(int i = 0; i < n; i++){
			scanf("%s",board);
			ans += computeArea(m, board);
	}

	printf("%d\n",(int)ans);

	return 0;
}