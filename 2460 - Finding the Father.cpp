#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long int ll;

string toBinary(ll number){
    string binary = "";
    while(number){
        binary += (number & 1) ? '1' : '0';
        number >>= 1;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

ll toDecimal(string binary){
    ll pot = 1, len = binary.length(), ans = 0;
    for(int i = len - 1; i >= 0; i--){
        if(binary[i] == '1')
            ans += pot;
        pot *= 2;
    }
    return ans;
}

int countOnes(string binary){
    int len = binary.length(), count = 0;
    for(int i = 0; i < len; i++)
        if(binary[i] == '1')
            ++count;
    return count;
}

bool allToLeft(string binary, int ones){
    for(int i = 0; i < ones; i++)
        if(binary[i] != '1')
            return false;
    return true;
}

string moveBits(string binary, int ones){
    int len = binary.length() + 1;
    string newBinary = "";
    for(int i = 0; i < len; i++)
        newBinary += (i == 0) ? '1' : '0';

    for(int i = len - 1; i > (len - 1) - (ones - 1); i--)
        newBinary[i] = '1';

    return newBinary;
}

string orderBits(string binary, int ones){
    int len = binary.length(), c_ones = 0;
    
    for(int i = len - 1; i >= 0; i--){
        if(binary[i] == '1'){
            while(binary[i] == '1'){
                c_ones++;
                i--;
            }
            binary[i] = '1';
            binary[i + 1] = '0';
            for(int j = i + 1; j < len; j++)
                binary[j] = '0';
            break;
        }
    }

    for(int i = len - 1; i > (len - 1) - (c_ones - 1); i--)
        binary[i] = '1';

    return binary;
}

int main(){
    ll number, ones;
    string binary;

    while(cin >> number){
        binary = toBinary(number);
        ones = countOnes(binary);
        binary = (allToLeft(binary, ones)) ? moveBits(binary, ones) : orderBits(binary, ones);
        cout << toDecimal(binary) << endl;
    }

    return 0;
}