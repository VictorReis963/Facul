#include <stdio.h>

int idioma(){
  
}

int transforma(){

    char str[] = "hello";
    char array[100];
    int i = 0;

    while (str[i] != '\0') {

      array[i] = str[i];

      i++;

    }

    array[i] = '\0';

}





int main(){

    char frase[100];

   

    print("digite a frase desejada");



    fgets(frase,50, stdin);

    transforma(frase);

    idioma(frase);

 



}