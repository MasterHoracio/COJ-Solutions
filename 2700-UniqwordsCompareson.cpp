#include <iostream>
#include <string>

using namespace std;

int main(){
	string uniqOne, uniqTwo, solve1, solve2, solve3;
	int len;

	getline(cin, uniqOne);
	getline(cin, uniqTwo);

	solve1 = solve2 = solve3 = "";

	len = uniqOne.length();

	for(int i = 0; i < len; i++)
		(uniqTwo.find(uniqOne[i]) != string::npos) ? solve3 += uniqOne[i] : solve1 += uniqOne[i];

	len = uniqTwo.length();

	for(int i = 0; i < len; i++)
		if(uniqOne.find(uniqTwo[i]) == string::npos)
			solve2 += uniqTwo[i];

	cout << "First:" << solve1 << "\n" << "Second:" << solve2 << "\n" << "First&Second:" << solve3 << "\n";

	return 0;
}