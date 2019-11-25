#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int obtenerArchivo(char **b, int n)
{
	int contador=0;
	for(int i=0;i<n;i++)
	{
		if(*(*b+i)!='\0'){
			contador++;
		}
	}
	return contador-1;
}

void agregarElementos(char **buffer,char **input, int argc)
{
	for(int i=0; i< argc; i++)
	{
		buffer[i]=(char *)malloc(MAX);
		strcpy(buffer[i],input[i]);
	}
}
Nodo* AgregarNodo(Nodo* head, char* word)
{
	Nodo* nuevo=(Nodo* )malloc(sizeof(Nodo));
	nuevo->count=1;
	strcpy(nuevo->s,word);
	nuevo->next=head;

	return nuevo;
}
Nodo* list_find(Nodo * start, char *word)
{
	Nodo* puntero=start;
	while (puntero!=NULL)
	{
		if(strcmp(puntero->s,word)==0)
		{
			return puntero;
		}
		puntero=puntero->next;
	}
	return NULL;
}