#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int rounds, pointsA, pointsB;
	string playerA, playerB;
	map <string,string> win;

	win["rock"] = "scissors";
	win["paper"] = "rock";
	win["scissors"] = "paper";

	cin >> rounds;
	pointsA = pointsB = 0;

	for(int i = 0; i < rounds; i++){
		cin >> playerA >> playerB;
		if(playerA == playerB){
			pointsA++;
			pointsB++;
		}else{
			if(win[playerA] == playerB)
				pointsA++;
			else
				pointsB++;
		}
	}

	if(pointsA > pointsB)
		cout << "A win\n";
	else if(pointsB > pointsA)
		cout << "B win\n";
	else
		cout << "tied\n";

	return 0;
}