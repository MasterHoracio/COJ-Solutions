#include <iostream>
#include <cmath>

using namespace std;

bool sameCol(int x1, int y1, int x2, int y2){
    if(x1 == x2)
        return true;
    return false;
}


int main(){
    int r, c, x1, x2, y1, y2, x3, y3, x4, y4;

    cin >> c >> r >> x1 >> y1 >> x2 >> y2;

    //check if there are on the same line or column

    if(abs(x2 - x1) >= 2){
        x4 = x3 = max(x2, x1) - 1;
        y3 = 0;
        y4 = r;
    }else if(abs(y2 - y1) >= 2){
        y3 = y4 = max(y1, y2) - 1;
        x3 = 0;
        x4 = c;
    }else{
        if(sameCol(x1, y1, x2, y2)){
            if(y1 > y2){
                x3 = c;
                y3 = y1;
                y4 = y2;
                x4 = 0;
            }else{
                x3 = c;
                y3 = y2;
                y4 = y1;
                x4 = 0;
            }
        }else{
            if(x1 > x2){
                x3 = x1;
                y3 = 0;
                x4 = x2;
                y4 = r;
            }else{
                x3 = x2;
                y3 = 0;
                x4 = x1;
                y4 = r;
            }
        }
    }

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}
