import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        for(;n>0;n>>=1){
            ans += n & 1;
        }
        System.out.println(ans);
    }

    private Node pre=null;
    public static boolean isBST(Node root)
    {
        if(root!=null)
        {
            if(!isBST(root.left))
                return false;
            if(pre!=null&&root.data<pre.data)
                return false;
            pre = root;
            if(!isBST(root.right))
                return false;
        }
        return true;
    }
}

