#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str){
    int length = str.length(), rigth = str.length() - 1;
    for(int i = 0; i < length/2; i++){
        if(str[i] != str[rigth])
            return false;
        rigth--;
    }
    return true;
}

string longetsPalindrome(string str){
    int length = str.length();
    string maxPalindrome = "";
    for(int i = 0; i < length; i++){
        for(int j = length - 1; j >= 0 && j != i; j--){
            if(isPalindrome(str.substr(i,j+1-i)))
                if(str.substr(i,j+1-i).length() > maxPalindrome.length())
                    maxPalindrome = str.substr(i,j+1-i);
        }
    }
    return maxPalindrome;
}

int main()
{
    string str;

    cin >> str;

    cout << longetsPalindrome(str) << "\n";

    return 0;
}
