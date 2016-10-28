#include <iostream>
#include <string>

using namespace std;

int main()
{
    int sumpar, sumim;
    string str;
  
    while(cin >> str){
        sumpar = sumim = 0;
        if(str.length() == 1 && str[0] == '0')
            break;
        for(int i = 0; i < str.length(); i++)
           ( (i + 1) % 2 == 0) ? sumpar += str[i] - '0' : sumim += str[i] - '0';  
        ( (sumpar - sumim) % 11 == 0) ? cout << str << " is a multiple of 11.\n" : cout << str << " is not a multiple of 11.\n";
    }
    
    return 0;
}
