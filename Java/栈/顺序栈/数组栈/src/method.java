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


    //菜单
    public static void menu(){
        System.out.println("顺序栈操作选择:");
        System.out.println("----------------------------------");
        System.out.print("1.初始化栈                           ");
        System.out.println("2.判断栈是否为空");
        System.out.print("3.得到栈顶元素                       ");
        System.out.println("4.清空栈");
        System.out.print("5.销毁栈                            ");
        System.out.println("6.检测栈长度");
        System.out.print("7.入栈                              ");
        System.out.println("8.出栈");
        System.out.println("9.退出                             ");
    }


    //获取用户数据输入
    public static int getNum(){
        str = sc.nextLine();//一直读取到换行符才算结束
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
    public static boolean initStack(SqStack s,int sizes){
        if(s.elem!=null){
                System.out.println("已初始化栈");
                return false;
            }

        else if(sizes<=0){
            System.out.println("请输入大于0的数字");
            return false;
        }
        s.size=sizes;
        s.elem=new int[sizes];
        return true;
    }

    //判断栈是否为空
public static boolean isEmptyStack(SqStack s){
        if(s==null||s.elem==null){
            System.out.println("未初始化顺序栈");
            return false;
        }else if(s.top==-1){
            System.out.println("栈为空");
            return true;
        }else {
            System.out.println("栈不为空");
            return true;
        }
}

//得到栈顶元素
    public static boolean getTopStack(SqStack s,int e){
        int index;//索引
        if(s==null||s.elem==null){
            System.out.println("未初始化顺序栈");
            return false;
        }
        else if(s.top==-1){
            System.out.println("栈为空");
            return true;
        }else {
            index=s.top;
            e=s.elem[index];
            System.out.println("栈顶元素为"+e);
            return true;
        }
    }

//清空栈
    public static boolean clearStack(SqStack s){
        if(s==null){
            System.out.println("未初始化顺序栈");
            return false;
        }
        else {
            s.elem=null;
            s.top=-1;
            return true;
        }
    }

//销毁栈
    public static boolean destroyStack(SqStack s){
        if(s==null){
            System.out.println("未初始化顺序栈");
            return false;
        }
        else {
            s.elem=null;
            s=null;
            return true;
        }
    }



  //检测栈长度
    public static boolean stackLength(SqStack s,int length){
        if(s==null||s.elem==null){
            System.out.println("未初始化顺序栈");
            return false;
        }
        else{
            length=s.top+1;
            System.out.println("栈的长度为:"+(s.top+1));
            return true;
        }
    }

//入栈
    public static boolean pushStack(SqStack s,int data){
        if(s==null||s.elem==null){
            System.out.println("未初始化顺序栈");
            return false;
        }
        else {
            if(s.top==s.elem.length-1){
                System.out.println("栈满");
                return false;
            }
            else {
                s.top++;
                s.elem[s.top]=data;
                return true;
            }
        }
    }

//出栈
    public static boolean popStack(SqStack s,int data){
        if(s==null||s.elem==null){
            System.out.println("未初始化顺序栈");
            return false;
        }
        else {
            if (s.top==-1){
                System.out.println("栈为空");
                return false;
            }
            else {
                data=s.elem[s.top];
                System.out.println("出栈元素为:"+data);
                s.top--;
                return true;
            }
        }
    }











}
