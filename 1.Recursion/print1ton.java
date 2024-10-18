public class print1ton {
    public static void printIncreasing(int n){
if (n==0) {
    return ;
}
printIncreasing(n-1);
System.err.println(n);
    }
    public static void main(String[] args) {
printIncreasing(5);
    }
}
