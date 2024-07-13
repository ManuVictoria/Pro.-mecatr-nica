#include <stdio.h>

/* Alumnos.
El programa almacena variables de tipo estructura alumno en un archivo. */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void escribe(FILE *); /* Prototipo de funci�n. */

int main(void) {
    FILE *ar;
    if ((ar = fopen("ad1.dat", "w")) != NULL) {
        escribe(ar);
        fclose(ar);
    } else {
        printf("\nEl archivo no se puede abrir");
    }
    return 0;
}

void escribe(FILE *ap) {
    /* Esta funci�n sirve para leer los datos de los alumnos utilizando una
    estructura tipo alumno, que se almacenar� posteriormente en un archivo. */
    alumno alu;
    int i = 0, r;
    printf("\n�Desea ingresar informaci�n sobre alumnos? (S�-1 No-0): ");
    scanf("%d", &r);
    while (r) {
        i++;
        printf("Matr�cula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        printf("Nombre del alumno %d: ", i);
        while (getchar() != '\n'); /* Limpiar el buffer de entrada */
        fgets(alu.nombre, sizeof(alu.nombre), stdin);
        size_t len = strlen(alu.nombre);
        if (len > 0 && alu.nombre[len-1] == '\n') {
            alu.nombre[len-1] = '\0';
        }

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);
        /* Observa que la funci�n fwrite tiene cuatro argumentos. El primero se
        utiliza para indicar la variable tipo estructura que se desea almacenar; el
        segundo muestra el tama�o de esa variable en t�rminos de bytes; el tercero
        se�ala el n�mero de variables que se leer�n o almacenar�n en el dispositivo
        de almacenamiento secundario, y el �ltimo representa el apuntador al inicio de
        la estructura FILE. */

        printf("\n�Desea ingresar informaci�n sobre m�s alumnos? (S�-1 No-0): ");
        scanf("%d", &r);
    }
}
