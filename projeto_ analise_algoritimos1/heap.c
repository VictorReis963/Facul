#include <stdio.h>

void heapify(int v[], int n, int i){
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if(esq < n && v[esq] > v[maior])
        maior = esq;

    if(dir < n && v[dir] > v[maior])
        maior = dir;

    if(maior != i){
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;

        heapify(v, n, maior);
    }
}

void heapSort(int v[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for(int i = n-1; i >= 0; i--){
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heapify(v, i, 0);
    }
}

int main(){
    int v[] = {4, 10, 3, 5, 1};
    int n = 5;

    heapSort(v, n);

    for(int i=0;i<n;i++){
        printf("%d ", v[i]);
    }
}
