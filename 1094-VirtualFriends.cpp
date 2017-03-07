#include <iostream>
#include <string>
#include <vector>
#include <map>

#define fastIO "cin.tie(0); ios_base::sync_with_stdio(false)"

using namespace std;

vector <int> id, sz;

int root(int i){
	while(i != id[i])
		i = id[i];
	return i;
}

int Union(int p, int q){
	int i = root(p);
	int j = root(q);
	if(i != j){
		if(sz[i] < sz[j]){
			id[i] = j;
			sz[j] += sz[i];
			return sz[j];
		}else{
			id[j] = i;
			sz[i] += sz[j];
			return sz[i];
		}

	}
	return sz[i];
}


int main(){
	map <string, int> people;
	string name1, name2;
	int tc, n, index;
	fastIO;

	cin >> tc;

	while(tc--){

		cin >> n;

		people.clear();
		id.clear();
		sz.clear();
		id.push_back(0);
		sz.push_back(1);
		index = 1;

		for(int i = 0; i < n; i++){
			cin >> name1 >> name2;
			if(!people[name1]){
				people[name1] = index;
				id.push_back(index);
				sz.push_back(1);
				index++;
			}
			if(!people[name2]){
				people[name2] = index;
				id.push_back(index);
				sz.push_back(1);
				index++;
			}
			cout << Union(people[name1], people[name2]) << endl;
		}
	}

	return 0;
}