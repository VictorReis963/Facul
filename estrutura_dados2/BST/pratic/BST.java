package BST.pratic;

public class BST{
    private Node raiz;

    public BST(){
        this.raiz=null;
    }
    public boolean busca(int valor){
        return buscaRec(this.raiz, valor);
        
    }

    public boolean buscaRec(Node atual, int valor){
        if (atual == null)return false;

        if(atual.valor == valor) return true;

        if (valor<atual.valor){
            return buscaRec(atual.left, valor);
        }else{
            return buscaRec(atual.right, valor);
        }

    }

    public void insert(int valor){
        this.raiz=insertRec(raiz, valor);
        

    }

    public Node insertRec(Node atual, int valor){
        if (atual==null){
            Node Node = new Node(valor);
            return Node;
        }
        if(valor< atual.valor){
            atual.left= insertRec(atual, valor);
        }
        else if(valor >atual.valor){
            atual.left = insertRec(atual.right, valor);
        }

        return atual;


    }

}