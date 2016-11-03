#include <cstdio>
#include <algorithm>

#define MAX 110

using namespace std;

int board[MAX][MAX], MEMO[MAX][MAX];

int computeMaximum(int renglones, int columnas){
	int ans = 0;
	
	for(int i = 0; i < columnas; i++)
		MEMO[renglones - 1][i] = board[renglones - 1][i];

	for(int i = renglones - 2; i >= 0; i--)
		for(int j = columnas - 1; j >= 0; j--)
			MEMO[i][j] = board[i][j] + max( (j - 1 >= 0) ? max(  MEMO[i + 1][j - 1] , MEMO[i + 1][j] ) : 0 , (j + 1 < columnas) ? max(  MEMO[i + 1][j + 1] ,MEMO[i + 1][j] ) : 0 );

	for(int i = 0; i < columnas; i++)
		if(MEMO[0][i] > ans)
			ans = MEMO[0][i];
	return ans;
}

int main(){
	int TC, renglones, columnas;

	scanf("%d",&TC);

	while(TC--){
		scanf("%d %d",&renglones,&columnas);

		for(int i = 0; i < renglones; i++)
			fill(MEMO[i],MEMO[i] + columnas, 0);

		for(int i = 0; i < renglones; i++)
			for(int j = 0; j < columnas; j++)
				scanf("%d",&board[i][j]);

		printf("%d\n",computeMaximum(renglones,columnas));
	}

	return 0;
}