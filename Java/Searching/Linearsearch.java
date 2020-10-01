import java.util.*;

public class LinearSearch{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of Array");
        int n=sc.nextInt();
        int array[]=new int[n];
        for(int i=0;i<n;i++){
            array[i]=sc.nextInt();
        }
        System.out.println("Enter the value to find");
        int key =sc.nextInt();
        int c=0;
        int index=0;
        for(int i=0;i<n;i++){
            if(array[i]==key){
                c=c+1;
                index=i;
                break;
            }
        }
        if(c>0){
            System.out.println("The value is found at index "+ index);
        }
        else{
            System.out.println("Not in the Array");
        }
    }
}