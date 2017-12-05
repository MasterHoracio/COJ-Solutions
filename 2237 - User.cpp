#include <bits/stdc++.h>

using namespace std;

vector <string> splitString(string name){
    istringstream iss(name);
    vector <string> Fullname;
    string subs;
    do{
        iss >> subs;
        Fullname.push_back(subs);
    }while(iss);
    Fullname.pop_back();

    return Fullname;
}

int main(){
    map <string, bool> hashMap;
    vector <string> fullName;
    string name, user;
    int n;

    cin >> n;
    getchar();

    cout << "Lista de Usuarios del Congreso FEU:" << endl;

    for(int i = 1; i <= n; i++){
        getline(cin, name);
        fullName = splitString(name);
        user = "";
        if(fullName.size() == 3){
            user += fullName[0][0];
            user += fullName[1];
            if(!hashMap[user]){
                hashMap[user] = true;
            }else{
                user = user.substr(0, 1);
                user += fullName[2];
                hashMap[user] = true;
            }
        }else{
            user += fullName[0][0];
            user += fullName[1][0];
            user += fullName[2];
            if(!hashMap[user]){
                hashMap[user] = true;
            }else{
                user = user.substr(0, 2);
                user += fullName[3];
                hashMap[user] = true;
            }
        }
        transform(user.begin(), user.end(), user.begin(), ::tolower);
        cout << "user" << i << ": " << user << endl;
    }

    return 0;
}
