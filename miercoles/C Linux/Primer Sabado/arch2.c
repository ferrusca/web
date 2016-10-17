#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int32_t main(int32_t argc, char const *argv[]){

  int32_t x;
  FILE *src, *des;

  //Verificacion de argumentos
  if(argc < 2){
      printf("Error: Faltan argumentos de entrada\n");
      exit(-1);
  }

  //Abrir el archivos
  if((src= fopen(argv[1],"r"))==NULL){
    printf("Error en apertura\n");
    exit(-1);
  }

  //Creacion
  if((des= fopen("Copia.txt","w"))==NULL){
    printf("Error en creacion de copia\n");
    exit(-1);
  }

  //Copia del archivos
  x= fgetc(src);
  while(!feof(src)){
    fputc(x,des);
    x= fgetc(src);
  }

  fclose(src);
  fclose(des);

  return 0;
}
