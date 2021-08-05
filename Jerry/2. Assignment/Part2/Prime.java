
import java.util.Scanner;

public class Prime {
    
    public static void main(String []args){
        Scanner input = new Scanner(System.in);
        System.out.println("Wellcome this program output with is number is Prime or not");

        System.out.print("Enter a integer : ");
        int num1 = input.nextInt();
        System.out.print(num1 + " Is Prime Number : "+ isPrime(num1));
    }
    public static boolean isPrime(int n){
        int count =1;
        int num=2;
        while(num <= n){
            if(n % num == 0){
                count++;
            }
            num++;
        }
        if(count > 2){
            return false;
        }
        return true;
    }
}
