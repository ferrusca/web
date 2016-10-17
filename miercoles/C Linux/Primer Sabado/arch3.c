#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

int32_t main(int32_t argc, char const *argv[]){

  int32_t origen, destino, amover;
  char buff[10];

  origen= open(argv[1],O_RDONLY);
  destino= open("CopiaPx.txt",O_WRONLY | O_CREAT);

  if(origen<0 || destino<0){
    perror("Fallo la apertura de archivos");
    exit(EXIT_FAILURE);
  }

  while((amover= read(origen,buff,10))!=0){
      if((write(destino,buff,amover)<0))
        perror("Error al escribir");
  }

  close(origen);  //src
  close(destino); //des

  return 0;
}
