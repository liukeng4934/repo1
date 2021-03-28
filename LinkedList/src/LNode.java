//创建一个链表的类
public class LNode {
    public int data;
    public LNode next;
    LNode(){
    }
    LNode(int data){
        this.data=data;
    }
    LNode(int data,LNode next){
        this.data=data;
        this.next=next;
    }
}

