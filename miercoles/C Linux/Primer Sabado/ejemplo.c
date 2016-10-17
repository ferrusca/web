/*
DIR es una estructura parecida a FILE en la que se encuentran
los datos necesarios para el manejo de directorios (carpetas).

Estructura dirent, miembros:

struct dirent {
  long d_ino;
  off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
};
struct dirent * readdir ( DIR *dirp ) //Leer la siguiente entrada de un directorio
void rewinddir(DIR *dirp);	//Nos situa al principio del directorio
void seekdir(DIR* dirp, long int loc);	//Nos sitúa en una posición del directorio
long int telldir(DIR* dirp);	//Nos indica la posición dentro del directorio
*/













#include <stdio.h>
#include <dirent.h>
#include <stdint.h>

int32_t main(){

    DIR *dir; //Flujo
    struct dirent *entry; //Informacion
    int32_t i;
    long offset;

    dir = opendir("/usr");

    puts("Comienza desde el primer objeto: ");
    for (i = 1; entry = readdir(dir); i++) {
        printf("%4d %s\n", i, entry->d_name);
        if (i == 4)
            offset = telldir(dir); //Proporciona la posicion actual, que es la cuarta
    }
    printf("\n");

    puts("Comienza desde el cuarto objeto ");
    seekdir(dir, offset); //Coloca la posicion en el cuarto objeto
    for (i = 1; entry = readdir(dir); i++){
        printf("%4d %s\n", i, entry->d_name);
		if (i == 5)
            offset = telldir(dir);
	}    
	printf("\n");

    rewinddir(dir);  //Regresa al inicio de la carpeta
    puts("Desde el inicio");
    //seekdir(dir, offset); //Se coloca en el quinto elemento
    for (i = 1; entry = readdir(dir); i++)
        printf("%4d %s\n", i, entry->d_name);
    printf("\n");

    closedir(dir);
    return 0;
}
