import java.util.Scanner;

public class Ex4_NumerosInversos {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] numeros = new int[10];
        
        // lendo 10 numeros inteiros
        for (int i = 0; i < 10; i++) {
            System.out.print("digite o " + (i + 1) + " numero inteiro: ");
            while (!scanner.hasNextInt()) { //impede entradas invalidas
                System.out.println("entrada invalida. por favor, digite um numero inteiro.");
                scanner.next(); // limpa a entrada invalida
            }
            numeros[i] = scanner.nextInt();
        }
        
        //exibindo os numeros em ordem inversa
        System.out.println("numeros na ordem inversa:");
        for (int i = 9; i >= 0; i--) {
            System.out.println(numeros[i]);
        }
        
        scanner.close();
    }
}
