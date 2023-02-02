/*2.-Desarrolla un programa que reciba como argumento desde la línea de comandos un valor de entrada n cuyo significado sera nivel.
Los niveles se refieren concretamente a las relaciones padre-hijo, es decir,
si un proceso está en el "nivel 1", su hijo estará en el "nivel 2",
y su nieto en el "nivel 3" y así sucesivamente.

El nivel que se indica como argumentoen la línea de comandos tendrá el significado de cuántos niveles tendrá un árbol de procesos
y al finalizar deberá haber 2n procesos donde cada proceso deberá ir mostrando en pantalla  un número que será el nivel en el que se encuentre actualmente,
 de manera que cada uno de los procesos estará mostrando en pantalla todos los niveles por los que va pasando. Por ejemplo:

Si n=1 terminarán dos procesos que deberán mostrar en pantalla 0,1,1
Si n=2 terminarán cuatro procesos que deberán mostrar en pantalla 0,1,1,2,2,2,2
Si n=4 terminarán 16 procesos que deberán mostrar en pantalla 0,1,1,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
                                                              0,1,1,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
No es necesario que los números que se van mostrando en pantalla se muestren en orden.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]); // los argumentos de terminal se toman como chars, es por eso que debemos de combertirlos a int con atoi()

    // printf("0");//el printf() del padre

    for (int i = 0; i <= n; i++)
    {

        if (i == 0)
        {
            printf("%d", i); // el printf() del padre
            fflush(stdout);
        }
        else
        {

            fork();

            printf(",");
            printf("%d", i);
            fflush(stdout);
        }
    }

    return 0;
}
