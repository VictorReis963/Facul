public class Node <T>{
    
    private T data;
    private Node<T> direita;
    private Node<T> esquerda;


    //contrutor
    public Node(T valor){
        this.data=valor;
        direita=null;
        esquerda=null;
    }

    public T getData(){
        return data;
    }

    public void setData(T valor){
        this.data=valor;
    }
    
    public Node<T> getDireita(){
        return direita;
    }
    public void setDireita(Node <T> valor){
        this.direita = valor;
        
    }
    public Node<T> getEsquerda(){
        return esquerda;
    }
    public void setEsquerda(Node<T> valor){
        this.esquerda = valor;
        
    }
}
