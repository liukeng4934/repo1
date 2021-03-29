public class Main {
    public static void main(String[] args) {
        int pick;//用户菜单选择
        LNode mid=null;//接收中间节点
        boolean flag;//判断方法执行是否成功
        LNode head=null;
        LNode p=null;
        int num;
       // Scanner sc=new Scanner(System.in);
        while(true){
            Method.Menu();
            pick=Method.InputNum();
            switch (pick){

                case 0:System.exit(0);
                case 1:
                    head=Method.InitList();
                    break;
                case 2:
                    System.out.println("请输入要插入的节点位置");
                    num=Method.InputNum();
                    p=Method.GetLnode(head,num);
                    if(p!=null) {
                        LNode q = new LNode();
                        System.out.println("请输入插入节点的数据");
                        q.data = Method.InputData();
                        flag = Method.InsertList(p, q);
                        Method.Judge(flag);
                    }
                    break;

                    case 3:
                        System.out.println("请输入你要删除的节点位置");
                        num=Method.InputNum();
                        p=Method.GetLnode(head,num);
                        flag=Method.DeleteList(p);
                        Method.Judge(flag);
                        break;
                case 4:
                        Method.TraverseList(head);
                        break;
                case 5:
                    System.out.println("请输入你要查询的节点数据");
                    num=Method.InputData();
                    flag=Method.SearchList(head,num);
                    Method.Judge(flag);
                    break;
                case 6:
                    flag=Method.ReverseList(head);
                    Method.Judge(flag);
                    break;
                case 7:
                    flag=Method.IsLoopList(head);
                    Method.Judge(flag);
                    break;
                case 8:
                    mid=Method.FindMidLNode(head);
                    break;
                case 9:
                    head=Method.ReverseEvenList(head);
                    break;
                case 10:
                    System.out.println("请输入你要添加的节点个数");
                    num=Method.InputNum();
                    flag=Method.AddLNode(head,num);
                    Method.Judge(flag);
                    break;
                case 11:
                    head=null;
                    break;


                default:break;
            }
        }
    }



}
