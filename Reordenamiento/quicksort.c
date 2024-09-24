#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void class_rap(int datos[], int inf, int sup){
    int i, j, tmp, elem_de_divi;
    if(sup > inf){
        elem_de_divi = datos[sup];
        i = inf - 1;
        j = sup;
        while (1){
            while(datos[++i] < elem_de_divi);
            while(datos[--j] > elem_de_divi);
            if(i >= j)
                break;
            tmp = datos[i];
            datos[i] = datos[j];
            datos[j] = tmp;
        }
        tmp = datos[i];
        datos[i] = datos[sup];
        datos[sup] = tmp;

        class_rap(datos, inf, i - 1);
        class_rap(datos, i + 1, sup);        
    }
}

// Función para generar números aleatorios en el arreglo
void generar_numeros_aleatorios(int datos[], int n, int rango_min, int rango_max) {
    // Usa la semilla basada en el tiempo para generar números aleatorios
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        datos[i] = rango_min + rand() % (rango_max - rango_min + 1);
    }
}

int main() {
    int datos[20]; // Arreglo de tamaño 20
    int n = sizeof(datos) / sizeof(datos[0]);

    // Genera 20 números aleatorios entre 1 y 100
    generar_numeros_aleatorios(datos, n, 1, 100);

    printf("Arreglo original (números aleatorios):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    // Llama a la función de ordenamiento rápido
    class_rap(datos, 0, n - 1);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    getch();
    return 0;
}
