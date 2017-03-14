#include <cstdio>
#include <cstring>

#define maxn 105

using namespace std;

bool isAnagram(char string1[], char string2[]){
	int ascii[26], len;

	memset(ascii, 0, sizeof(ascii));

	len = strlen(string1);

	for(int i = 0; i < len; i++)
		if(string1[i] != ' ')
			ascii[string1[i] - 'a']++;
	
	len = strlen(string2);

	for(int i = 0; i < len; i++){
		if(string2[i] != ' '){
			if(ascii[string2[i] - 'a'] == 0)
				return false;
			else
				ascii[string2[i] - 'a']--;
		}
	}

	for(int i = 0; i  < 26; i++)
		if(ascii[i] > 0)
			return false;
	
	return true;
}

int main(){
	char string1[maxn], string2[maxn];
	int tc;

	scanf("%d",&tc);
	getchar();

	while(tc--){
		gets(string1);
		gets(string2);
		(isAnagram(string1, string2)) ? printf("yes\n") : printf("no\n");
	}
	return 0;
}