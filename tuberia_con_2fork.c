#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LEER				0
#define ESCRIBIR		1	
#define TAMANIO		110	


int main()
{
	int descr[2];
	int bytesleidos;
	char mensaje[TAMANIO], *frase = "Papi, me gusta mucho la cancio Poker Face de Lady Gaga pero no tanto como las clasees de Sistemas Operativos.";	

	pipe(descr);
	if (fork() == 0) {
		/* Hijo 1 escribe */
		close (descr[LEER]);
		write (descr[ESCRIBIR], frase, strlen(frase));
		close (descr[ESCRIBIR]);
	} else {
		if (fork() == 0) {
			/* Hijo 2 lee */
			close (descr[ESCRIBIR]);	
			bytesleidos = read (descr[LEER], mensaje, TAMANIO);
			mensaje[bytesleidos]='\0';
			printf ("Bytes leidos: %d\n", bytesleidos);
			printf ("Mensaje enviado por el Hijo: %s\n", mensaje);
			close (descr[LEER]);
		} else{
			/* Padre espera a los hijo */
 			wait(0);		
 			wait(0);		
			return(0);
		} 
	} 
}
