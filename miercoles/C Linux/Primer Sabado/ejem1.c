#include <stdio.h>
#include <string.h>
#include <stdint.h>

int32_t main(void){
   FILE *fp;
   char c[] = "Esta es una prueba";
   char buffer[100];

   fp = fopen("file.txt", "w+");

   fwrite(c, strlen(c) + 1, 1, fp);

   fseek(fp, SEEK_SET, 0);

   fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
   fclose(fp);

   return(0);
}
