#include <stdio.h>

/* Archivos y cadenas de caracteres.
El programa escribe cadenas de caracteres en un archivo. */

int main(void)
{
    char cad[50];
    int res;
    FILE *ar;
    if ((ar = fopen("arc.txt", "w")) != NULL)
    {
        /* Se abre el archivo para escritura. En la misma instrucci�n se verifica si se
        pudo abrir. */
        printf("\n�Desea ingresar una cadena de caracteres? S�-1 No-0:");
        scanf("%d", &res);
        while (res)
        {
            fflush(stdin);
            printf("Ingrese la cadena: ");
            fgets(cad, sizeof(cad), stdin);
            /* Uso de fgets en lugar de gets para evitar desbordamientos de b�fer */
            cad[strcspn(cad, "\n")] = 0; /* Eliminar el salto de l�nea al final de la cadena*/
            fputs(cad, ar); /* Observa la forma como se escribe la cadena en el archivo.*/
            printf("\n�Desea ingresar otra cadena de caracteres? S�-1 No-0:");
            scanf("%d", &res);
            if (res)
                fputs("\n", ar);
            /* Se indica un salto de l�nea, excepto en la �ltima cadena. Si no
            se hiciera esta indicaci�n, la funci�n fputs pegar�a las cadenas y
            luego tendr�amos dificultades en el momento de leerlas. Por otra
            parte, si realiz�ramos este salto de l�nea al final de la �ltima
            cadena, en la escritura se repetir�a la �ltima cadena. */
        }
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
    return 0; /* Se agrega return 0 para indicar una terminaci�n exitosa */
}
