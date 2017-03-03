#include <cstdio>

using namespace std;

typedef long long int lld;

int main(){
	lld n, m, ans, cuadros, esquinas, diferente, bordeS, bordeL;
	
	while(scanf("%lld %lld",&n,&m) && (n != 0 || m != 0) ){
		if( (n == 1 && m < 3) || (m == 1 && n < 3)){
			ans = 0;
		}else{
			cuadros = n * m;
			if(n == 1 || m == 1){
				esquinas = 2 * (cuadros - 2);
				diferente = (n > 1) ? n : m;
				ans = esquinas + ( (diferente - 2) * (cuadros - 3));
			}else{
				esquinas = 4 * (cuadros - 4);
				bordeS = 2 * (m - 2) * (cuadros - 6);
				bordeL = 2 * (n - 2) * (cuadros - 6);
				((n - 2) > 0 && (m - 2) > 0) ? ans = esquinas + bordeS + bordeL + ( ((n - 2) * (m - 2)) * (cuadros - 9)) : ans = esquinas + bordeS + bordeL;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
