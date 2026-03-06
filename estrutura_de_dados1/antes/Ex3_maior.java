import java.util.Scanner;

public class Ex3_maior {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // inicia as varivais como o infinito oposto
        double maior = Double.NEGATIVE_INFINITY;
        double menor = Double.POSITIVE_INFINITY;
        
        // lendo 10 numeros
        for (int i = 1; i <= 10; i++) {
            System.out.print("digite o " + i + " numero (use ponto para decimais): ");
            double numero = scanner.nextDouble();
            
            // verificando maior e menor numero
            if (numero > maior) {
                maior = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
        }
        
        // exibindo os resultados
        System.out.println("o maior numero digitado foi: " + maior);
        System.out.println("o menor numero digitado foi: " + menor);
        
        scanner.close();
    }
}
