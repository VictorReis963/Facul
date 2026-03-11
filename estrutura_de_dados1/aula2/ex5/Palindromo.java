package aula2.ex5;

public class Palindromo {

    private String texto;

    // Construtor sem parâmetro
    public Palindromo() {
        this.texto = "";
    }

    // Construtor com parâmetro
    public Palindromo(String texto) {
        if (texto == null) {
            this.texto = "";
        } else {
            this.texto = texto;
        }
    }

    // Getter
    public String getTexto() {
        return texto;
    }

    // Setter com validação (não permite null)
    public void setTexto(String texto) {
        if (texto == null) {
            throw new IllegalArgumentException("O texto não pode ser null.");
        }
        this.texto = texto;
    }

    // Método verificar()
    public boolean verificar() {

        // Remove espaços e deixa tudo minúsculo
        String textoTratado = texto.trim().replaceAll("\\s+", "").toLowerCase();

        int inicio = 0;
        int fim = textoTratado.length() - 1;

        while (inicio < fim) {

            if (textoTratado.charAt(inicio) != textoTratado.charAt(fim)) {
                return false;
            }

            inicio++;
            fim--;
        }

        return true;
    }
}