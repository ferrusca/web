#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //write,read,close
#include <string.h> //strlen
#include <stdint.h>

int32_t main(int32_t argc, char *argv[]){
	char cadena[]= "Que tal, como estan!";
	char cadena2[100];
	char cadena3[100];
	int32_t fd;

	fd= open("nuevoPOSIX.txt", O_WRONLY | O_CREAT,0644);

	if(write(fd,cadena,sizeof(char)*strlen(cadena)) > 0)
		printf("Escritura exitosa\n\n");

	else
		printf("Fallo al escribir\n\n");

	close(fd);

	fd= open("nuevoPOSIX.txt", O_RDONLY,0444);

	if(read(fd,cadena2,sizeof(char)*strlen(cadena)) > 0)
		printf("Lectura exitosa\n\n");

	else
		printf("Lectura fallida\n\n");

	printf("\nEl contenido del archivo es: %s\n",cadena2);

	lseek(fd,5,SEEK_SET);

	if(read(fd,cadena3,sizeof(char)*strlen(cadena)) > 0)
		printf("Lectura exitosa\n\n");

	else
		printf("Lectura fallida\n\n");

	printf("\nEl contenido despues de lseek es: %s\n",cadena3);

	close(fd);

	return 0;
}
