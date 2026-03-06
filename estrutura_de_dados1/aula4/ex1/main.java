import java.util.Scanner;


public class main{
    public static void main(String [] args){
        System.out.println("digite a palavra para verificar se ela é palindromo/n");

        Scanner s = new Scanner(System.in);
        String texto= s.nextLine();
        Palindromo.verifica(texto);
        
        s.close();
    }
}