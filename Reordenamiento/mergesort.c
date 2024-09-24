#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de las funciones
void combina(int destino[], int fuente[], int inf, int medio, int sup);
void pasa_comb(int destino[], int fuente[], int tamano, int lon);
void class_combi(int datos[], int tamano);

// Función para combinar dos subarreglos ordenados
void combina(int destino[], int fuente[], int inf, int medio, int sup) {
    int i = inf, j = medio + 1, k = inf;

    while (i <= medio && j < sup) {
        if (fuente[i] <= fuente[j]) {
            destino[k++] = fuente[i++];
        } else {
            destino[k++] = fuente[j++];
        }
    }

    while (i <= medio) {
        destino[k++] = fuente[i++];
    }

    while (j < sup) {
        destino[k++] = fuente[j++];
    }
}

// Función para pasar combinaciones entre dos arreglos
void pasa_comb(int destino[], int fuente[], int tamano, int lon) {
    int inf = 0;

    while (inf < tamano - 2 * lon) {
        combina(destino, fuente, inf, inf + lon - 1, inf + 2 * lon);
        inf += 2 * lon;
    }

    if (inf + lon < tamano) {
        combina(destino, fuente, inf, inf + lon - 1, tamano);
    } else {
        while (inf < tamano) {
            destino[inf] = fuente[inf]; // Corrección: asignar valor en lugar de sumar
            inf++;
        }
    }
}

// Función para ordenar usando el algoritmo de mergesort por combinación
void class_combi(int datos[], int tamano) {
    int tmp[2048]; // Se podría ajustar según el tamaño máximo esperado
    int lon = 1;

    while (lon < tamano) {
        pasa_comb(tmp, datos, tamano, lon);
        lon *= 2;
        pasa_comb(datos, tmp, tamano, lon);
        lon *= 2; // Corrección: Multiplicar por 2 una sola vez en cada iteración
    }
}

int main() {
    int datos[20];
    int n = sizeof(datos) / sizeof(datos[0]);

    // Semilla para generar números aleatorios
    srand(time(NULL));

    // Generar 20 números aleatorios entre 1 y 100
    for (int i = 0; i < n; i++) {
        datos[i] = rand() % 100 + 1;
    }

    // Imprimir el arreglo original
    printf("Arreglo original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    // Llamar a la función de ordenamiento por combinación
    class_combi(datos, n);

    // Imprimir el arreglo ordenado
    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    return 0;
}