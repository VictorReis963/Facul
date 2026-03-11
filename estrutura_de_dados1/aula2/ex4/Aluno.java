package aula2.ex4;

public class Aluno {

    private String rgm;
    private String nome;
    private char sexo;
    private float notaA;
    private float notaB;
    private float notaC;
    private float notaD;

    public Aluno() {
    }

    public Aluno(String rgm, String nome) {
        this.rgm = rgm;
        this.nome = nome;
    }

    public Aluno(String rgm, String nome, float notaA, float notaB, float notaC, float notaD) {
        this.rgm = rgm;
        this.nome = nome;
        this.notaA = notaA;
        this.notaB = notaB;
        this.notaC = notaC;
        this.notaD = notaD;
    }

    public float calculaMedia() {
        return (notaA + notaB + notaC + notaD) / 4;
    }

    public boolean avaliaSituacao() {
        return calculaMedia() >= 6;
    }

    public void mostraDados() {
        System.out.println("RGM: " + rgm);
        System.out.println("Nome: " + nome);
        System.out.println("sexo"+sexo);
        System.out.println("Média: " + calculaMedia());

        if (avaliaSituacao())
            System.out.println("Situação: Aprovado");
        else
            System.out.println("Situação: Reprovado");

        System.out.println("---------------------");
    }
}