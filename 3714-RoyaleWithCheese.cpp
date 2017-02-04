#include <cstdio>
#include <cstring>
#include <map>

#define MAX 100005

using namespace std;

int main(){
	map <char, int> alph;
	map <int, int> change;
	char str[MAX];
	int len, h;

	change[2] = 5;
	change[5] = 2;
	change[6] = 9;
	change[9] = 6;
	change[12] = 15;
	change[15] = 12;
	change[16] = 19;
	change[19] = 16;
	change[20] = 50;
	change[21] = 51;
	change[22] = 55;
	change[23] = 53;
	change[24] = 54;
	change[25] = 52;
	change[26] = 59;

	while(scanf("%s",str) != EOF){
		len = strlen(str);
		h = 1;

		for(int i = 0; i < len && h < 27; i++){
			if(!alph[str[i]]){
				(!change[h]) ? alph[str[i]] = h : alph[str[i]] = change[h];
				h++;
			}
		}

		for(int i = 0; i < len; i++)
			printf("%d",alph[str[i]]);
		printf("\n");

		alph.clear();

	}
	return 0;
}