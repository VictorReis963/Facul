import java.util.Scanner;

public class VerificaLetra {
    public static void main(String[] args) {
        //cria um objeto para entrada do usuario
        Scanner scanner = new Scanner(System.in);
        
        //solicita a letra
        System.out.print("Digite uma letra: ");
        String input = scanner.next();
        
        //verificando se a entrada e uma unica letra
        if (input.length() == 1 && Character.isLetter(input.charAt(0))) {
            char letra = Character.toLowerCase(input.charAt(0));
            
            //verificando se e uma vogal ou consoante
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
                System.out.println("A letra " + letra + " é uma vogal.");
            } else {
                System.out.println("A letra " + letra + " é uma consoante.");
            }
        } else { //aviso caso seja um simbolo ou numero
            System.out.println("Erro: Por favor, insira apenas uma única letra e não símbolos ou números.");
        }
        
        
        scanner.close();
    }
}