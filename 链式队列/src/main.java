import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str;
        int pick;
        data e=null;
        int type;
        int length;
        boolean flag;
        LQueue Q=null;

        while (true){
            method.menu();
            pick=method.getNum();
            switch (pick){
                case 1:
                    if (Q==null){
                        Q=new LQueue();
                    }
                    method.InitLQueue(Q);
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 2:
                    method.DestroyLQueue(Q);
                    if(Q!=null){
                        Q=null;
                    }
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 3:
                    flag=method.IsEmptyLQueue(Q);
                    method.Judge(flag);
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 4:
                    flag=method.GetHeadLQueue(Q,e);
                    method.Judge(flag);
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 5:
                    length=method.LengthAQueue(Q);
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 6:
                    method.type();
                    System.out.println("请输入你要存放的数据类型");
                    type=method.getNum();
                    while (!(type>0&&type<4)){
                        System.out.println("无此项选择，请重新输入");
                        type=method.getNum();
                    }


                    if (type==1)
                    {
                        data<Integer> data1=new data<>(method.getNum());
                        method.EnLQueue(Q,data1);
                    }
                    if (type==2){
                        data<Double> data2=new data<>(method.getNum2());
                        method.EnLQueue(Q,data2);
                    }
                    if(type==3){
                        System.out.println("请输入你的数据");
                        data<String> data3=new data<>(sc.nextLine());
                        method.EnLQueue(Q,data3);
                    }
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 7:
                    flag=method.DeLQueue(Q);
                    method.Judge(flag);
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 8:
                    method.ClearLQueue(Q);
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 9:
                    flag=method.TraverseLQueue(Q);
                    method.Judge(flag);
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;
                case 10:
                    System.exit(0);
                default:
                    System.out.println("无此项选择");
                    System.out.println("请输入任意字符清屏");
                    str=sc.nextLine();
                    method.clear();
                    break;


            }

        }
    }
}
