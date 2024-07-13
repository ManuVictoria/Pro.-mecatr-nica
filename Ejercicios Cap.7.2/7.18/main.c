#include <stdio.h>
#include <stdlib.h>

/* Cadena resuelta en form recursiva. */
void inverso(char *); /* Prototipo de funcion */

void main(void)
{
char fra[50];
printf("\nIngrese la linea de texto: ");
gets(fra);
printf("\nEscribe la linea de texto en forma inversa: ");
inverso(fra);
}
void inverso(char *cadena)
/* La funcion inverso obtiene precisamente el inverso de la cadena.*/
{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
