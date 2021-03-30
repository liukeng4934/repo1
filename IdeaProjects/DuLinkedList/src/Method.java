import java.util.Scanner;

public class Method {
    static String str;
    static int pick = 0;
    static Scanner sc = new Scanner(System.in);


    //判断数据是否正确
    public static int isValid(char[] str2) {
        int isSpace = 0;
        int i = 0;//遍历字符数组
        for (; i < str2.length; i++) {
            if (str2[i] == ' ') isSpace = 1;
            else if (!(str2[i] <='9') && (str2[i] >='0'))
                return 0;
            else if ((str2[i] <='9') && (str2[i] >= '0') && isSpace == 1)
                return 0;
        }
        return 1;
    }

    //新的输入方法
    public static int InputPick() {
        str = sc.nextLine();//一直读取到换行符才算结束
        char[] str2 = str.toCharArray();
        if(Method.isValid(str2)==0){
            System.out.println("你输入的数据不符合，请重新输入");
            pick=InputPick();
        }
        else pick=Integer.parseInt(str.trim());//自己会辨认负数
        //trim()自己会移除字符串前后多余的空格
        //pick*=-1;//测试不是负数原因，不用理
        System.out.println(pick);
        return pick;
    }

    //菜单
    public static void Menu(){
        System.out.println("------------------------------");
        System.out.println("单向链表操作选项");
        System.out.print("0.退出程序                   ");
        System.out.println("1.初始化链表");
        System.out.print("2.插入节点(在指定位置前)       ");
        System.out.println("3.插入节点(在指定位置后)");
        System.out.print("4.删除节点(在指定位置后)       ");
        System.out.println("5.遍历链表");
        System.out.print("6.添加链表                   ");
        System.out.println("7.销毁链表");
        System.out.println("------------------------------");
        System.out.println("请输入你的选择:");
    }

    //初始化链表
    public static DuLNode InitList_DuL(){
        System.out.println("操作成功");
        return new DuLNode(0,null,null);
    }

/*
    //获取链表数据
    public static int InputData_DuL(){
        int num;
        Scanner sc=new Scanner(System.in);
        while(!sc.hasNextInt()){
            sc.next();
            System.out.println("数据不符合，请重新输入");
            System.out.println("请输入你的选择:");
        }
        num=sc.nextInt();
        return num;
    }

    //获取用户操作选择的输入(大于0的整数
    public static int InputNum(){
        int num;
        Scanner sc=new Scanner(System.in);
        while(!sc.hasNextInt()){
            sc.next();
            System.out.println("数据不符合，请重新输入");
            System.out.println("请输入你的选择:");
        }
        num=sc.nextInt();
        if(num<0){
            System.out.println("数据不符合，请输入大于0的整数");
            num=Method.InputNum();
        }
        return num;
    }

*/
    //判断操作是否成功
    public static void Judge(boolean flag){
        if(flag){
            System.out.println("操作成功");
        }
        else {
            System.out.println("操作失败");
        }
    }


    //删除节点后数据
    public static boolean DeleteList_DuL(DuLNode p){
        int e;
        if(p==null){
            System.out.println("节点为空");
            return false;
        }else if (p.next==null){
            System.out.println("下一个节点为空");
            return  false;
        }
        else {
            e=p.next.data;//取出删除的数据
            if (p.next.next!=null){
                p.next.next.prior=p;//下2个节点都不是空才进行，如果是空指针则不用管
            }
            p.next=p.next.next;
            System.out.println("删除节点成功,删除的数据为:"+e);
            return true;
        }
    }


    //遍历链表
    public static void TraverseList_DuL(DuLNode L){
        if(L==null){
            System.out.println("未初始化链表");
        }
        else if(L.next==null){
            System.out.println("链表为空");
        }
        else {
            int i=0;//10个数据换行
            DuLNode p=L.next;
            while (p!=null){
                if(i%10==0) System.out.println();
                System.out.print(p.data+"<-->");
                p=p.next;
                i++;
            }
            System.out.println();
            System.out.println("链表遍历完成");
        }
    }

    //获取链表节点
    public static DuLNode GetLNode_DuL(DuLNode L,int index){
        DuLNode p=L;
        if(L==null){
            System.out.println("未初始化链表");
            return null;
        }else if (L.next==null){
            System.out.println("链表为空");
            return L;
        }else {
            for (;index>0;--index){
                p=p.next;
                if(p==null){
                    return null;
                }
            }
        return p;
        }
    }

    //添加节点
    public static boolean AddLNode_DuL(DuLNode L,int num){
        DuLNode q,p=null;
        if (L==null){
            System.out.println("未初始化链表");
            return false;
        }else {
            for (q=L;q!=null;q=q.next){
                p=q;
            }
            //p是传入链表中的最后一个节点
            while (num>0){
                q=new DuLNode();
                q.next=null;
                p.next=q;
                q.prior=p;
                p=q;
                System.out.println("请输入节点数据");
                q.data=Method.InputPick();
                num--;
            }
            return true;
        }
    }


    //插入节点(位置后
    public static boolean InsertAfterList_DuL(DuLNode p,DuLNode q){
        if(p==null){
            System.out.println("节点为空");
            return false;
        }else {
            q.next=p.next;
            p.next=q;
            q.prior=p;
            System.out.println("插入节点成功");
            return true;
        }
    }

   //插入节点(位置前
   public static boolean InsertBeforeList_DuL(DuLNode p,DuLNode q){
       if(p==null){
           System.out.println("节点为空");
           return false;
       }else {
           q.prior=p.prior;
           p.prior=q;
           q.next=p;
           q.prior.next=q;
           System.out.println("插入节点成功");
           return true;
       }
   }

    //清屏
    public static void clear(){

        System.out.println("----------清屏----------");
        System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

}
