

#include <stdio.h>

int swap(int *a, int *b){
    int temp=*a;
    *a= *b;
    *b= temp;
    
}
// a função do partition e reorganizar o vetor separando os elementos dentro
//do proprio vetor em menores e maiores que o pivot
int partition(int v[], int inicio,int fim){
   int pivo= v[fim]; // pivo escolhido = ultimo elemento (tem vario tipos de escolha)
   int i= inicio-1;//posição dos menores
   

   
   for(int j=inicio; j<fim; j++){
       if (v[j] <= pivo){ //se V[j] for menor que pivot vai para equerda
           i++;
           swap( &v[j], &v[i]); // troca elementos
           
       }
   }
   swap(&v[i+1],&v[fim]);
   
   return (i+1);
   
}

void quick(int v[],int inicio,int fim){
    
    if (inicio<fim) {
        
        int l= partition(v,inicio,fim);
        
        quick(v,inicio,l-1);
        quick(v,l+1,fim);
    }
    
    
}

    

int main()
{
    int v[]={4,2,9,1,5,10,11,1,9,6};
    int t= sizeof(v)/sizeof(v[0]);
    quick (v,0,t-1);
    
    
    
    for (int i=0;i<=t-1;i++){
        printf("%d,",v[i]);
    }

    return 0;
}