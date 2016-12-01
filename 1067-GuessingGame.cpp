#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector <int> mayores;
	vector <int> menores;
	string part1, part2;
	int n;
	bool bien = true;
	
	while(cin >> n && n != 0){
		cin >> part1 >> part2;
		if(part1 == "too"){
			if(part2 == "high"){
				if(find(mayores.begin(), mayores.end(), n) == mayores.end()){
					mayores.push_back(n);
				}else{
					if(find(menores.begin(), menores.end(), n) != menores.end())
						bien = false;
				}		
			}else{
				if(find(menores.begin(), menores.end(), n) == menores.end()){
					menores.push_back(n);
				}else{
					if(find(mayores.begin(), mayores.end(), n) != mayores.end())
						bien = false;
				}	
			}
		}else{
			if( (find(mayores.begin(), mayores.end(), n) != mayores.end()) || (find(menores.begin(), menores.end(), n) != menores.end()) )
				bien = false;
			for(int i = 0; i < mayores.size(); i++)
				if(mayores[i] <= n)
					bien = false;
			for(int i = 0; i < menores.size(); i++)
				if(menores[i] >= n)
					bien = false;
			
			(bien) ? cout << "Stan may be honest\n" : cout << "Stan is dishonest\n";
			bien = true;
			mayores.clear();
			menores.clear();
		}
	}
	return 0;
	
}
