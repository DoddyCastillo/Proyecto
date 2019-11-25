/*
 * This program prints the twenty most frequent words in a text file.
 *
 * Run on William Shakespeare's King Henry VIII, the top twenty words
 * are:
 *
 * the     943
 * and     735
 * to      600
 * i       579
 * of      539
 * a       457
 * you     416
 * my      371
 * that    323
 * in      298
 * your    270
 * his     268
 * this    255
 * me      233
 * king    216
 * for     210
 * he      201
 * is      193
 * him     192
 * not     191
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdbool.h>
#include "archivo.h"
#define MAX 100
char *buffer[MAX];
void Opcion_W(Nodo *head,int palabras);
void Opcion_r(Nodo *head,int palabras,int n);
/* main program */
bool wflag = false; //Opción -c, usar grados Celsius
bool rflag = false; //Opción -i, especificar nombre archivo
int main (int argc,char **argv) {
	//lo que se enceuentra en libro
	char  delimitador[] = ",-.:;";
	char bufferLine[MAXLINE];
	Nodo *head=(Nodo*)malloc(sizeof(Nodo));
	int	i, n, m;	
	agregarElementos(buffer,argv,argc);
	int archivo=obtenerArchivo(buffer,argc);
	FILE *file = fopen( argv[archivo], "r" );
	n = 0;
    int opt;
	int nummero_palabras;
    while ((opt = getopt (argc, argv, "hw:r")) != -1){
		switch(opt)
		{
			case 'w':
			    if(atoi(optarg)!=0){
					nummero_palabras=atoi(optarg);
					wflag = true;
				}
				else{
					fprintf(stderr,"Tiene que ser un valor numerico");
				}
				break;
			case 'r':
				rflag = true;
				break;
			case 'h':
                printf("\n******************************************************************************************************* \n");
				printf("\n* wordfreq imprime las palabras más frecuentes en un archivo de texto.\n");
				printf("* uso:\n* %s [-w <numero de palabras> ] [-r ] [<nombre_archivo>]\n", argv[0]);
				printf("* %s -h \n", argv[0]);
				printf("* Opciones:\n");
				printf("* -h                           Ayuda, muestra este mensaje\n");
				printf("* -w <numero de palabras>      Especifica el número de palabras a mostrar [default: 20]* \n");
				printf("* -r                           Muestra frecuencia relativa\n");
                printf("\n******************************************************************************************************** \n");
				return 0;
			default:
				fprintf(stderr, "\tuso: %s [-h] [-w <numero de palabras> ] [-r ] [<nombre_archivo>] \n", argv[0]);
				return -1;
		}
	}

		if(file ==NULL)
		{
			fprintf(stderr,"Error de Archivo");
		}

		else
		{

			while (fscanf(file,"%s",bufferLine) > 0)
			{
				char *token = strtok(bufferLine, delimitador);
				if(token!=NULL)
				{
					while (token!=NULL)
					{
						//convertir todo en minuscula
						for(int i=0;token[i];i++)
						{
							token[i]=tolower(token[i]);
						}
						Nodo* result=list_find(head,token);
						if(result==NULL)
						{
							head=AgregarNodo(head,token);
						}
						else
						{
							result->count++;
						}
						token = strtok(NULL, delimitador);
						n++;
					}
					
				}
			}
			
		}

		if(wflag)
		{
			Opcion_W(head,nummero_palabras);
		}
		if (rflag)
		{
			Opcion_r(head,nummero_palabras,n);
		}
		

	}

void Opcion_W(Nodo *head,int palabras)
{
	Nodo *puntero=head;
	if (palabras<20)
	{
		int contador=0;
		while (contador<palabras && puntero!=NULL)
		{
			printf("%s\t%i\n",puntero->s,puntero->count);
			puntero=puntero->next;
			contador++;
		}
	}
	else
	{
		int contador=0;
		while (contador<20 && puntero!=NULL)
		{
			printf("%s\t%i\n",puntero->s,puntero->count);
			puntero=puntero->next;
			contador++;
		}	
	}	
}

void Opcion_r(Nodo *head,int palabras,int n)
{
	Nodo *puntero=head;
	if(palabras!=0)
	{
		if (palabras<20)
		{
			int contador=0;
			while (contador<palabras && puntero!=NULL)
			{
			printf("%s\t%d\n",puntero->s,(puntero->count)/n);
			puntero=puntero->next;
			contador++;
			}
		}
		else
		{
			int contador=0;
			while (contador<20 && puntero!=NULL)
			{
			printf("%s\t%d\n",puntero->s,(puntero->count)/n);
			puntero=puntero->next;
			contador++;
			}	
		}
	}
	else if (palabras=0)
	
	{
		int contador=0;
		while (contador<20 && puntero!=NULL)
		{
			float freRe=(puntero->count)/n;
			printf("%s\t%f\n",puntero->s,freRe);
			puntero=puntero->next;
			contador++;
		}	
	}
}