#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <int> registration;
    string registrationCode;
    int len;

    for(int i = 0; i < 5; i++){
        cin >> registrationCode;    len = registrationCode.length();
        for(int j = 0; j < len; j++)
            if(registrationCode[j] == 'F' && j + 1 < len && registrationCode[j + 1] == 'B' && j + 2 < len && registrationCode[j + 2] == 'I')
                registration.push_back(i + 1);
    }

    if(registration.empty())
        cout << "HE GOT AWAY!\n";
    else
        for(int i = 0; i < registration.size(); i++)
            (i + 1 < registration.size()) ? cout << registration[i] << " " : cout << registration[i] << "\n";

    registration.clear();

    return 0;
}
