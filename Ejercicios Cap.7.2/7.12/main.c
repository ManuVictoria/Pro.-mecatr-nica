#include <stdio.h>
#include <ctype.h>

void quitarAcentos(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        switch (cadena[i]) {
            case '�':
            case '�':
                cadena[i] = 'a';
                break;
            case '�':
            case '�':
                cadena[i] = 'e';
                break;
            case '�':
            case '�':
                cadena[i] = 'i';
                break;
            case '�':
            case '�':
                cadena[i] = 'o';
                break;
            case '�':
            case '�':
                cadena[i] = 'u';
                break;
            case '�':
            case '�':
                cadena[i] = 'n';
                break;
            default:
                break;
        }
        i++;
    }
}

int main(void) {
    char cad[50];
    int i = 0, mi = 0, ma = 0;
    printf("\nIngrese la cadena de caracteres (m�ximo 50 caracteres): ");
    gets(cad);

    quitarAcentos(cad);

    while (cad[i] != '\0') {
        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }
    printf("\n\nN�mero de letras min�sculas: %d", mi);
    printf("\nN�mero de letras may�sculas: %d", ma);

    return 0;
}
