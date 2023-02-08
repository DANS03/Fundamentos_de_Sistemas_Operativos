#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t parentId;
    pid_t childId;
    
    childId = fork();

    if(childId == 0){
        childId = getpid();
        printf("%d <--Soy el hijo\n",childId);

        sleep(20);
        printf("Soy el hijo\n");
        exit(0);
    } else{
        parentId = getpid();
        
        printf("%d  <--Soy el padre\n",parentId);

        sleep(1);
    }
    return 0;
}