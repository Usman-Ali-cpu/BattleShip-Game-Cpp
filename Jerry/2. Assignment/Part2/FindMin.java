
import java.util.Scanner;

public class FindMin {
    public static void main(String []args){ 
        System.out.println("Minimum Number is : " + getMinimum());
    }

    public static int getMinimum(){
        Scanner input = new Scanner(System.in);
        int larger = 2434;
        int num =0;
        while(num != -1){
            System.out.print("Enter a number or (-1 to end): ");
            num = input.nextInt();
            if(num < larger && num != -1){
                larger = num;
            }
        }
        return larger;
    }
    
}
