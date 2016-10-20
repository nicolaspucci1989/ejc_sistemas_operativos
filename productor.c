#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int bandera, fd;	
	char *nfifo="fifo";

	printf("Productor\n\n");

	if(argc != 2){
			printf(stderr, "modo de uso: ./productor mensaje\n");
			exit(1);
	}
	/* Crear pipe */
	bandera=mkfifo(nfifo, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if(!bandera){
		printf("productor espera apuertura de consumirod\n");
		fd=open(nfifo, O_WRONLY);
		if(fd == -1)
			perror("error al abrir la tuberia (escritura)\n");
		else{
			/* escritura en la tuberia */
		wirte(fd, argv[1], 100);
		printf("productor envio: %s\n", argv[1]);
		close(fd);
		}
	}
	else
		perror("error al crear la tuberia\n");
	return 0:
}
