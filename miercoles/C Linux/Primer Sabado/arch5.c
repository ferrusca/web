#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

int32_t main(int32_t argc, char const *argv[]){

  char buffer[512];

  printf("\nCon funcion getcwd()\n");
  printf("El dir es: %s\n",getcwd(buffer,512));

  printf("\nCon funcion get_current_dir_name()\n");
  printf("El dir actual es: %s\n",get_current_dir_name());

  printf("Funcion getwd()\n");
  printf("El dir actual es %s\n",getwd(buffer));

  return 0;
}
