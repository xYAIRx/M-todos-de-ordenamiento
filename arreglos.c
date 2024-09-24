#include <stdio.h>
#include <conio.h>
/*int main(){
    int numeros[5]={11,32,23,84,15};
    printf("Valor inicial en la posicion 4: %d \n",numeros[3]);
    numeros[3]=55;
    printf("Valor cambiado en la posiscion 4: %d",numeros[3]);
    getch();
    return 0;
}*/
int main(){
    int numeros[5]={11,32,23,84,15};
    int calificaciones[5];
    /*for(int i = 0; i < sizeof(numeros); i+1){
        printf("Calificacion %d",i);
        scanf("%d", &calificaciones[i]);
    }*/
   for(int i = 0; i < sizeof(numeros); i++){
        printf("Calificacion %d: %d \n",i+1,calificaciones[i]);
    }
    return 0;
}