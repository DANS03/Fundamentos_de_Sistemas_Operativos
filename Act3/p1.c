/*1.-Escribir un programa que cree un hijo.
 El hijo debe escribir:"Soy el hijo" diez veces. 
 El padre debe escribir: "Soy el padre" diez veces.
Ambos procesos deberán mostrar concurrentemente sus líneas en pantalla y entre cada linea que 
escriban deben hacer una pausa de un segundo. 
  
  El padre debe esperar a que termine el hijo y mostrar el mensaje: "Mi proceso hijo ya ha terminado".*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>//Esta libreria elimina el warning de Implicit declaration of function ‘wait’
#include <unistd.h>


int main(){

    int pid;//aqui almaceno el ide de proceso
    pid = fork();

    for(int i = 0 ; i < 10 ; i++){

        if( pid == 0){//el valor del proceso hijo pid siempre sera 0
            printf("Soy el hijo \n");
            sleep(1);
        }
        else{
             printf("Soy el padre \n");
             sleep(1);
        }
    }

    if( pid == 0){
        exit(0);//terminamos la ejecucion del hijo
    }
    wait(NULL);//espera al que el hijo termine
    printf("Mi proceso hijo ya ha terminado");

    return 0;
}
