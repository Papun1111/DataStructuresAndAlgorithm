public class RemoveDuplicates {
    public static void remove(String s,int idx,boolean curr[],StringBuilder str){
if(idx==s.length()){
    System.out.println("str");
    return;
}
char ch=s.charAt(idx);
if(curr[ch-'a']==true){
remove(s, idx+1, curr, str);
}
else{
    remove(s, idx+1, curr, str.append(ch));
}
    }
    public static void main(String[] args) {
        
    }
}
