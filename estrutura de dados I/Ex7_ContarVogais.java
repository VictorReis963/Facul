import java.util.Scanner;

public class Ex7_ContarVogais { // função para contra vogais
    //metodo que conta a quantidade de vogais em uma string
    public static int contarVogais(String texto) {
        int contador = 0;
        texto = texto.toLowerCase(); //diminui as letras maiusculas
        for (char c : texto.toCharArray()) { // converte a string em um array
            if ("aeiou".indexOf(c) != -1) {
                contador++;
            }
        }
        return contador;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //testando contarVogais()
        System.out.print("Digite uma string: ");
        String texto = scanner.nextLine();
        System.out.println("Quantidade de vogais: " + contarVogais(texto));

        scanner.close();
    }
}
