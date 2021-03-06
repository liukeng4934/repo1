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

    //清屏
    public static void clear() {

        System.out.println("----------清屏----------");
        System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    //菜单
    public static void Menu() {
        System.out.println("------------------------------");
        System.out.println("单向链表操作选项");
        System.out.print("0.退出程序                      ");
        System.out.println("1.初始化链表");
        System.out.print("2.插入节点                      ");
        System.out.println("3.删除节点");
        System.out.print("4.遍历链表                      ");
        System.out.println("5.查询节点");
        System.out.print("6.反转链表                      ");
        System.out.println("7.判断链表是否成环");
        System.out.print("8.找到链表的中间节点并返回         ");
        System.out.println("9.调换奇偶顺序");
        System.out.print("10.添加链表                     ");
        System.out.println("11.销毁链表");
        System.out.println("------------------------------");
        System.out.println("请输入你的选择:");
    }

    /*输入链表数据
    public static int InputData() {
        int num;
        Scanner sc = new Scanner(System.in);
        while (!sc.hasNextInt()) {
            sc.next();
            System.out.println("数据不符合，请重新输入");
            System.out.println("请输入你的选择:");
        }
        num = sc.nextInt();
        return num;
    }

    //获取用户输入(大于等于0的整数
    public static int InputNum() {
        int num;
        Scanner sc = new Scanner(System.in);
        while (!sc.hasNextInt()) {
            sc.next();
            System.out.println("数据不符合，请重新输入");
            System.out.println("请输入你的选择:");
        }
        num = sc.nextInt();
        if (num < 0) {
            System.out.println("数据不符合，请输入大于等于0的整数");
            num = Method.InputNum();
        }
        return num;
    }
*/

    //初始化链表
    public static LNode InitList() {
        System.out.println("操作成功");
        return new LNode(0, null);
    }


    //插入节点
    public static boolean InsertList(LNode p, LNode q) {
        if (p == null) {
            System.out.println("节点为空");
            return false;
        } else {
            q.next = p.next;
            p.next = q;
            System.out.println("插入节点成功");
            return true;
        }
    }


    //判断操作是否成功
    public static void Judge(boolean flag) {
        if (flag) {
            System.out.println("操作成功");
        } else {
            System.out.println("操作失败");
        }
    }


    //删除节点
    public static boolean DeleteList(LNode p) {
        int e;
        if (p == null) {
            System.out.println("节点为空");
            return false;
        } else if (p.next == null) {
            System.out.println("下一个节点为空");
            return false;
        } else {
            e = p.next.data;//取出删除的数据
            p.next = p.next.next;
            System.out.println("删除节点成功,删除的数据为:" + e);
            return true;
        }
    }

    //遍历链表
    public static void TraverseList(LNode L) {
        if (L == null) {
            System.out.println("未初始化链表");
        } else if (L.next == null) {
            System.out.println("链表为空");
        } else {
            int i = 0;//10个数据换行
            LNode p = L.next;
            while (p != null) {
                if (i % 10 == 0) System.out.println();
                System.out.print(p.data + "->");
                p = p.next;
                i++;
            }
            System.out.println();
            System.out.println("链表遍历完成");
        }
    }

    //获取链表节点
    public static LNode GetLNode(LNode L, int index) {
        LNode p = L;
        if (L == null) {
            System.out.println("未初始化链表");
            return null;
        } else if (L.next == null) {
            System.out.println("链表为空");
            return L;
        } else {
            for (; index > 0; --index) {
                p = p.next;
                if (p == null) {
                    return null;
                }
            }
            return p;
        }
    }

    //查询节点
    public static boolean SearchList(LNode L, int e) {
        LNode p;
        if (L == null) {
            System.out.println("未初始化链表");
            return false;
        } else if (L.next == null) {
            System.out.println("链表为空");
            return false;
        } else {
            p = L;
            while (p != null) {
                if (p.data == e) {
                    System.out.println("找到所求节点");
                    return true;
                }
                p = p.next;
            }
            System.out.println("未找到所求节点");
            return false;
        }
    }


    //反转链表
    public static boolean ReverseList(LNode L) {
        if (L == null) {
            System.out.println("未初始化链表");
            return false;
        } else if (L.next == null || L.next.next == null) {
            System.out.println("链表少于2个节点，无需反转");
            return false;
        } else {
            LNode head, p, q, r;
            head = L;
            p = head.next;
            head.next = null;
            q = p.next;
            p.next = null;
            while (q != null) {
                r = q.next;
                q.next = p;
                p = q;
                q = r;
            }
            head.next = p;
            System.out.println("链表反转完成");
            return true;
        }
    }


    //判断链表是否成环
    public static boolean IsLoopList(LNode L) {
        if (L == null) {
            System.out.println("未初始化链表");
            return false;
        } else if (L.next == null) {
            System.out.println("链表为空");
            return false;
        } else {
            LNode slow, fast;//如果成环，一定相遇
            slow = fast = L;
            while (slow.next != null && fast.next != null && fast.next.next != null) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) {
                    System.out.println("该链表成环");
                    return true;
                }
            }
            System.out.println("该链表不成环");
            return false;
        }
    }


    //找到中间节点并返回
    public static LNode FindMidLNode(LNode L) {
        if (L == null) {
            System.out.println("未初始化链表");
            return null;
        } else if (L.next == null) {
            System.out.println("链表为空");
            return null;
        } else {
            LNode fast, slow;
            fast = slow = L;
            while (fast != null) {
                if (fast.next == null) {
                    fast = null;
                } else {
                    fast = fast.next.next;
                }
                slow = slow.next;
            }
            return slow;
        }
    }

    //调换奇偶顺序
    public static LNode ReverseEvenList(LNode L) {
        if (L == null) {
            System.out.println("未初始化链表");
            return null;
        } else if (L.next == null) {
            System.out.println("链表为空");
            return L;
        } else {
            LNode cur = L.next;
            LNode p;
            LNode head2 = new LNode();//新建一个头结点，用来链接链表
            head2.next = null;
            LNode q = head2;
            while (cur != null && cur.next != null) {
                p = cur;
                q.next = p.next;
                q = q.next;
                cur = cur.next.next;//移后两位，反转前面的2个节点
                q.next = p;
                q = q.next;
            }
            q.next = cur;
            return head2;
        }
    }

    //添加节点
    public static boolean AddLNode(LNode L, int num) {
        LNode q, p = null;
        if (L == null) {
            System.out.println("未初始化链表");
            return false;
        } else {
            for (q = L; q != null; q = q.next) {
                p = q;
            }
            //p是传入链表中的最后一个节点
            while (num > 0) {
                q = new LNode();
                q.next = null;
                p.next = q;
                p = q;
                System.out.println("请输入节点数据");
                q.data = Method.InputPick();
                num--;
            }
            return true;
        }
    }



}
