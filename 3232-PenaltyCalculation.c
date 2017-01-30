#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct nodo{
	int time;
	char S[5];
	struct nodo *next;
}Nodo, *ptrNodo;

ptrNodo newNodo(int t, char s[]){
	ptrNodo new = (ptrNodo) malloc(sizeof(Nodo));
	new -> time = t;
	strcpy(new -> S, s);
	new -> next = NULL;
	return new;
}

int empty(ptrNodo top){
	return (top == NULL);
}


int main(){
	int submissions, time, ans, flag, min = MAX;
	ptrNodo top = NULL, new;
	char S[5];

	scanf("%d",&submissions);

	ans = flag = 0;

	while(submissions--){
		scanf("%d %s",&time,S);

		new = newNodo(time, S);
		new -> next = top;
		top = new;
		
		if(S[0] == 'A'){
			flag = 1;
			if(time < min)
				min = time;
		}
	}

	if(flag == 1){
		while(top != NULL){
			if( top -> time < min && (top -> S[0] == 'W' || top -> S[0] == 'T' || top -> S[0] == 'R' || top -> S[0] == 'C') )
				ans += 20;
			top = top -> next;
		}
		ans += min;
		printf("%d\n",ans);
	}else{
		printf("0\n");
	}

	return 0;
}