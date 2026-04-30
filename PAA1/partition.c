#include <stdio.h>

int part(int v[], int tam){
    int v1[100], v2[100];
    int x = 0, y = 0;
    int pivot = v[tam - 1];
 
    //atribui menores e maiores que o pivô
    for (int i = 0; i < tam - 1; i++){
        if (v[i] < pivot){
            v1[x++] = v[i];
        } else {
            v2[y++] = v[i];
        }
    }

    // copia menores
    int k = 0;
    for (int i = 0; i < x; i++){
        v[k++] = v1[i];
    }

    // coloca pivot
    v[k++] = pivot;

    // copia maiores
    for (int i = 0; i < y; i++){
        v[k++] = v2[i];
    }

    return x; // posição do pivô
}

int main(){
    int v[] = {5,6,2,12,0,10,7,11,6,5,2,7,70,1,11,10};
    int tam = sizeof(v)/sizeof(v[0]);

    //exibe vetor antes da partição
    for (int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }

    //chama a função principal de partição
    int pos = part(v, tam); 
    

    printf("\nPivot na posicao: %d\n", pos);
    //exibe vetor depois da partição
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}