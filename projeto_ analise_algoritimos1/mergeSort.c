// Função para trocar dois elementos usando ponteiros
void swap(int *a, int *b) {
    int temp = *a;   // guarda o valor de *a temporariamente
    *a = *b;         // coloca o valor de *b em *a
    *b = temp;       // coloca o valor salvo em *b
}

// Função que "mescla" duas partes ordenadas do vetor
void merge(int arr[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;// tamanho da parte esquerda
    int n2 = direita - meio;

    
    int L[n1];// vetores temporários esquerda e direita
    int R[n2];

    
    for(int i = 0; i < n1; i++) { // copia os elementos da esquerda para L[]
        L[i] = arr[esquerda + i];
    }

    for(int j = 0; j < n2; j++) {// copia os elementos da direita para R[]
        R[j] = arr[meio + 1 + j];
    }
    // índices de controle
    int i = 0;        // índice de L[]
    int j = 0;        // índice de R[]
    int k = esquerda; // índice do vetor original arr[]

    // enquanto tiver elementos nas duas metades
    // comparamos e colocamos o menor no arr
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while(i < n1) { // se ainda sobraram elementos em L[], copia
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while(j < n2) { // se ainda sobraram elementos em R[], copia
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort (recursiva)
void mergeSort(int arr[], int esquerda, int direita) {

    if(esquerda < direita) {// condição de parada: vetor com 1 ou 0 elementos
        int meio = (esquerda + direita) / 2;// encontra o meio do vetor
        
        mergeSort(arr, esquerda, meio);
        // ordena a metade direita
        mergeSort(arr, meio + 1, direita);
        // junta as duas metades ordenadas
        merge(arr, esquerda, meio, direita);
    }
}
