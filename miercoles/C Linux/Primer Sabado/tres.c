#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool pegaTodo(int32_t,char**);
int32_t obtenSize(FILE*);

int32_t main(int32_t argc, char **argv){

	if(argc > 1)
		if(pegaTodo(argc,argv)){
			return EXIT_SUCCESS;
		
		}else
			return EXIT_FAILURE;

	else
		return EXIT_FAILURE;
}

bool pegaTodo(int32_t argc, char **argv){
	char *buffer= NULL;
	int32_t size= 0, var;
	FILE *initArch= NULL, *endArch= NULL;

	if(!(initArch= fopen(argv[1],"a")))
		return true;

	else{

		for(int32_t i=2; i<argc; i++){
			if(!(endArch= fopen(argv[i],"r"))){
				fclose(initArch);
				return true;

			}else{
				if(!(size= obtenSize(endArch))){
					fclose(initArch);
					return true;
						
				}else if(!(buffer= (char*)calloc(size,sizeof(char)))){
					fclose(initArch);
					return true;

				}else if(fread(buffer,sizeof(char),size,endArch) != size){
					free(buffer);
					fclose(initArch);
					fclose(endArch);
					return true;

				}else if(fwrite(buffer,sizeof(char),size,initArch) == size){
					free(buffer);
					fclose(endArch);
				
				}else{
					free(buffer);
					fclose(initArch);
					fclose(endArch);
					return true;
				} 
			}
		}

		return false;
	}

}

int32_t obtenSize(FILE *arch){
	int32_t size= 0;

	fseek(arch,0,SEEK_END);
	size= ftell(arch);
	rewind(arch);

	return size;
}