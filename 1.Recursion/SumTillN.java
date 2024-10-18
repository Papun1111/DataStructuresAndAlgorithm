public class SumTillN {
    public static int sumofn(int n){
        if(n==1)return 1;
        return n+sumofn(n-1);
    }
    public static void main(String[] args) {
        int sum=sumofn(4);
        System.err.println(sum);
    }
}
