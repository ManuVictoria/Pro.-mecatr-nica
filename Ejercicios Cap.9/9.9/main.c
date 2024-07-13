#include <stdio.h>

/* Alumnos.
El programa lee bloques �variables de tipo estructura alumno� de un archivo
de acceso directo. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void lee(FILE *); /* Prototipo de funci�n. */

int main(void) {
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r")) != NULL) {
        lee(ar);
        fclose(ar);
    } else {
        printf("\nEl archivo no se puede abrir");
    }
    return 0;
}

void lee(FILE *ap) {
    /* Esta funci�n se utiliza para leer bloques de un archivo de acceso directo. */
    alumno alu;
    size_t leidos;

    leidos = fread(&alu, sizeof(alumno), 1, ap);
    while (leidos == 1) {
        printf("\nMatr�cula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %f\t", alu.promedio);
        puts(alu.nombre);
        leidos = fread(&alu, sizeof(alumno), 1, ap);
    }
}
