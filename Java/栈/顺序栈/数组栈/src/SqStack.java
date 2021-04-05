public class SqStack {
    public int[] elem;
    public int top;//指向栈顶
    public int size;//存储最大空间
    public SqStack(){

    }
    public SqStack(int sizes,int top){
        this.size=sizes;
        this.top=top;
        this.elem=new int[sizes];
    }
}
