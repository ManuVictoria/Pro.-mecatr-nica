#include <stdio.h>

/* Archivos con variables enteras y reales.
El programa lee datos de alumnos almacenados en un archivo y escribe la matr�cula y el promedio de cada alumno. */

int main(void)  /* Cambio de 'void main(void)' a 'int main(void)' para seguir el est�ndar de C */
{
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;

    ar = fopen("arc9.txt", "r");  /* Asignaci�n y verificaci�n por separado para mejor claridad */
    if (ar != NULL)
    {
        fscanf(ar, "%d", &n);
        for (i = 0; i < n; i++)
        {
            fscanf(ar, "%d", &mat);
            printf("%d\t", mat);
            pro = 0;
            for (j = 0; j < 5; j++)
            {
                fscanf(ar, "%f", &cal);
                pro += cal;
            }
            printf("%.2f\n", pro / 5);  /* Eliminaci�n de tabulador adicional y ajuste de formato */
        }
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }

    return 0;  /* Retorno de 0 para indicar terminaci�n exitosa */
}
