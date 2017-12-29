#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string cadena){
    int lef = 0, rig = cadena.length() - 1;
    while(lef <= rig){
        if(cadena[lef++] != cadena[rig--])
            return false;
    }
    return true;
}

int main(){
    string cadena;
    int tc, len;
    bool find;

    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> cadena;
        if(isPalindrome(cadena)){
            cout << "palindrome" << endl;
        }else{
            find = false;
            len = cadena.length();
            for(int i = 0; i < len - 1 && !find; i++)
                if(isPalindrome(cadena.substr(0, i + 1)) && isPalindrome(cadena.substr(i + 1, len - (i + 1))))
                    find = true;
            (find) ? cout << "bi-palindrome" << endl : cout << "non-palindrome" << endl;
        }
    }

    return 0;
}