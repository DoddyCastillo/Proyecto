#define MAXWORDS	10000
#define MAXSTRING	100
#define MAX 100
#define MAXLINE 1024

/* structure holding word frequency information */

typedef struct Nodo {
	char	s[MAXSTRING];	/* the word */
	int	count;		/* number of times word occurs */
	struct Nodo* next;
}Nodo;


int obtenerArchivo(char **b, int n);
void agregarElementos(char **buffer,char **input, int argc);
Nodo* list_find(Nodo * start, char *word);
Nodo* AgregarNodo(Nodo* head, char* word);

