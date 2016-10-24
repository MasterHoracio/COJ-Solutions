#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
	int TC, k;
	map<int,string> mp;

	mp[1] = "one"; 
	mp[2] = "two";
	mp[3] = "three";
	mp[4] = "four";
	mp[5] = "five";
	mp[6] = "six";
	mp[7] = "seven";
	mp[8] = "eight";
	mp[9] = "nine";
	mp[10] = "ten";
	mp[11] = "eleven";
	mp[12] = "twelve";

	scanf("%d",&TC);

	while(TC--){
		scanf("%d",&k);
		printf("%s\n",mp[k].c_str());
	}

	return 0;
}
