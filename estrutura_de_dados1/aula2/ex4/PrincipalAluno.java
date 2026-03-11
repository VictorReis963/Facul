package aula2.ex4;

public class PrincipalAluno {

    public static void main(String[] args) {

        Aluno aluno1 = new Aluno("123", "Carlos", 7, 8, 6, 9);
        Aluno aluno2 = new Aluno("456", "Ana", 5, 4, 6, 5);

        aluno1.mostraDados();
        aluno2.mostraDados();
    }
}