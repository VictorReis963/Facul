
public class CircularLinkedList{
    private Node head = Null;
    private Node tail = NULL;

    public void add(int data){
        Node no= new Node (data);
        
        if (head == null){
            head=no;
            tail=no;
            no.next=head;
        }
        else{   
            tail=no.next; //o no anterior se conecta ao novo

            tail=newNode; //agora o novo no recebe o tail

            tail.next= head; // agora conecta o tail no head para completar o circulo
    }
    }
    public void display() {
        Node current = head;
        if (head == null) {
            System.out.println("A lista está vazia.");
            return;
        }
        System.out.println("Nós da lista circular: ");
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head); // Para quando voltar ao início
        System.out.println();
    }

    public void addPos(int data, int pos){
        Node newNode = new Node(data);
        if (pos==0){
            tail.next=newNode; //o tail se conecta ao novo no

            newNode.next=head; //o novo no se conecta ao head
            head=newNode; //o head recebe o novo no
            
        }
        else{
            Node P_anda =head;
            Node P_anterior = null;
            int cont=0;
            while (cont<pos){
                p_anterior = p_anda;
                p_anda = p_anda.next;
                cont++;
            }
            
        }
    }
}