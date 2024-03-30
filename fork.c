#include <stdio.h>
#include <unistd.h>

// Función para contar caracteres ingresados por el usuario
int contarCaracteres() {
    int c;
    int count = 0;

    // Itera hasta que se alcance el final del archivo (EOF) o se presione Enter (\n)
    while ((c = getchar()) != EOF && c != '\n') {
        count++; // Incrementa el contador de caracteres
    }

    return count;
}

// Función para imprimir una serie de números con un incremento dado
void imprimir_numeros(int inicio, int fin, int incremento, int proceso_id) {
    printf("[Proceso-%d] ", proceso_id);

    // Imprime los números en el rango especificado con el incremento dado
    for (int i = inicio; i <= fin; i += incremento) {
        printf("%d ", i);
    }

    printf("\n");
}

// Función para generar la serie de Fibonacci hasta un término dado
void fibonacci(int n, int proceso_id) {
    int primero = 0, segundo = 1, siguiente;
    
    printf("[Proceso-%d] Serie Fibonacci: ", proceso_id);
    
    // Genera y muestra los términos de la serie de Fibonacci
    for (int i = 0; i < n; i++) {
        printf("%d ", primero);
        siguiente = primero + segundo;
        primero = segundo;
        segundo = siguiente;
    }

    printf("\n");
}

// Función para sumar dos números
void sumar(int a, int b, int proceso_id) {
    printf("[Proceso-%d] Suma: %d + %d = %d\n", proceso_id, a, b, a + b);
}

// Función para restar dos números
void restar(int a, int b, int proceso_id) {
    printf("[Proceso-%d] Resta: %d - %d = %d\n", proceso_id, a, b, a - b);
}

// Función para multiplicar dos números
void multiplicar(int a, int b, int proceso_id) {
    printf("[Proceso-%d] Multiplicación: %d * %d = %d\n", proceso_id, a, b, a * b);
}

// Función para dividir dos números
void dividir(int a, int b, int proceso_id) {
    if (b == 0) {
        printf("[Proceso-%d] Error: División por cero\n", proceso_id);
        return;
    }
    printf("[Proceso-%d] División: %d / %d = %.2f\n", proceso_id, a, b, (float)a / b);
}

int main() {
    printf("Ingresa tu nombre: ");
    int cantidadCaracteres = contarCaracteres();
    printf("La cantidad de caracteres ingresados es: %d\n", cantidadCaracteres);
    printf ("El arbol asignado es: %d\n", cantidadCaracteres % 2);

    pid_t pid;

    // Creación de procesos secuenciales
    for (int proceso_id = 1; proceso_id <= 6; proceso_id++) {
        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Error al crear el proceso\n");
            return 1;
        } else if (pid == 0) {
            // Dependiendo del ID del proceso, llama a la función correspondiente
            switch (proceso_id) {
                case 1:
                    imprimir_numeros(1, 50, 2, proceso_id);
                    break;
                case 2:
                    fibonacci(10, proceso_id);
                    break;
                case 3:
                    sumar(10, 5, proceso_id);
                    break;
                case 4:
                    restar(10, 5, proceso_id);
                    break;
                case 5:
                    multiplicar(10, 5, proceso_id);
                    break;
                case 6:
                    dividir(10, 5, proceso_id);
                    break;
                default:
                    break;
            }
            return 0; // Termina el proceso hijo después de ejecutar su tarea
        }
    }

    return 0; // Termina el proceso padre
}
