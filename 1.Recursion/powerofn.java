public class powerofn {
   public static int powerOfXton(int x,int n){
        if(n==0){
            return 1;
        }
        return x*powerOfXton(x,n-1);
    }
    public static void main(String[] args) {
        int a=powerOfXton(3,3);
        System.out.println(a);
    }
}
