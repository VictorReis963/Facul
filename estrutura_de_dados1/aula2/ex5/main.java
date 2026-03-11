package aula2.ex5;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Digite um texto: ");
        String entrada = sc.nextLine();

        Palindromo p = new Palindromo();
        p.setTexto(entrada);

        if (p.verificar()) {
            System.out.println("É palíndromo.");
        } else {
            System.out.println("Não é palíndromo.");
        }

        sc.close();
    }
}