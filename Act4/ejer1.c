#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*1.- Desarrolla un programa donde un proceso padre crea un proceso hijo, al iniciar este proceso hijo, deberá matar o terminar a su padre*/

int main(){

    pid_t parentID = getpid();
    pid_t childId;
    
    childId = fork();

    if(childId == 0){
        kill(parentID,SIGTERM);
        sleep(1);
        printf("Soy el hijo\n");
        exit(0);
    } else{
        wait(NULL);
        printf("Soy el padre");
    }
    return 0;
}