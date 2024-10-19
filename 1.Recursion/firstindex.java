public class firstindex {
    public static int firstOccur(int arr[],int n,int key){
        if(n==arr.length-1){
            return -1;
        }
        if(arr[n]==key){
            return n;
        }
        return firstOccur(arr, n+1, key);
    }
    public static void main(String[] args) {
        int arr[]={1,2,3,4,5,6,7,8};
        int a=firstOccur(arr,0,4);
        System.out.println(a);
    }
}
