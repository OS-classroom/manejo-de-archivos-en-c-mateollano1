#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void factorial(int hijo);

int main () {
    pid_t pid_h1, pid_h2;

    pid_h1 = fork();
    if(pid_h1 < 0){
        printf("Error en la creación del proceso.");
    }
    else if(pid_h1 == 0){
        factorial(1);
        exit(0);
    }    
    else{
        pid_h2 = fork();
        if(pid_h2 == 0){
            factorial(2);
        }
        else{
            wait();
        }
        
    }

    return 0;
}

void factorial(int hijo){
    int producto = 1;
    for(int i = 1; i<=10; i++){
        producto *= i;
        printf("Hijo%d: factorial(%d)=%d\n",hijo,i,producto);
    }
}