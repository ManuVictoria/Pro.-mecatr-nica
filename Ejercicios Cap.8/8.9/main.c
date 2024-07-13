#include <stdio.h>
#include <string.h>

/* Bienes ra�ces.
El programa maneja informaci�n sobre las propiedades que tiene una empresa
de bienes ra�ces de la ciudad de Lima, Per�, tanto para venta como para renta. */

typedef struct {
    char zona[20];
    char calle[20];
    char colo[20];
} ubicacion;

typedef struct {
    char clave[5];
    float scu;   /* Superficie cubierta */
    float ste;   /* Superficie terreno */
    char car[50]; /* Caracter�sticas */
    ubicacion ubi;
    float precio;
    char dispo; /* Disponibilidad */
} propiedades;

/* Declaraci�n de la estructura ubicaci�n.*/
/* Colonia. */
/* Declaraci�n de la estructura propiedades.*/
/* Superficie cubierta. */ /* Superficie terreno. */ /* Caracter�sticas. */
/* Observa que este campo es de tipo estructura ubicaci�n. */
/* Disponibilidad. */

void Lectura(propiedades *, int);
void F1(propiedades *, int); /* Prototipos de funciones. */
void F2(propiedades *, int);

int main(void) {
    propiedades PROPIE[100];
    /* Se declara un arreglo unidimensional de tipo estructura propiedades. */
    int TAM;
    do {
        printf("Ingrese el n�mero de propiedades: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);
    /* Se verifica que el tama�o del arreglo sea correcto. */
    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
    return 0;
}

void Lectura(propiedades A[], int T)
/* Esta funci�n se utiliza para leer un arreglo unidimensional de tipo estructura propiedades de T elementos. */
{
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos de la propiedad %d", I + 1);
        printf("\nClave: ");
        fflush(stdin);
        fgets(A[I].clave, sizeof(A[I].clave), stdin);
        A[I].clave[strcspn(A[I].clave, "\n")] = '\0'; /* Eliminar el salto de l�nea */

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);

        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);

        printf("Caracter�sticas: ");
        fflush(stdin);
        fgets(A[I].car, sizeof(A[I].car), stdin);
        A[I].car[strcspn(A[I].car, "\n")] = '\0'; /* Eliminar el salto de l�nea */

        printf("\tZona: ");
        fflush(stdin);
        fgets(A[I].ubi.zona, sizeof(A[I].ubi.zona), stdin);
        A[I].ubi.zona[strcspn(A[I].ubi.zona, "\n")] = '\0'; /* Eliminar el salto de l�nea */

        printf("\tCalle: ");
        fflush(stdin);
        fgets(A[I].ubi.calle, sizeof(A[I].ubi.calle), stdin);
        A[I].ubi.calle[strcspn(A[I].ubi.calle, "\n")] = '\0'; /* Eliminar el salto de l�nea */

        printf("\tColonia: ");
        fflush(stdin);
        fgets(A[I].ubi.colo, sizeof(A[I].ubi.colo), stdin);
        A[I].ubi.colo[strcspn(A[I].ubi.colo, "\n")] = '\0'; /* Eliminar el salto de l�nea */

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        printf("Disponibilidad (Venta-V Renta-R): ");
        fflush(stdin);
        scanf("%c", &A[I].dispo);
    }
}

void F1(propiedades A[], int T)
/* Esta funci�n se utiliza para generar un listado de las propiedades disponibles para venta en la zona de Miraflores, cuyo valor oscila entre 450,000 y 650,000 nuevos soles. */
{
    int I;
    printf("\n\t\tListado de Propiedades para Venta en Miraflores\n");
    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0) && (A[I].precio >= 450000) && (A[I].precio <= 650000)) {
            printf("\nClave de la propiedad: ");
            puts(A[I].clave);
            printf("Superficie cubierta: %.2f\n", A[I].scu);
            printf("Superficie terreno: %.2f\n", A[I].ste);
            printf("Caracter�sticas: ");
            puts(A[I].car);
            printf("Calle: ");
            puts(A[I].ubi.calle);
            printf("Colonia: ");
            puts(A[I].ubi.colo);
            printf("Precio: %.2f\n", A[I].precio);
        }
    }
}

void F2(propiedades A[], int T)
/* Al recibir como datos una zona geogr�fica de Lima, Per�, y un cierto rango respecto al monto, esta funci�n genera un listado de todas las propiedades disponibles para renta. */
{
    int I;
    float li, ls;
    char zon[20];
    printf("\n\t\tListado de Propiedades para Renta\n");
    printf("Ingrese zona geogr�fica: ");
    fflush(stdin);
    fgets(zon, sizeof(zon), stdin);
    zon[strcspn(zon, "\n")] = '\0'; /* Eliminar el salto de l�nea */

    printf("Ingrese el l�mite inferior del precio: ");
    scanf("%f", &li);
    printf("Ingrese el l�mite superior del precio: ");
    scanf("%f", &ls);

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0) && (A[I].precio >= li) && (A[I].precio <= ls)) {
            printf("\nClave de la propiedad: ");
            puts(A[I].clave);
            printf("Superficie cubierta: %.2f\n", A[I].scu);
            printf("Superficie terreno: %.2f\n", A[I].ste);
            printf("Caracter�sticas: ");
            puts(A[I].car);
            printf("Calle: ");
            puts(A[I].ubi.calle);
            printf("Colonia: ");
            puts(A[I].ubi.colo);
            printf("Precio: %.2f\n", A[I].precio);
        }
    }
}
