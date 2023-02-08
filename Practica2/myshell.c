#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int wordsCount(const char s[])//Es una funcion la cual cuenta la cantidad de palabras que tiene el comando retornando un int con este numero
{
    int len = strlen(s);
    int cont = 0;
    for (int i = 1; i < len - 1; i++)
    {
        if (s[i] == 32 && s[i - 1] != 32 && s[i + 1] != 32)//hacemos la cuenta de las palabras mediante los espacios
        {
            cont++;
        }
    }
    return cont + 1;
}

int main(int argc, char const* argv[])
{
    char command[100];
    int index, words,p;
    char* word;


    while (1)
    {
        printf("sh >");
        fgets(command, 100, stdin);
        words = wordsCount(command);
        
        if (strcmp(command, "\n") == 0){//Ignoramos el comando si el usuario solo pone un salto de linea.
            continue;
        }

        command[strlen(command) - 1] = '\0';// Remplasamos el salto de linea con un caracter de terminacion.
        
        char* arguments[words];//creamos un arreglo con el tamaño de palabras del comando original

        word = strtok(command, " ");//El comando strtork modifica el contenido del string original y convierte sus valore en tokens , esta funcion retorna el primer puntero a el token cadena, se puede ir reiterando sobre la misma funcion haste que se entrege un puntero nulo lo cual significa que no hay mas tokens

        index = 0;
        while (word != NULL){
            arguments[index++] = word;//se almacena el valor de cada palabra en un arreglo
            word = strtok(NULL, " ");//se iteran los valores de word
        }

        arguments[index] = NULL;

        if (strcmp(command, "shutdown") == 0){//evaluamos si el ususrio ha terminado el programa y si es asi terminamso con el comando 1
            exit(1);
        }

        if (strcmp(command, "exit") == 0){//evaluamos si el ususrio ha salido el programa y si es asi regresamos terminamos el proceso
            break;
        }

        p = fork();

        if (p == 0)
        {
            execvp(command, arguments);//execvp toma el primer valor como el momando a ejecultar y despues una lista de argumentos de esa funcion
            exit(5);
        }

        wait(NULL);//espera al proceso hijo a que termine
    }
    exit(0);

    return 0;
}
