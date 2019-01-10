#include <bits/stdc++.h>

using namespace std;
typedef long long int lld;

lld modpow(lld base, lld exponent, lld module){
  lld answ = 1, current, past = base;
  string binary = "";
  while(exponent){
    binary += (exponent & 1) ? "1" : "0";
    exponent >>= 1;
  }
  for(int i = 0; i < binary.length(); i++){
    current = (i == 0) ? past % module : (past * past) % module;
    past = current;
    if(binary[i] == '1')
      answ = (answ * current) % module;
  }
  return answ;
}

int main(){
  lld tc, n;
  scanf("%lld",&tc);
  for(int i = 0; i < tc; i++){
    scanf("%lld",&n);
    (n == 1) ? printf("1\n") : printf("%lld\n",modpow(2,n-1,1000000007));
  }
  return 0;
}
