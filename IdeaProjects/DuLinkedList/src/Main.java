public class Main {
    public static void main(String[] args) {
        int pick;//用户菜单选泽
        boolean flag;//判断方法执行是否成功
        DuLNode head = null;
        DuLNode p;
        int num;
        while (true) {
            Method.Menu();
            pick = Method.InputPick();
            switch (pick) {
                case 0:
                    System.exit(0);
                case 1:
                    head = Method.InitList_DuL();
                    Method.clear();
                    break;
                case 2:
                    System.out.println("请输入要插入的节点位置");
                    num = Method.InputPick();
                    p = Method.GetLNode_DuL(head, num);
                    if (p != null) {
                        DuLNode q = new DuLNode();
                        System.out.println("请输入插入节点的数据");
                        q.data = Method.InputPick();
                        flag = Method.InsertBeforeList_DuL(p, q);
                        Method.Judge(flag);
                    } else {
                        System.out.println("未找到所插节点位置");
                        Method.Judge(false);
                    }
                    Method.clear();
                    break;
                case 3:
                    System.out.println("请输入要插入的节点位置");
                    num = Method.InputPick();
                    p = Method.GetLNode_DuL(head, num);
                    if (p != null) {
                        DuLNode q = new DuLNode();
                        System.out.println("请输入插入节点的数据");
                        q.data = Method.InputPick();
                        flag = Method.InsertAfterList_DuL(p, q);
                        Method.Judge(flag);
                    } else {
                        System.out.println("未找到所插节点位置");
                        Method.Judge(false);
                    }
                    Method.clear();
                    break;
                case 4:
                    System.out.println("请输入你要删除的节点位置");
                    num=Method.InputPick();
                    p=Method.GetLNode_DuL(head,num);
                    flag=Method.DeleteList_DuL(p);
                    Method.Judge(flag);
                    Method.clear();
                    break;
                case 5:
                    Method.TraverseList_DuL(head);
                    Method.clear();
                    break;
                case 6:
                    System.out.println("请输入你要添加的节点个数");
                    num=Method.InputPick();
                    flag=Method.AddLNode_DuL(head,num);
                    Method.Judge(flag);
                    Method.clear();
                    break;
                case 7:
                    head=null;
                    Method.clear();
                    break;
                default:
                    System.out.println("无此项选择");
                    Method.clear();
                    System.out.println("请重新输入操作选择");
                    break;
            }
        }
    }
}
