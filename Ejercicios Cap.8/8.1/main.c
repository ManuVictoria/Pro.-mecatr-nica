#include <stdio.h>
#include <string.h>

/* Estructura -1.
El programa muestra la manera en que se declara una estructura, asi como la forma en que se tiene
acceso a los campos de las variables de tipo estructura tanto para asignacion
de valores como para lectura y escritura. */

struct alumno                            /* Declaracion de la estructura. */
{
    int matricula;
    char nombre[20];
    char carrera[20];                    /* Campos de la estructura. */
    float promedio;
    char direccion[20];
};          /* Observa que la declaracion de una estructura termina con punto y coma. */

void main (void)
{
/* Observa que las variables de tipo estructura se declaran como cualquier otra variable. a1, a2 y a3
son variables de tipo estructura alumno. */
struct alumno a1 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"}, a2, a3;
/* Los campos de a1 reciben valores directamente. */

char nom [20], car[20], dir[20];
int mat;
float pro;

/* Los campos de a2 reciben valores por medio de una lectura. */
printf("\nIngrese la matricula del alumno 2: ");
scanf("%d", &a2. matricula);

}
