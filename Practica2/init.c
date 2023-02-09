#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#define NumProssess 6

int main(int argc, char const* argv[])
{
    int p, code = 1;

    for (int i = 0; i < NumProssess; i++)//Ejecuta 6 procesos getty desde una nueva ventana.
    {
        
        p = fork();

        if (p == 0)
        {
            
            execlp("xterm", "xterm", "-e", "./getty", NULL);
        }
    }

    while (1)//Espera los codigos de terminacion de sus procesos hijos y si alguno de estos no ha termiado con un 0 entonces vuleve a crear un nuevo proceso de los contrario manda una señal de termminacion para el grupo de procesos.
    {
        int id = wait(&code);

        if (code == 0)
        {
            p = fork();
            if (p == 0)
            {
                execlp("xterm", "xterm", "-e", "./getty", NULL);
            }
        }
        else
        {
            killpg(0, 9);//manda un codigo de terminacion a todos los hijos
            break;
        }
    }
    printf("FIN\n");
    return 0;
}
