#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int TC, n, d, arr[1005], ans;
    string line;

    cin >> TC;

    while(TC--){
        ans = 0;
        cin >> n >> d >> line;
        for(int i = 0 ; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n);

        if(line[0] == 'r')
            for(int i = n-1 ; i >= n-d ; i--)
                ans += arr[i];
        else
            for(int i = 0; i < d; i++)
                ans += arr[i];

       printf("%d\n", ans);

    }

    return 0;
}
