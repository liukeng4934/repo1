import java.util.Queue;
import java.util.Scanner;

public class method {
    //获取整数
    public static int getNum(){
        int pick=0;
        Scanner sc = new Scanner(System.in);
        String str;
        System.out.println("请输入你的数据");
        str=sc.nextLine();
        try {
            char[] str2 = str.toCharArray();
            if(method.isValid(str2)==0){
                System.out.println("你输入的数据不符合，请重新输入");
                pick=getNum();
            }
            else pick=Integer.parseInt(str.trim());//自己会辨认负数
            //trim()自己会移除字符串前后多余的空格
        }catch (Exception e){
            System.out.println("空字符异常");
            System.out.println("请重新输入");
            pick=getNum();
        }
        return pick;
    }

    //输入数据类型
    public static void type(){
        System.out.println("1.整数类型");
        System.out.println("2.浮点类型");
        System.out.println("3.字符类型");
    }




    //小数输入
    public static double getNum2(){
        double pick=0;
        Scanner sc = new Scanner(System.in);
        String str;
        System.out.println("请输入你的数据");
        str=sc.nextLine();
        try {
            char[] str2 = str.toCharArray();
            if(method.isValid2(str2)==0){
                System.out.println("你输入的数据不符合，请重新输入");
                pick=getNum2();
            }
            else pick=Double.parseDouble(str.trim());//自己会辨认负数
            //trim()自己会移除字符串前后多余的空格
        }catch (Exception e){
            System.out.println("空字符异常");
            System.out.println("请重新输入");
            pick=getNum2();
        }
        return pick;
    }


    //判断方法，只能输入整数
    public static int isValid(char[] str){
        int i;
        int sign=0;//判断正负
        int digit=0;//数字长度
        for (i=0;i<str.length;i++){
            if((str[i]>='0'&&str[i]<='9')||str[i]=='+'||str[i]=='-'||str[i]=='\n'){
                if (str[i]=='+'||str[i]=='-'){
                    if (sign!=0)return 0;
                    if (str[i]=='+')sign=1;
                    else sign=-1;
                }
                else if (str[i]>='0'&&str[i]<='9'){
                    digit++;
                    if (digit>5){
                        System.out.println("数据过大");
                        return 0;
                    }
                }
            }
            else return 0;
        }
        return 1;
    }

    //判断方法2，只能输入小数
    public static int isValid2(char[] str){
        int point=0;
        int i;
        int sign=0;//判断正负
        int digit=0;//数字长度
        for (i=0;i<str.length;i++){
            if((str[i]>='0'&&str[i]<='9')||str[i]=='+'||str[i]=='-'||str[i]=='\n'||str[i]=='.'){
                if (str[i]=='+'||str[i]=='-'){
                    if (sign!=0)return 0;
                    if (str[i]=='+')sign=1;
                    else sign=-1;
                }
                else if (str[i]>='0'&&str[i]<='9'){
                    digit++;
                    if (digit>5){
                        System.out.println("数据过大");
                        return 0;
                    }
                }
                else {
                    if (point==1)return 0;
                    digit=0;
                    point=1;
                }
            }
            else return 0;
        }
        return 1;
    }


    public static void menu(){
        System.out.println("数组队列操作选择:");
        System.out.println("----------------------------------");
        System.out.print("1.初始化队列                          ");
        System.out.println("2.销毁队列");
        System.out.print("3.检查队列是否已满                     ");
        System.out.println("4.检查队列是否为空");
        System.out.print("5.查看队头元素                         ");
        System.out.println("6.确定队列长度");
        System.out.print("7.入队操作                            ");
        System.out.println("8.出队操作");
        System.out.print("9.清空队列                            ");
        System.out.println("10.遍历队列");
        System.out.println("11.退出");
    }


    //清屏
    public static void clear(){

        System.out.println("----------清屏----------");
        System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    //判断操作是否成功
    public static void Judge(boolean flag){
        if(flag){
            //System.out.println("操作成功");
        }
        else {
            //System.out.println("操作失败");
        }
    }

    //初始化队列
    public static void InitAQueue(AQueue Q){
        if(Q.length!=0){
            System.out.println("已初始化过队列");
        }
        else {
            Q.length=0;
            Q.front=0;
            Q.rear=0;
            System.out.println("初始化完成");
        }
    }

    //销毁队列
    public static void DestroyAQueue(AQueue Q){
        if(Q==null){
            System.out.println("队列未初始化");
        }
        else{
            for (int i = 0; i < Q.length; i++) {
                Q.data[(Q.front+i)%Q.MAXQUEUE]=null;
            }
            System.out.println("销毁完成");
        }
    }

 //检查队列是否已满
    public static boolean IsFullAQueue(AQueue Q){
        if (Q==null){
            System.out.println("队列未初始化");
            return false;
        }
        else if (Q.length==Q.MAXQUEUE){
            System.out.println("队列已满");
            return true;
        }
        else {
            System.out.println("队列未满");
            return false;
        }
    }

    //检查队列是否为空
    public static boolean IsEmptyAQueue(AQueue Q){
        if (Q==null){
            System.out.println("队列未初始化");
            return false;
        }
        else if (Q.length==0){
            System.out.println("队列为空");
            return true;
        }
        else {
            System.out.println("队列不为空");
            return false;
        }
    }

    //查看头元素
    public static boolean GetHeadAQueue(AQueue Q,data e){
        if (Q==null){
            System.out.println("队列未初始化");
            return false;
        }
        else if (Q.length==0){
            System.out.println("队列为空");
            return false;
        }
        else {
            e=Q.data[Q.front%Q.MAXQUEUE];
            System.out.println("队头元素为:"+e);
            return true;
        }
    }

//查看队列长度
    public static int  LengthAQueue(AQueue Q){
        if (Q==null){
            System.out.println("未初始化队列");
            return 0;
        }else {
            System.out.println("队列长度为:"+Q.length);
            return Q.length;
        }
    }



    //入队
    public static boolean EnAQueue(AQueue Q,data data){
        if (Q==null){
            System.out.println("未初始化队列");
            return false;
        }else if (Q.length==Q.MAXQUEUE){
            System.out.println("队列已满，无法入队");
            return false;
        }
        else {
            Q.data[Q.rear%Q.MAXQUEUE]=data;
            Q.rear++;
            Q.length++;
            System.out.println("入队成功");
            return true;
        }
    }

    //出队
    public static boolean DeAQueue(AQueue Q){
        if (Q==null){
            System.out.println("未初始化队列");
            return false;
        }else if (Q.length==0){
            System.out.println("队列为空");
            return false;
        }else {
            System.out.println("出队元素为:"+Q.data[Q.front%Q.MAXQUEUE]);
            Q.data[Q.front%Q.MAXQUEUE]=null;
            Q.front++;
            Q.length--;
            System.out.println("出队成功");
            return true;
        }
    }


//清空队列
    public static void ClearAQueue(AQueue Q){
        if (Q==null){
            System.out.println("未初始化队列");
        }
        else if(Q.length==0){
            System.out.println("队列为空，无需清空");
        }
        else{
            for (int i = 0; i < Q.length; i++) {
                Q.data[(Q.front+i)%Q.MAXQUEUE]=null;
            }
            Q.front=0;
            Q.length=0;
            Q.rear=0;
            System.out.println("清空完成");
        }

    }



    //遍历队列
    public static boolean TraveseAQueue(AQueue Q){
        if (Q==null){
            System.out.println("未初始化队列");
            return false;
        }
        else if(Q.length==0){
            System.out.println("队列为空");
            return false;
        }else{
            for (int i = 0; i < Q.length; i++) {
                System.out.print(Q.data[(Q.front+i)%Q.MAXQUEUE]+"  <-  ");;
            }
            System.out.println();
            return true;
        }
    }










}
