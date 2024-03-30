#include <stdio.h>
#include <unistd.h>

int contarCaracteres() {
    int c = getchar();
    
    if (c == EOF || c == '\n') {
        return 0;
    } 
    else {
        return 1 + contarCaracteres();
    }
}

void imprimir_numeros(int inicio, int fin, int incremento, int proceso_id) {
    printf("[Proceso-%d] ", proceso_id);
    for (int i = inicio; i <= fin; i += incremento) {
        printf("%d ", i);
    }
    printf("\n");
}

void fibonacci(int n, int proceso_id) {
    int primero = 0, segundo = 1, siguiente;
    
    printf("[Proceso-%d] Serie Fibonacci: ", proceso_id);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", primero);
        siguiente = primero + segundo;
        primero = segundo;
        segundo = siguiente;
    }
    printf("\n");
}

void sumar(int a, int b, int proceso_id) {
    printf("[Proceso-%d] Suma: %d + %d = %d\n", proceso_id, a, b, a + b);
}

void restar(int a, int b, int proceso_id) {
    printf("[Proceso-%d] Resta: %d - %d = %d\n", proceso_id, a, b, a - b);
}

void multiplicar(int a, int b, int proceso_id) {
    printf("[Proceso-%d] Multiplicación: %d * %d = %d\n", proceso_id, a, b, a * b);
}

void dividir(int a, int b, int proceso_id) {
    if (b == 0) {
        printf("[Proceso-%d] Error: División por cero\n", proceso_id);
        return;
    }
    printf("[Proceso-%d] División: %d / %d = %.2f\n", proceso_id, a, b, (float)a / b);
}


void main (){

    printf("Ingresa tu nombre: ");
    int cantidadCaracteres = contarCaracteres();
    printf("La cantidad de caracteres ingresados es: %d\n", cantidadCaracteres);
    printf ("El arbol asignado es: %d", cantidadCaracteres%2);


    pid_t pid;

    /*Procesos*/
    /*Primer proceso*/
    pid = fork();

    if(pid<0){
        fprintf(stderr, "Error al crear el proceso\n");
        return 1;
    }else if (pid == 0){
        imprimir_numeros(1,50,2,1);
    }
    /*Segundo proceso*/
    else{
        pid = fork();

    if(pid<0){
        fprintf(stderr, "Error al crear el proceso\n");
        return 1;
    }else if (pid == 0){
        fibonacci(10,2);
    }
    }
    /*Tercer proceso*/
    else{
        pid = fork();

    if(pid<0){
        fprintf(stderr, "Error al crear el proceso\n");
        return 1;
    }else if (pid == 0){
        sumar(10,5,3);
    }
    }
    /*Cuarto proceso*/
    else{
        pid = fork();

    if(pid<0){
        fprintf(stderr, "Error al crear el proceso\n");
        return 1;
    }else if (pid == 0){
        restar(10,5,4);
    }
    }
    /*Quinto proceso*/
    else{
        pid = fork();

    if(pid<0){
        fprintf(stderr, "Error al crear el proceso\n");
        return 1;
    }else if (pid == 0){
        multiplicar(10,5,5);
    }
    }
    /*Sexto proceso*/
    else{
        pid = fork();

    if(pid<0){
        fprintf(stderr, "Error al crear el proceso\n");
        return 1;
    }else if (pid == 0){
        dividir(10,5,6);
    }
    }
}
