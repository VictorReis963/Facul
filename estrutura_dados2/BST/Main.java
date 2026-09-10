/*
 * Victor Reis da Silva  RA: 10420297
 * REFERENCIAS CONSULTADAS:
 * - Aulas da disciplina de Estrutura de Dados II e outras anotações anteriores
 * - Documentacao Oficial Java (Oracle)
 * - Stack overflow
 */

public class Main {
    public static void main(String[] args) {
        BST arvore = new BST();

        System.out.println("--- Inserindo elementos ---");
        arvore.insert("M");
        arvore.insert("F");
        arvore.insert("S");
        arvore.insert("B");
        arvore.insert("K");
        arvore.insert("F"); // Duplicado de teste

        System.out.println("\n--- Percurso em Ordem ---");
        imprimirEmOrdem(arvore.root, arvore.root);

        System.out.println("\n--- Testando Buscas ---");
        Node achado = arvore.search("K");
        if (achado != null) {
            System.out.println("Encontrado: " + achado.data);
        } else {
            System.out.println("Nao encontrado!");
        }

        System.out.println("\n--- Min e Max ---");
        Node min = arvore.findMin();
        Node max = arvore.findMax();
        System.out.println("Menor elemento: " + (min != null ? min.data : "null"));
        System.out.println("Maior elemento: " + (max != null ? max.data : "null"));

        System.out.println("\n--- Remoções ---");
        System.out.println("Removendo 'B' (folha)...");
        arvore.remove("B");
        imprimirEmOrdem(arvore.root, arvore.root);

        System.out.println("\nLimpando a arvore...");
        arvore.clear();
        System.out.println("Min apos clear: " + arvore.findMin());
    }

    // Exibe os detalhes de cada no 
    public static void imprimirEmOrdem(Node no, Node raiz) {
        if (no != null) {
            imprimirEmOrdem(no.left, raiz);

            String paiStr = (no.parent != null) ? no.parent.data : "null";
            String esqStr = (no.left != null) ? no.left.data : "null";
            String dirStr = (no.right != null) ? no.right.data : "null";
            boolean ehFolha = (no.left == null && no.right == null);

            System.out.println("No: " + no.data + " | Pai: " + paiStr + 
                               " | Esq: " + esqStr +  " | Dir: " + dirStr + 
                               " | Eh Raiz: " + (no == raiz) +  " | Eh Folha: " + ehFolha);

            imprimirEmOrdem(no.right, raiz);
        }
    }
}