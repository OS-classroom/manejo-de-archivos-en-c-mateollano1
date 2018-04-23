#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
	printf("Ejecutable: \n");
	char *args[] = {"/bin/ls", "-l", ".", NULL};
    printf("Forma 3: \n");
	execvp("/bin/ls", args);
	return 0;
}