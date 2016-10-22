#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string food, breakfast, lunch;
	map <char, int> mapfood;
	map <char, int>::iterator it;
	int TC, lenfood, lenbreakfast, lenlunch;
	bool check;

	cin >> TC;

	while(TC--){

		cin >> food >> breakfast >> lunch;
		lenfood = food.length();	lenbreakfast = breakfast.length();	lenlunch = lunch.length();
		check = true;

		for(int i = 0; i < lenfood; i++)
				mapfood[food[i]] = 1;

		for(int i = 0; i < lenbreakfast && check; i++){
			if(!mapfood[breakfast[i]])
				check = false;
			else
				mapfood[breakfast[i]] = 0;
		}

		for(int i = 0; i < lenlunch && check; i++){
			if(!mapfood[lunch[i]])
				check = false;
			else
				mapfood[lunch[i]] = 0;
		}

		if(check == false){ 
			cout << "CHEATER\n";
		}else{
			for(it = mapfood.begin(); it != mapfood.end(); it++)
				if(it->second == 1)
					cout << it->first;
			cout << "\n";
		}

		mapfood.clear();

	}

	return 0;
}