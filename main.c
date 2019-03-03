#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
int main(int argc, char *argv[]) {
	lst *a=NULL,*c=NULL;
	a=cria(a);
	aluno *b=NULL;
	int o,v;char m[50];
	do{
		printf("MENU:\n1-Inserir aluno\n2-Remover aluno\n3-Buscar aluno\n4-Mostrar alunos\t");
		scanf("%d",&o);
		switch(o){
			case 1:
			b=dados();a=insere(a,b); ordenar(a);break;
			case 2:
			printf("Remover: ");fflush(stdin);gets(m);		
			v=excluir(a,m);
			if(v==0)a=remini(a);
			else if(v==1)c=remfim(a);
			else if(v==2)c=remmeio(a,m);
			break;
			case 3:busca(a);break;
			case 4:	imp(a);	break;
		}
	}while(o!=0);
	free(a);
	system("pause");
	return 0;
}
