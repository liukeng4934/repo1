public class main {
    public static void main(String[] args) {
        int pick;//用户菜单选泽
        int e=0;//获取栈顶元素
        int length=0;//栈的长度
        int data=0;
        boolean flag;//判断方法执行是否成功
        LinkStack s=null;
        while (true){
            method.menu();
            pick=method.getNum();
            switch (pick){
                case 1:
                    if(s==null){
                        s=new LinkStack(null,0);
                    }
                    flag=method.initLStack(s);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 2:
                    flag=method.isEmptyLStack(s);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 3:
                    flag=method.getTopLStack(s,e);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 4:
                    flag=method.clearLStack(s);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 5:
                    flag=method.destroyLStack(s);
                    s=null;
                    method.Judge(flag);
                    method.clear();
                    break;
                case 6:
                    flag=method.LStackLength(s,length);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 7:
                    System.out.println("请输入你入栈的数据");
                    data=method.getNum();
                    flag=method.pushLStack(s,data);
                    method.Judge(flag);
                    method.clear();
                    break;
                case 8:
                    flag=method.popLStack(s,data);
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
