#include <cstdio>

using namespace std;

int main(){
	int n, m, k, t_equipos, resm, resn, t_res, equipos, estudiantes;

	scanf("%d %d %d",&m,&n,&k);

	equipos = m / 2;
	resm = resn = t_res = 0;

	if(equipos < 1){
		printf("%d\n",equipos);
	}else{
		resm = m % 2;
		if(n >= equipos){
			t_equipos = equipos;
			resn = n - equipos;
		}else{
			t_equipos = n;
			resm += (equipos - t_equipos) * 2;
		}
		t_res = resn + resm;
		if(t_res >= k){
			printf("%d\n",t_equipos);
		}else{
			k -= t_res;
			estudiantes = t_equipos * 3;
			estudiantes -= k;
			printf("%d\n",estudiantes / 3);
		}
	}

	return 0;
}