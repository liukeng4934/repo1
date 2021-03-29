public class DuLNode {
    public int data;
    public DuLNode next;
    public DuLNode prior;

    public DuLNode(int data) {
        this.data = data;
    }

    DuLNode(){

    }

    DuLNode(int data, DuLNode next, DuLNode prior){
        this.data=data;
        this.next=next;
        this.prior=prior;
    }
}
