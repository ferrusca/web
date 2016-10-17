#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdint.h>

int32_t main(int32_t argc, char const *argv[]) {

  int32_t borra;
  char buffer[512];

  printf("El directorio actual es: %s\n",getcwd(buffer,512));
  chdir("."); //Llegar a directorio actual

  //Crear directorio
  mkdir("./directorio1",0755);
  mkdir("./directorio2",0755);
  printf("\nSe crearon los directorios\n");
  printf("\nDesea borrar el directorio1?(1.Si 2.No)\n");
  scanf("%d",&borra);

  if(borra==1)
    rmdir("./directorio1");

  return 0;
}
