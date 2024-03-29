#include <stdio.h>
#include <unistd.h>

/*prototipos*/

int contarCaracteres();

int main() {
    printf("Ingresa tu nombre:\n");
    int cantidadCaracteres = contarCaracteres();
    printf("La cantidad de caracteres ingresados es: %d\n", cantidadCaracteres);
    printf ("El arbol asignado es: %d", cantidadCaracteres%2);

    return 0;
}


int contarCaracteres() {
    int c = getchar();
    
    if (c == EOF || c == '\n') {
        return 0;
    } 
    else {
        return 1 + contarCaracteres();
    }
}
