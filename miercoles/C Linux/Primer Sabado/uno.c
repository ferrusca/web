#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


bool obtenTam(char*);

int32_t main(int32_t argc, char *argv[]){

	if(argc == 2){
		
		if(obtenTam(argv[1])){
			printf("Error al obtener tama\u00F1o\n");
			return EXIT_FAILURE;
		
		}else
			return EXIT_SUCCESS;
		
	}else{
		printf("Nel prro! >:v\n");
		return EXIT_FAILURE;
	}
}

bool obtenTam(char *archivo){
	int32_t size;
	FILE *arch= NULL;

	if(!(arch= fopen(archivo,"r")))
		return true;

	fseek(arch,0,SEEK_END);

	size= ftell(arch);

	printf("El tama\u00F1o del archivo es: %d bytes\n",size);

	if(fclose(arch))
		return true;

	else
		return false;
}

