public class countSort{
public static void print(int arr[]){
    for (int i=0;i<arr.length;i++){
        System.out.print(arr[i]+" ");
    }
    System.out.println();
}
public static void countsort(int arr[]){
int max=findMax(arr);
int count[]=new int[max+1];
for (int i=0;i<count.length;i++){
    count[arr[i]]++;
}
int k=0;
for(int i=0;i<count.length;i++){
    for(int j=0;j<count[i];j++){
arr[k++]=i;
    }
}
}
public static int findMax(int arr[]){
    int max=-1;
    for(int i:arr){
        if(i>max){
            max=i;
        }
        
    }
    return max;
}
    public static void main(String[] args) {
    int arr[]={1,2,2,1,4,5,3,6};

    countsort(arr);
    print(arr);
}


}