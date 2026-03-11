public class Palindromo{
    String arr[];
    String pilha[];
    

    public void verifica(String texto){
        String arr[]= texto.split("");



        
        for (int i=0; i<arr.length/2; i++){
            pilha[i]=arr[i];
        }

        for (int i=0;i<arr.length;i++){
            if(pilha[i]!=arr[i]){
                System.out.println("é palindromo ");
            }
            else{System.out.println("não é palindromo");}

                
            }
        }
        
        
    }

    
        

}