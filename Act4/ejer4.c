#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*4.- Desarrolla un programa que al ejecutarse cree dos procesos hijos y cada uno de los hijos creará 3 nuevos procesos hijos.
 De esta manera habrá un proceso padre, dos procesos hijos y seis procesos nieto. Los hijos y los nietos deberán tener al final la instrucción
  sleep(20), pero el padre después de ejecutar la instrucción sleep(5) deberá terminar a todos los hijos y nietos.*/
int createGrandChildren(){

    pid_t grandChildId;

    for(int i = 0 ; i <= 2 ; i++){
    
        grandChildId = fork();

        if(grandChildId == 0){
            printf("==>I'm a grandson %d\n",getpid());
            sleep(20);
            printf("==>Goodbye grandson %d\n",getpid());
            exit(0);
        } 
    }
    sleep(20);
    printf("Goodbye son %d\n",getpid());
    exit(0);
    
}



int main(){

    pid_t childId,childGroup;

    printf(">Parent %d\n",getpid());
    
    for(int i = 0 ; i <= 1 ; i++){
    
        childId = fork();

        if(childId == 0){
            printf("=>I'm a son %d\n",getpid());
            createGrandChildren();
        } 
        
    }
    
    sleep(5);
    printf("\n\n>Goodbye Parent: %d\n",getpid());
    childGroup = getpgrp();
    killpg(childGroup, SIGKILL);
    

    return 0;
}