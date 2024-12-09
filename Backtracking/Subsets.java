public class Subsets{
   static void printSubsets(String s,String ans,int i){
        if(i==s.length()){
            System.out.println(ans);
            return;
        }


        printSubsets(s, ans+s.charAt(i), i+1);
        
        printSubsets(s, ans, i+1);
    }
    public static void main(String args[]){
String s="kanha";
String ans="";
printSubsets(s, ans, 0);
    }
}