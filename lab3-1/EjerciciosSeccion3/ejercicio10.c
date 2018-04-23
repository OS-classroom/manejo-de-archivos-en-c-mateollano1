#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main () {
    pid_t pid_h1, pid_h2, pid_h3, pid_h4;

    printf("El ID del proceso 1: %d\n",getpid());
    printf("El ID del padre del proceso 1: %d\n",getppid());

    //creacion del proceso 2, hijo 1
    pid_h1 = fork();

    if(pid_h1 < 0){
        printf("Error en la creación del proceso.");
    }
    else if(pid_h1 == 0){
        printf("ID proceso 2: %d\n", getpid());
        printf("ID padre del proceso 2: %d\n", getppid());
    }
    else{
        wait();
        //creacion del proceso 3, hijo 2
        pid_h2=fork();
        if(pid_h2 < 0){
            printf("Error en la creación del proceso.");
        }
        else if(pid_h2 == 0){
            
            printf("ID proceso 3: %d\n", getpid());
            printf("ID padre del proceso 3: %d\n", getppid());

            //creacion del proceso 4, hijo 1 del proceso hijo 2
            pid_h3 = fork();
            if(pid_h3 < 0){
                printf("Error en la creación del proceso.");
            }
            else if(pid_h3 == 0){
                sleep(0.2);
                printf("ID proceso 4: %d\n", getpid());
                printf("ID padre del proceso 4: %d\n", getppid());
            }
            else{
                wait();
                //creacion del proceso 5, hijo 2, del hijo 2
                pid_h4 = fork();
                if(pid_h4 < 0){
                    printf("Error en la creación del proceso.");
                }
                else if(pid_h4 == 0){                    
                    printf("ID proceso 5: %d\n", getpid());
                    printf("ID padre del proceso 5: %d\n", getppid());  
                    
                }
                else{
                    wait();
                        
                }
                
                
            }
        }
        else{
            wait();
                         char c[30] = "pstree -a ";
                    char pid[5];
                    sprintf(pid,"%d",getpid());
                    strcat (c, pid);
                    system(c);
        }
    }


    return 0;
}