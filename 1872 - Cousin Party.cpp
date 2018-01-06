#include <bits/stdc++.h>
#define MOD 1000007

using namespace std;

typedef unsigned long long int ull;

ull **multiply(ull **matrixOne, ull **matrixTwo){
    ull **result;
    result = new ull*[2];
    result[0] = new ull[2];
    result[1] = new ull[2];

    result[0][0] = ((matrixOne[0][0] * matrixTwo[0][0]) % MOD) + ((matrixOne[0][1] * matrixTwo[1][0]) % MOD);
    result[0][1] = ((matrixOne[0][0] * matrixTwo[0][1]) % MOD) + ((matrixOne[0][1] * matrixTwo[1][1]) % MOD);
    result[1][0] = ((matrixOne[1][0] * matrixTwo[0][0]) % MOD) + ((matrixOne[1][1] * matrixTwo[1][0]) % MOD);
    result[1][1] = ((matrixOne[1][0] * matrixTwo[0][1]) % MOD) + ((matrixOne[1][1] * matrixTwo[1][1]) % MOD);

    return result;
}

ull fibonacci(ull n){//O(log(n))
    ull **matrix, **result;
    bool state = false;

    result = new ull*[2];
    matrix = new ull*[2];
    for(int i = 0; i < 2; i++){
        result[i] = new ull[2];
        matrix[i] = new ull[2];
    }

    if(n <= 1)
        return 1;
    n -= 1;

    result[0][0] = result[0][1] = result[1][0] = result[1][1] = 1;
    matrix[1][0] = matrix[0][1] = matrix[0][0] = 1;
    matrix[1][1] = 0;

    while(n != 0){
        if(n % 2 != 0){
            if(!state){
                result = matrix;
                state = true;
            }else{
                result = multiply(result, matrix);
            }
        }
        n /= 2;
        matrix = multiply(matrix, matrix);
    }
    return (result[1][0] + result[1][1])%MOD;
}

int main(){
    ull tc, n;

    cin >> tc;

    while(tc--){
        cin >> n;
        (n == 0) ? cout << "1" << endl : cout << fibonacci(n + 2) << endl;
    }

    return 0;
}