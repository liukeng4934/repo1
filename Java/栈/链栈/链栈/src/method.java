import java.util.Scanner;

public class method {

    static String str;
    static int pick = 0;
    static Scanner sc = new Scanner(System.in);

    //清屏
    public static void clear(){

        System.out.println("----------清屏----------");
        System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    //判断操作是否成功
    public static void Judge(boolean flag){
        if(flag){
            System.out.println("操作成功");
        }
        else {
            System.out.println("操作失败");
        }
    }

    static void menu(){
        System.out.println("链栈操作选择:");
        System.out.println("----------------------------------");
        System.out.print("1.初始化栈                           ");
        System.out.println("2.判断栈是否为空");
        System.out.print("3.得到栈顶元素                       ");
        System.out.println("4.清空栈");
        System.out.print("5.销毁栈                            ");
        System.out.println("6.检测栈长度");
        System.out.print("7.入栈                              ");
        System.out.println("8.出栈");
        System.out.println("9.退出");
    }



    //获取用户数据输入
    public static int getNum(){
        str = sc.nextLine();//一直读取到换行符才算结束
        if(str.equals("")){
            System.out.println("你输入的数据不符合，请重新输入");
            pick=getNum();
        }
        char[] str2 = str.toCharArray();
        if(method.isValid(str2)==0){
            System.out.println("你输入的数据不符合，请重新输入");
            pick=getNum();
        }
        else pick=Integer.parseInt(str.trim());//自己会辨认负数
        //trim()自己会移除字符串前后多余的空格
        return pick;
    }


    //判断数据是否正确
    public static int isValid(char[] str2) {
        int digit=0;
        int isSpace = 0;
        int i = 0;//遍历字符数组
        for (; i < str2.length; i++) {
            if (str2[i] == ' ') isSpace = 1;
            else if (!((str2[i] <='9') && (str2[i] >='0')))
                return 0;
            else if ((str2[i] <='9') && (str2[i] >= '0') && isSpace == 1)
                return 0;
            else if((str2[i] <='9') && (str2[i] >= '0')){
                digit++;
                if(digit>4){
                    System.out.println("数据溢出");
                    return 0;
                }
            }
        }
        return 1;
    }

//初始化栈
    public static boolean initLStack(LinkStack s){
        if(s!=null&&s.top!=null){
            System.out.println("栈已初始化");
            return false;
        }


        else {
            s.top=new StackNode();
            return true;
        }
    }


//判断是否为空栈
    public static boolean isEmptyLStack(LinkStack s){
        if(s==null||s.top==null){
            System.out.println("栈未初始化");
            return false;
        }
        else if(s.count==0){
            System.out.println("栈为空");
            return true;
        }
        else {
            System.out.println("栈不为空");
            return true;
        }
    }

//得到栈顶元素
    public static boolean getTopLStack(LinkStack s,int e){
        if(s==null||s.top==null){
            System.out.println("栈未初始化");
            return false;
        }
        else if(s.count==0){
            System.out.println("栈为空");
            return false;
        }else {
            e=s.top.data;
            System.out.println("栈顶元素为:"+e);
            return true;
        }
    }



//清空栈
    public static boolean clearLStack(LinkStack s){
        if(s==null||s.top==null){
            System.out.println("栈未初始化");
            return false;
        }
        else {
            s.top=null;
            s.count=0;
            return true;
        }
    }

//销毁栈
public static boolean destroyLStack(LinkStack s){
    if(s==null||s.top==null){
        System.out.println("栈未初始化");
        return false;
    }
    else {
        s.top=null;
        s.count=0;
        return true;
    }
}

//检测栈的长度
    public static boolean LStackLength(LinkStack s,int length){
        if(s==null||s.top==null){
            System.out.println("栈未初始化");
            return false;
        }
        else if (s.count==0){
            System.out.println("栈为空");
            return false;
        }else {
            length=s.count;
            System.out.println("栈的长度为:"+length);
            return true;
        }
    }


//入栈
    public static boolean pushLStack(LinkStack s,int data){
        if(s==null){
            System.out.println("栈未初始化");
            return false;
        }
        else {
            StackNode p=new StackNode(data,s.top);
            s.top=p;
            s.count++;
            return true;
        }
    }


//出栈
    public static boolean popLStack(LinkStack s,int data){
        if(s==null||s.top==null){
            System.out.println("栈未初始化");
            return false;
        }
        else if (s.count==0){
            System.out.println("栈为空");
            return false;
        }
        else {
            data=s.top.data;
            s.top=s.top.next;
            System.out.println("出栈元素为:"+data);
            s.count--;
            return true;
        }
    }


































}
