#include <cstdio>

using namespace std;

typedef struct{
	int day, month, year, consume;
}date;

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//bisiesto febrero tiene 29 dias

bool hasNext(date past, date curr){
	date cmp;
	if(past.day >= months[past.month - 1]){
		if( ( ( (past.year % 4 == 0) && (past.year % 100 != 0) ) || (past.year % 400 == 0) ) && (past.month == 2) ){
			if(past.day == 29){
				cmp.year = past.year;
				cmp.month = past.month + 1;
				cmp.day = 1;
			}else{
				cmp.year = past.year;
				cmp.month = past.month;
				cmp.day = past.day + 1;
			}
		}else{
			if(past.month == 12){
				cmp.year = past.year + 1;
				cmp.month = 1;
				cmp.day = 1;
			}else{
				cmp.year = past.year;
				cmp.month = past.month + 1;
				cmp.day = 1;
			}
		}
	}else{
		cmp.year = past.year;
		cmp.month = past.month;
		cmp.day = past.day + 1;
	}
	if(cmp.year == curr.year && cmp.month == curr.month && cmp.day == curr.day)
		return true;
	return false;
}

int main(){
	int n, sum, days;
	date tmp, past;
	
	while(scanf("%d",&n) &&  n != 0){
		days = sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d",&tmp.day ,&tmp.month ,&tmp.year ,&tmp.consume);
			if(i != 0){
				if(hasNext(past, tmp)){
					++days;
					sum += tmp.consume - past.consume;
				}
			}
			past = tmp;
		}
		printf("%d %d\n",days,sum);
	}
	
	return 0;
}
