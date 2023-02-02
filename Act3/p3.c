/*3.- Desarrolla un programa que reciba como argumento desde la línea de comandos un valor de entrada n cuyo significado sera un número de procesos a crear,
 de manera que cuando ejecutes tu programa este será el proceso padre que creará solamente n procesos hijos a un nivel, cada proceso hijo mostrará su número que será de 1 hasta n. 
 El proceso padre deberá esperar a que  todos los hijos terminen para al finalizar mostrar en pantalla el mensaje "Fin".

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>//Esta libreria elimina el warning de Implicit declaration of function ‘wait’
#include <unistd.h>


int main(int argc,  char *argv[]){

    int n = atoi(argv[1]);//los argumentos de terminal se toman como chars, es por eso que debemos de combertirlos a int con atoi()
    int status = 0;
    pid_t pid=1;

    for( int i = 0 ; i <= n ; i++){
    
        if( pid == 0 ){
            
            printf("Proceso hijo %d \n",i);

            exit(0);
        }else{
            if(i<n){
                pid=fork();
            }
            
        }
    } 

    for(int i = 0 ; i< n; i++){
        wait(NULL);
    } 

    printf("Fin\n");

    return 0;


}