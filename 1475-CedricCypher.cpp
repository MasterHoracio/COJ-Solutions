#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	int len, dif, ascii, exc;
	char piv, asc;

	while(getline(cin,line)){
		if(line[0] == '#') 
			break;
		len = line.length();	piv = line[len - 1];
		dif = piv - 'A';

		for(int i = 0; i < len - 2; i++){
			if(line[i] == ' '){
				cout << line[i];
			}else{
				ascii = line[i];
				if(ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122){
					asc = ascii;
				}else{
					if(ascii <= 90){
						ascii -= dif;
						if(ascii < 65){
							exc = 65 - ascii;
							asc = 'Z' - exc + 1;
						}else{
							asc = ascii;
						}
					}else{
						ascii -= dif;
						if(ascii < 97){
							exc = 97 - ascii;
							asc = 'z' - exc + 1;
						}else{
							asc = ascii;
						}
					}
				}
				cout << asc;
			}
			
		}
		cout << ".\n";
	}
	return 0;
}