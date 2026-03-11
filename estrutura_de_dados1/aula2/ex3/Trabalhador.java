package aula2.ex3;
public class Trabalhador {

    private String cpf;
    private String nome;
    private int idade;
    private char sexo;
    private String endereco;
    private float salario;

    public Trabalhador(String nome, float salario, String cpf, int idade, char sexo, String endereco) {
        this.nome = nome;
        this.salario = salario;
        this.cpf = cpf;
        this.idade = idade;
        this.sexo = sexo;
        this.endereco = endereco;
    }

    // GETTERS E SETTERS
    public String getCpf() { return cpf; }
    public void setCpf(String cpf) { this.cpf = cpf; }

    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public int getIdade() { return idade; }
    public void setIdade(int idade) { this.idade = idade; }

    public char getSexo() { return sexo; }
    public void setSexo(char sexo) { this.sexo = sexo; }

    public String getEndereco() { return endereco; }
    public void setEndereco(String endereco) { this.endereco = endereco; }

    public float getSalario() { return salario; }
    public void setSalario(float salario) { this.salario = salario; }

    public float calculaSalarioAnual() {
        return salario * 12;
    }

    public void mostra() {
        System.out.println("Nome: " + nome);
        System.out.println("CPF: " + cpf);
        System.out.println("Idade: " + idade);
        System.out.println("Sexo: " + sexo);
        System.out.println("Endereço: " + endereco);
        System.out.println("Salário: " + salario);
        System.out.println("Salário Anual: " + calculaSalarioAnual());
        System.out.println("------------------------");
    }
}