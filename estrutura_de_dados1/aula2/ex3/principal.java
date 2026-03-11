package aula2.ex3;
import java.util.Scanner;

public class Principal {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        final int MAX_TRABALHADOR = 50;

        Trabalhador[] trabalhadores = new Trabalhador[MAX_TRABALHADOR];

        System.out.print("Quantos trabalhadores deseja cadastrar? ");
        int n = sc.nextInt();

        float somaSalario = 0;

        for (int i = 0; i < n; i++) {

            sc.nextLine();

            System.out.println("\nTrabalhador " + (i + 1));

            System.out.print("Nome: ");
            String nome = sc.nextLine();

            System.out.print("Salário: ");
            float salario = sc.nextFloat();

            sc.nextLine();

            System.out.print("CPF: ");
            String cpf = sc.nextLine();

            System.out.print("Idade: ");
            int idade = sc.nextInt();

            System.out.print("Sexo (M/F): ");
            char sexo = sc.next().charAt(0);

            sc.nextLine();

            System.out.print("Endereço: ");
            String endereco = sc.nextLine();

            trabalhadores[i] = new Trabalhador(nome, salario, cpf, idade, sexo, endereco);

            somaSalario += salario;
        }

        float media = somaSalario / n;
        System.out.println("\nMédia Salarial: " + media);

        Trabalhador maiorSalarioHomem = null;
        Trabalhador menorSalarioMulher = null;

        float somaHomens30 = 0;
        int contHomens30 = 0;

        for (int i = 0; i < n; i++) {

            Trabalhador t = trabalhadores[i];

            if (t.getSexo() == 'M' || t.getSexo() == 'm') {

                if (t.getSalario() > media) {
                    System.out.println("\nHomem acima da média:");
                    t.mostra();
                }

                if (t.getIdade() > 30) {
                    somaHomens30 += t.getSalario();
                    contHomens30++;
                }

                if (maiorSalarioHomem == null || 
                    t.getSalario() > maiorSalarioHomem.getSalario()) {
                    maiorSalarioHomem = t;
                }
            }

            if (t.getSexo() == 'F' || t.getSexo() == 'f') {

                if (menorSalarioMulher == null || 
                    t.getSalario() < menorSalarioMulher.getSalario()) {
                    menorSalarioMulher = t;
                }
            }
        }

        if (contHomens30 > 0) {
            System.out.println("Média homens > 30 anos: " + (somaHomens30 / contHomens30));
        }

        System.out.println("\nHomem com maior salário:");
        if (maiorSalarioHomem != null) maiorSalarioHomem.mostra();

        System.out.println("\nMulher com menor salário:");
        if (menorSalarioMulher != null) menorSalarioMulher.mostra();

        sc.close();
    }
}