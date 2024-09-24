#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numerosRandom(int arr[], int n) {
    srand(time(0)); // Inicializa la semilla del generador de números aleatorios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Genera números aleatorios entre 0 y 99
    }
}

void bubbleSort(int arr[], int n){
    for (int i=0; i< n-1; i++){
        for (int j=0; j< n-i-1; j++){
            if(arr[j]> arr[j+1]){
                // Intercambiamos arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[30]; // Definimos un arreglo con 30 elementos
    int n = sizeof(arr)/sizeof(arr[0]);

    numerosRandom(arr, n); // Llenamos el arreglo con números aleatorios
    printf("Arreglo original: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n); // Ordenamos el arreglo usando bubble sort
    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    getch();
    return 0;
}
