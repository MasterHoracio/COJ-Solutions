#include <iostream>
#include <string>
#include <map>

const int c = 39;
const int d = 92;

using namespace std;

void solve(map <char, char> &keyboard){
	keyboard['W'] = 'Q';		
	keyboard['S'] = 'A';
	keyboard['X'] = 'Z';
	keyboard['E'] = 'W';
	keyboard['D'] = 'S';
	keyboard['C'] = 'X';
	keyboard['R'] = 'E';
	keyboard['F'] = 'D';
	keyboard['V'] = 'C';
	keyboard['T'] = 'R';
	keyboard['G'] = 'F';
	keyboard['B'] = 'V';
	keyboard['Y'] = 'T';
	keyboard['H'] = 'G';
	keyboard['N'] = 'B';
	keyboard['U'] = 'Y';
	keyboard['J'] = 'H';
	keyboard['M'] = 'N';
	keyboard['I'] = 'U';
	keyboard['K'] = 'J';
	keyboard[','] = 'M';
	keyboard['O'] = 'I';
	keyboard['L'] = 'K';
	keyboard['.'] = ',';
	keyboard['P'] = 'O';
	keyboard[';'] = 'L';
	keyboard['/'] = '.';
	keyboard['['] = 'P';
	keyboard[']'] = '[';
	keyboard[d] = ']';
	keyboard[c] = ';';
	keyboard['1'] = '`';
	keyboard['2'] = '1';
	keyboard['3'] = '2';
	keyboard['4'] = '3';
	keyboard['5'] = '4';
	keyboard['6'] = '5';
	keyboard['7'] = '6';
	keyboard['8'] = '7';
	keyboard['9'] = '8';
	keyboard['0'] = '9';
	keyboard['-'] = '0';
	keyboard['='] = '-';
}

int main(){
	map <char, char> keyboard;
	string cad;
	int len;

	solve(keyboard);

	getline(cin, cad);
	len = cad.length();

	for(int i = 0; i < len; i++){
		if(cad[i] == ' ' || cad[i] == '\n')
			printf("%c",cad[i]);
		else
			printf("%c",keyboard[cad[i]]);
	}printf("\n");

	return 0;
}