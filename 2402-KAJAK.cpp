#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

typedef struct kaj{
	int position;
	int rank;
};

bool cmp(kaj a, kaj b){
    return a.rank < b.rank;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	map <int, int> score;
	map <int, int>::iterator it;
	kaj kajak[10];
	int rows, cols, pos;
	string column;
	
	while(cin >> rows >> cols){
		
		for(int i = 0; i < rows; i++){
			cin >> column;
			for(int j = cols - 1; j >= 0; j--){
				if(column[j] != '.' && column[j] != 'F' && column[j] != 'S'){
					kajak[column[j] - '0'].position = column[j] - '0';
					kajak[column[j] - '0'].rank = cols - j - 1;
					break;
				}
			}
		}
		
		sort(kajak+1,kajak+10,cmp);
		
		pos = 1;
		
		for(int i = 1; i < 10; i++){
			if(i + 1 < 10){
				if(kajak[i].rank == kajak[i + 1].rank){
					while(kajak[i].rank == kajak[i + 1].rank && i < 10){
						score[kajak[i].position] = pos;
						i++;
					}
					score[kajak[i].position] = pos;
					pos++;
				}else{
					score[kajak[i].position] = pos;
					pos++;
				}
			}else{
				score[kajak[i].position] = pos;
				pos++;
			}
		}
		for(it = score.begin(); it != score.end(); it++)
			cout << it->second << endl;
	}
	
	return 0;
}
