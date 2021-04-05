import java.lang.reflect.Method;

public class main {
    public static void main(String[] args) {
        int pick;//用户菜单选泽
        int sizes;//栈数组的大小
        int length = 0;
        int e = 0;
        int data = 0;
        boolean flag;//判断方法执行是否成功
        SqStack s=null;
        while(true){
            method.menu();
            pick=method.getNum();
            switch (pick){
                case 1:
                    if(s==null)
                    {
                        s=new SqStack();
                        s.top=-1;
                        s.elem=null;
                    }
                    System.out.println("请输入栈的最大空间");
                    sizes=method.getNum();
                    flag=method.initStack(s,sizes);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 2:
                    flag=method.isEmptyStack(s);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 3:
                    flag=method.getTopStack(s,e);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 4:
                    flag=method.clearStack(s);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 5:
                    flag=method.destroyStack(s);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 6:
                    flag=method.stackLength(s,length);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 7:
                    System.out.println("请输入你进栈数据:");
                    data=method.getNum();
                    flag=method.pushStack(s,data);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 8:
                    flag=method.popStack(s,data);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 9:
                    System.exit(0);
                default:
                    System.out.println("无此项选择");
                    method.clear();
                    break;
                    
            }
        }
    }
}
