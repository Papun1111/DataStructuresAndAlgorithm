public class Pairing{
    public static int pair(int n){
        if(n==1||n==2){
            return n;
        }
        int fps=pair(n-1);
        int fpc=pair(n-2);
        int restways=(n-1)*fpc;
        int total=restways+fps;
        return total;
    } 
public static void main(String[] args) {
    int ways=pair(13);
    System.out.println(ways);
}
}