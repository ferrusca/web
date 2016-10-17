#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool copiarAlv(char*,char*);
int32_t obtenSize(FILE*);

int32_t main(int32_t argc, char **argv){

	if(argc == 3){

		if(copiarAlv(argv[1],argv[2])){
			printf("No se pudo copiar alv :'v\n");
			return EXIT_FAILURE;

		}else
			return EXIT_SUCCESS;

	}else{
		printf("KYC prro! >:v\n");
		return EXIT_FAILURE;
	}
}

bool copiarAlv(char *from, char *to){
	char *buffer= NULL;
	int32_t size= 0;
	FILE *arch0= NULL, *arch1= NULL;

	if(!(arch0= fopen(from,"r")))
		return true;

	if(!(size= obtenSize(arch0))){
		fclose(arch0);
		return true;
	}

	if(!(buffer= (char*)calloc(size,sizeof(char)))){
		fclose(arch0);
		return true;
	}

	if((fread(buffer,sizeof(char),size,arch0)) == size){

		if(!(arch1= fopen(to,"w"))){
			free(buffer);
			fclose(arch0);
			return true;

		}else{
			if(fwrite(buffer,sizeof(char),size,arch1)){
				free(buffer);
				fclose(arch1);
				fclose(arch0);
				return false;

			}else{
				free(buffer);
				fclose(arch1);
				fclose(arch0);
				return true;

			}
		}

	}else{
		free(buffer);
		fclose(arch0);
		return true;
	}
}

int32_t obtenSize(FILE *arch){
	int32_t size= 0;

	fseek(arch,0,SEEK_END);
	size= ftell(arch);
	rewind(arch);

	return size;
}