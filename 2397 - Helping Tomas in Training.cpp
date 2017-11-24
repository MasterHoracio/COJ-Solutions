#include <bits/stdc++.h>

using namespace std;

int normal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct{
    int year, month, day;
}date;

date convertToDate(string str_date){
    date d;
    d.year = stoi(str_date.substr(0, 4));
    d.month = stoi(str_date.substr(5, 2));
    d.day = stoi(str_date.substr(8, 2));
    return d;
}

bool isLeap(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0)
                return true;
            else
                return false;
        }else{
            return true;
        }
    }
    return false;
}

int currDay(date d){
    int day = 0;
    if(isLeap(d.year)){
        for(int i= 0; i < d.month - 1; i++)
            day += leap[i];
    }else{
        for(int i= 0; i < d.month - 1; i++)
            day += normal[i];
    }
    day += d.day;
    return day;
}

int diferenceDate(date d_low, date d_up){
    int aux, count = 0;
    if(d_low.year == d_up.year){
        if(d_low.month == d_up.month){
            count = d_up.day - d_low.day;
        }else{
            if(isLeap(d_low.year)){
                count = leap[d_low.month - 1] - d_low.day;
                for(int i = d_low.month; i < d_up.month - 1; i++)
                    count += leap[i];
                count += d_up.day;
            }else{
                count = normal[d_low.month - 1] - d_low.day;
                for(int i = d_low.month; i < d_up.month - 1; i++)
                    count += normal[i];
                count += d_up.day;
            }
        }
    }else{
        if(isLeap(d_low.year)){
            count = 366 - currDay(d_low);
            for(int i = d_low.year + 1; i < d_up.year; i++){
                if(isLeap(i)){
                    count += 366;
                }else{
                    count += 365;
                }
            }
            count += currDay(d_up);
        }else{
            count = 365 - currDay(d_low);
            for(int i = d_low.year + 1; i < d_up.year; i++){
                if(isLeap(i)){
                    count += 366;
                }else{
                    count += 365;
                }
            }
            count += currDay(d_up);
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string low, up;
    date d_low, d_up;
    int tc;

    cin >> tc;

    while(tc--){
        cin >> low >> up;
        if(low == up){
            cout << "0\n";
        }else{
            d_low = convertToDate(low);
            d_up = convertToDate(up);
            cout << diferenceDate(d_low, d_up) << "\n";
        }
    }

    return 0;
}