package BST;

public class Node {
    String data;
    Node parent;
    Node left;
    Node right;

    public Node(String data) {
        this.data = data;
        this.parent = null;
        this.left = null;
        this.right = null;
    }
}