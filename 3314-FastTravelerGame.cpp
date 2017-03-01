#include <cstdio>
#include <vector>

#define maxb 105

using namespace std;

int main(){
	int tc, p, b, d, board[maxb], dice, player, pos;
	vector <int> winners, players;
	bool cont;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d %d",&p,&b,&d);

		for(int i = 0; i <= p; i++)
			players.push_back(0);

		for(int i = 0; i < b; i++)
			scanf("%d",&board[i]);

		player = 1;
		cont = true;

		for(int i = 0; i < d; i++){
			scanf("%d",&dice);
			if(cont){
				if(player > p)
					player = 1;
				if(players[player] != (b - 1)){//si aun no llega
					players[player] += dice;
					pos = players[player];
					players[player] += board[pos];
					if(players[player] == (b - 1))
						winners.push_back(player);
				}else{
					cont = false;
					for(int j = player; j <= p; j++){
						if(players[j] != (b - 1)){
							cont = true;
							player = j;
							break;
						}
					}
					for(int j = 1; j <= player && !cont; j++){
						if(players[j] != (b - 1)){
							cont = true;
							player = j;
							break;
						}
					}
					if(cont){
						players[player] += dice;
						pos = players[player];
						players[player] += board[pos];
						if(players[player] == (b - 1))
							winners.push_back(player);
					}
				}
				player++;
			}
		}

		if(winners.empty()){
			printf("-1\n");
		}else{
			for(int i = 0; i < winners.size(); i++)
				(i + 1 < winners.size()) ? printf("%d ",winners[i]) : printf("%d\n",winners[i]);
		}

		winners.clear();
		players.clear();
	}
	return 0;
}