#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

int32_t main(int32_t argc, char const *argv[1]){

  char archivo_temporal[]= "nuevo.txt";
  char buff[10];
  struct stat statbuf; //Propiedades del archivo
  int32_t bytes;  //Bytes que vamos a mover
  int32_t archivo_origen; //Descriptores
  int32_t archivo_destino;

  if ((archivo_origen= open(argv[1],O_RDONLY))<0) {
    perror("Error al abrir el archivo origen");
    exit(EXIT_FAILURE);
  }

  if((archivo_destino= open(archivo_temporal,O_CREAT | O_WRONLY,0644))<0){
    perror("Error al abrir archivo temporal");
    exit(EXIT_FAILURE);
  }

  printf("El archivo de salida es %s\n",archivo_temporal);
  while((bytes= read(archivo_origen,buff,10))!=0){
    if((write(archivo_destino,buff,bytes))<0){
      perror("Error escritura destino");
      exit(EXIT_FAILURE);
    }
  }

  //Obtiene los datos del archivo en cuestion, antes de truncarlo
  fstat(archivo_destino,&statbuf);
  printf("Antes de ftruncate %s es de %ld bytes\n",archivo_temporal,statbuf.st_size);

  //Truncado de archivo
  ftruncate(archivo_destino,statbuf.st_size/2);
  fsync(archivo_destino);

  //Propiedades del destino
  fstat(archivo_destino,&statbuf);
  printf("Despues de ftruncate %s es de %ld bytes\n",archivo_temporal,statbuf.st_size);

  close(archivo_origen);
  close(archivo_destino);

  return 0;
}
