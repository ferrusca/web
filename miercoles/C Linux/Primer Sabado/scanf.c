#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int32_t main(void){
	char *cadena= NULL;

	scanf("%m[^\n]s",&cadena);

	printf("%s",cadena);
	free(cadena);

	return EXIT_SUCCESS;
}