#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct text{
	char *cadena;
	struct text *sig;
}text_t;

bool leer(char*);
text_t* nuevoNodo(text_t*);
void indexar(text_t*);

int32_t main(int32_t argc, char **argv){
    
    if(argc == 2){
    	leer(argv[1]);
    	return EXIT_SUCCESS;

    }else{
    	printf(">:v\n");
    	return EXIT_FAILURE;
    }

}

bool leer(char *nombre){
	text_t *inicio= NULL, *fin= NULL;
	FILE *arch= NULL;

	if(!(arch= fopen(nombre,"r")))
		return true;

	while(!feof(arch)){
		fin= nuevoNodo(inicio);
		if(!inicio)
			inicio= fin;

		fscanf(arch,"%m[^\n]\n",&fin->cadena);
	}

	indexar(inicio);
	fclose(arch);

	return false;
}

text_t* nuevoNodo(text_t *inicio){
	text_t *aux= inicio, *tmp;

	if(!aux){
		aux= (text_t*)calloc(1,sizeof(text_t));
		return aux;

	}else{
		while(aux){
			tmp= aux;
			aux= aux->sig;
		}

		tmp->sig= (text_t*)calloc(1,sizeof(text_t));
		return tmp->sig;
	}
}

void indexar(text_t *inicio){
	int32_t i= 0;
	text_t *aux= inicio, *tmp;
	FILE *arch= fopen("lista.txt","w");

	while(aux){
		fprintf(arch,"%d -> %s\n",i++,aux->cadena);
		tmp= aux;
		aux= aux->sig;
		free(tmp->cadena);
		free(tmp);
	}
}