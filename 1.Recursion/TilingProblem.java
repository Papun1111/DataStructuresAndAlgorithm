
public class TilingProblem{
public static int TilingWays(int n){
if(n==1||n==0){
return 1;
}
int vertWays=TilingWays(n-1);
int horWays=TilingWays(n-2);
int tot=vertWays+horWays;
return tot;

}
    public static void main (String args[]){
System.out.println(TilingWays(4));
    }
}