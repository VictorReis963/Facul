package BST;

public class BST extends BinaryTree {

    public BST() {
        super();
    }

    // SEARCH 
    public Node search(String data) {
        return searchRec(root, data);
    }

    private Node searchRec(Node atual, String data) {
        if (atual == null || atual.data.equals(data)) {
            return atual;
        }
        if (data.compareTo(atual.data) < 0) {
            return searchRec(atual.left, data);
        }
        return searchRec(atual.right, data);
    }

    // --- INSERT ---
    public void insert(String data) {
        root = insertRec(root, null, data);
    }

    private Node insertRec(Node atual, Node pai, String data) {
        if (atual == null) {
            Node novo = new Node(data);
            novo.parent = pai;
            return novo;
        }

        int comp = data.compareTo(atual.data);
        if (comp < 0) {
            atual.left = insertRec(atual.left, atual, data);
        } else if (comp > 0) {
            atual.right = insertRec(atual.right, atual, data);
        }
        // Se comp == 0 (duplicado), nao faz nada
        return atual;
    }

    // --- REMOVE ---
    public void remove(String data) {
        root = removeRec(root, data);
    }

    private Node removeRec(Node atual, String data) {
        if (atual == null) return null;

        int comp = data.compareTo(atual.data);
        if (comp < 0) {
            atual.left = removeRec(atual.left, data);
        } else if (comp > 0) {
            atual.right = removeRec(atual.right, data);
        } else {
            // Achou o n a, remover!
            // Caso 1e2; sem filho esquerdo
            if (atual.left == null) {
                if (atual.right != null) atual.right.parent = atual.parent;
                return atual.right;
            }
            // Caso 2: sem filho direito
            if (atual.right == null) {
                if (atual.left != null) atual.left.parent = atual.parent;
                return atual.left;
            }

            // Caso 3: dois filhos (pega o predecessor)
            Node pred = findMaxRec(atual.left);
            atual.data = pred.data;
            atual.left = removeRec(atual.left, pred.data);
        }
        return atual;
    }

    // --- FIND MIN & MAX ---
    public Node findMin() {
        return findMinRec(root);
    }

    private Node findMinRec(Node atual) {
        if (atual == null) return null;
        while (atual.left != null) {
            atual = atual.left;
        }
        return atual;
    }

    public Node findMax() {
        return findMaxRec(root);
    }

    private Node findMaxRec(Node atual) {
        if (atual == null) return null;
        while (atual.right != null) {
            atual = atual.right;
        }
        return atual;
    }

    // --- PREDE CESSOR E SUCESSOR ---
    public Node findPredecessor(String data) {
        Node no = search(data);
        if (no == null) return null;

        if (no.left != null) {
            return findMaxRec(no.left);
        }

        Node p = no.parent;
        while (p != null && no == p.left) {
            no = p;
            p = p.parent;
        }
        return p;
    }

    public Node findSuccessor(String data) {
        Node no = search(data);
        if (no == null) return null;

        if (no.right != null) {
            return findMinRec(no.right);
        }

        Node p = no.parent;
        while (p != null && no == p.right) {
            no = p;
            p = p.parent;
        }
        return p;
    }


    public void clear() {
        this.root = null;
    }
}