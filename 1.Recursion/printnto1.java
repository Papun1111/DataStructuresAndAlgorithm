public class printnto1{
    public static void printNto1(int n){
        if(n==0){
            return;
        }
        System.err.println(n);
        printNto1(n-1);
    }
    public static void main(String args[]){
printNto1(5);
    }
}