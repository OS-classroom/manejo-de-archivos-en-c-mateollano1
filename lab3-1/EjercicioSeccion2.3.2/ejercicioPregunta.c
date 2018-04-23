#include <unistd.h>
#include <stdio.h>

/*Ejercicio ejecutar un comando que no exita y posteriormente un ls -s*/

int main(int argc, char *argv[]) {
	printf("Ejecutable: \n");

    execl("/bin/l", "/bin/l", "-k", ".", NULL);

	execl("/bin/ls", "/bin/ls", "-l", ".", NULL);

	return 0;
}