#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int comparacion(char[], char[]);
int main()
{
there:
    char str1[20];
    char str4[20];
    char str2[20] = "Hola";
    char str5[20] = "Hello";
    char str3[20] = "Exit";
    pid_t p,p1;
    int status;

    // while(1){
    // there:

    printf("Introduce Hola para correr programa, Exit para salir: ");
    scanf("%s", str1);

    printf("Introduce Hello para correr programa 2, Exit para salir: ");
    scanf("%s", str4);

    p = fork();
    p1 = fork();

    int c = comparacion(str1, str2);
    int b = comparacion(str1, str3);
    int x = comparacion(str4, str5); 
    if (c == 0 && x == 0)
    {
        if (p == 0)
        {
            execlp("./Hola", "helloworld", NULL);
            // wait(&status);
        }

        if (p1 == 0)
        {
            execlp("./Hello", "holamundo", NULL);
            
        }
        wait(&status);
        goto there; // para volver a ejecutar
    }

    else if (b == 0)
    {
        exit(0);
    }
    else
    {
        printf("Terminado");
        exit(0);
    }

    return 0;
}

// Comparing both the strings.

// investigue sobre funcion
int comparacion(char a[], char b[])
{
    int flag = 0, i = 0;                 // integer variables declaration
    while (a[i] != '\0' && b[i] != '\0') // while loop
    {
        if (a[i] != b[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (a[i] != '\0' || b[i] != '\0')
        return 1;
    if (flag == 0)
        return 0;
    else
        return 1;
}
