public class StackNode {
    public int data;//存放元素

    public StackNode next;//下个指针

    public StackNode(){}

    public StackNode(int data,StackNode next){
        this.data=data;
        this.next=next;
    }
}
