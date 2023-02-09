#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char user[60];
    char password[60];
    FILE* textfile;

    char* found_u;
    char* found_p;
    int found = 0, code;
    while (found == 0)
    {
        textfile = fopen("passwords.txt", "r");//Abrimos el archivo txt donde se almacenan los usuarios y contraseñas

        if (textfile == NULL)//Si no se encunetra el documento terminamos el programa
            return 1;
        
        printf("Username: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", password);

        while (!feof(textfile))//feof verifica que no sea el final del texto
        {
            char text[120];
            fscanf(textfile, "%s", text);
            //El comando strtork modifica el contenido del string original y convierte sus valores en tokens , esta funcion retorna el primer puntero a el token cadena, se puede ir reiterando sobre la misma funcion hasta que se entrege un puntero nulo lo cual significa que no hay mas tokens
            found_u = strtok(text, ":");//dividemos el string para econtrar su usuario
            found_p = strtok(NULL, ":");//dividemos el string para econtrar su contraseña

            if (strcmp(user, found_u) == 0 && strcmp(password, found_p) == 0)
            {
                found = 1;
                break;
            }
        }
    }

    int p = fork();

    if (p == 0)
        execlp("./myshell", "./myshell", NULL);


    while (1)
    {
        wait(&code);
        if (code == 256) //si se recibe un shutdown entonces terminamos todos los procesos con el mismo pid grupal
        {
            kill(getppid(), 9);
            exit(1);
        }
        else if (code == 0)
        {
            execlp("./getty", "./getty", NULL);
        }
    }

    return 0;
}
