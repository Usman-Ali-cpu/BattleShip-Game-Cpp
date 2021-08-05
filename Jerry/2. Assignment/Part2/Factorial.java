
import java.util.Scanner;

public class Factorial {
  
    public static void main(String args[]){  
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number to get Factorial : ");
        int number = input.nextInt();
         System.out.println("Factorial of "+number+" is: "+getFact(number));    
    }  

    public static int getFact(int number){
        int i,fact=1; 
        for(i=1;i<=number;i++){    
            fact=fact*i;    
        } 
        return fact;
    }
    
}
