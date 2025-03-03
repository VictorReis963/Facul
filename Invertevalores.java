import java.util.Scanner;

public class Invertevalores {
    public static void main(String[] args) {
        // Cria um objeto Scanner para entrada do usuário
        Scanner scanner = new Scanner(System.in);
        
        // Solicita o primeiro valor
        System.out.print("Digite o primeiro valor: ");
        int valor1 = scanner.nextInt();
        
        // Solicita o segundo valor
        System.out.print("Digite o segundo valor: ");
        int valor2 = scanner.nextInt();
        
         // Invertendo os valores
         int temp = valor1;
         valor1 = valor2;
         valor2 = temp;
        
        // Exibindo o resultado
        System.out.println("o conteúdo de valor 1 e valor 2 após a troca: " + valor1 +"-" +valor2);
        
        // Fechando o scanner
        scanner.close();
    }
}