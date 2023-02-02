#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*Desarrolla un programa donde un proceso padre crea un hijo, el padre tendrá una duración de 20 segundos y el hijo una duración de 1 segundo. Antes de que el padre termine observa qué procesos hay, ¿En qué estado se encuentra el hijo?, ¿por qué?*/


int main(){
    pid_t parentId;
    pid_t childId;
    
    childId = fork();

    if(childId == 0){
        childId = getpid();
        printf("%d <--Soy el hijo\n",childId);

        sleep(1);
        printf("Soy el hijo\n");
        //exit();
    } else{
        parentId = getpid();
        
        printf("%d  <--Soy el padre\n",parentId);

        sleep(20);
    }
    return 0;
}