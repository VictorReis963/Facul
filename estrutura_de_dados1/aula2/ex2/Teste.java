package aula2.ex2;

import java.util.Scanner;

public class Teste {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println(" diga o tamanho do raio\n");
        float raio =  scanner.nextFloat();

        Circulo x = new Circulo();

        x.setRaio(raio);
        x.new Metodos(). mostrarDados();

        scanner.close();
    }
    
}