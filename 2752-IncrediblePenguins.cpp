#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef struct{
	string name;
	int ID;
} penguin;

int main(){
	vector <penguin> penguins;
	map<int, int> repeat;
	penguin temp;
	string name;
	int N, id;

	cin >> N;

	while(N--){
		cin >> name >> id;
		temp.name = name;
		temp.ID = abs(id);
		penguins.push_back(temp);
		repeat[abs(id)]++;
	}

	cout << "FOREVER ALONE ones:\n";

	for(int i = 0; i < penguins.size(); i++)
		if(repeat[penguins[i].ID] == 1)
			cout << penguins[i].name << "\n";

	penguins.clear();
	repeat.clear();

	return 0;
}