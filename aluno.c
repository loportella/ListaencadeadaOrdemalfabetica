#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
//declaração das estruturas
struct Aluno{
	char nome[50];
	float n1;float n2;
};
struct lista{
	struct Aluno *a;
	struct lista *prox;
};
//inicializa a lista com nada
lst *cria(lst *l){
	 return NULL;
}
//testa se a estrutura tem 0 ou 1 elemento
int vazia(lst *l){
	if(l==NULL){
		return 1;
	}else if(l->prox==NULL){
		return 2;
	}else{
		return 0;
	}
}
//coleta dos dados
aluno *dados(){
	aluno *a;
	a=(aluno*)malloc(sizeof(aluno));
	fflush(stdin);
	printf("Nome: ");gets(a->nome);
	printf("Nota 1: ");scanf("%f",&a->n1);
	printf("Nota 2: ");scanf("%f",&a->n2);
	system("cls");
	return a;
}
//insere no inicio da lista
lst *insere(lst *l,aluno *e){
	lst *n=(lst*)malloc(sizeof(lst));
	if(vazia(l)==1){
		n->a=e;n->prox=NULL;
		return n;
	}else{
		n->a=e;n->prox=l;
		return n;
	}
	
}
//ordena a lista por ordem alfabetica
void ordenar(lst *l){
	if(vazia(l)==1||vazia(l)==2)
	{return ;}
	lst *no=(lst*)malloc(sizeof(lst));
	while(l->prox!=NULL){
		if(strcmp(l->a->nome,l->prox->a->nome)>0){
			no->a=l->a;
			l->a=l->prox->a;
			l->prox->a=no->a;
		}l=l->prox;
	}l->prox=NULL;
}
//busca por um determinado elemento
void busca(lst *l){
	lst *a;char m[50];int i=0;
	if(vazia(l)==1){
		printf("Lista vazia\n");
	}else{
	printf("Pesquisar pelo aluno:");
	fflush(stdin); gets(m);
	for(a=l;a!=NULL;a=a->prox){
	if(strcmp(a->a->nome,m)==0){
		printf("Nome: %s\n",a->a->nome);i++;
		printf("Nota 1: %.2f\n",l->a->n1);
		printf("Nota 2: %.2f\n",l->a->n2);
	}
}printf("\n");free(a);
if(i==0)printf("%s nao foi encontrado\n",m);
}
}
//função que procura onde o elemento a ser excluido se encontra
//inicio, meio ou no fim da lista
int excluir(lst *l,char m[50]){
	lst *aux,*a=l,*b=l;
	int i=0,v=0,t=0,c;
	if(vazia(l)==1){
	printf("Nao ha dados\n");return -1;}
	else{
		while(a!=NULL){
			if(strcmp(a->a->nome,m)==0){
				if(t==0){
					t=2;break;
				}else if(t==1&&a->prox==NULL){
					t=3;break;
				}else if(t==1&&a->prox!=NULL){
					t=4;break;
				}
			}
			a=a->prox;i++;t=1;
		}
		if(t==2)return 0;
		else if(t==3)return 1;
		else if(t==4)return 2;
		else {
		printf("Nome não foi encontrado\n");return 40;}
	}
}
//caso tenha que remover o último nó da lista
lst *remfim(lst *l){
	lst *a=l->prox,*b=l;
	while(a->prox!=NULL){
		b=a;a=a->prox;
	}b->prox=NULL;
	printf("Aluno excluido com sucesso: ");
	return a;
}
//caso tenha que remover o primeiro nó da lista
lst *remini(lst *l){
	lst *a=l->prox;
	if(a==NULL)return NULL;
	else{l->prox=a->prox;
	printf("Aluno excluido com sucesso: ");
	 return a;}
}
//remover um nó do meio da lista
lst *remmeio(lst *l,char m[50]){
	lst *a=l,*b=l;int i=2;
	while(a!=NULL){
		if(strcmp(a->prox->a->nome,m)==0){
			break;}
			a=a->prox;
	}lst *t=a->prox;
		a->prox=t->prox;
		t->prox=NULL;free(t);
		printf("Aluno excluido com sucesso: ");
	return l;
}
void imp(lst *l){
	system("cls");
	lst *aux;
	if(vazia(l)==1){
		printf("Nao ha dados\n");
	}else{
	printf("Dados armazenados: \n");
	for(aux=l;aux!=NULL;aux=aux->prox){
		printf("Nome: %s\n",aux->a->nome);
		printf("Nota 1: %.2f\n",aux->a->n1);
		printf("Nota 2: %.2f\n",aux->a->n2);
	}printf("\n");
}}
