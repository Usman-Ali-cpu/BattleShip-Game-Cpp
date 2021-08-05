
import java.util.Scanner;
import java.lang.Math;


public class Main {
    public static void main(String []args){ 
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = input.nextInt();
        System.out.print("Enter a it power: ");
        int pow = input.nextInt();

        System.out.println("Sum of " + number + " and " + pow + " is : " + sum(number, pow));
        System.out.print("Power of " + number + " to " + pow + " is : " + getPower(number, pow));

    }

    public static double getPower(int num, int p){
        return Math.pow(num, p);
    }
    public static double sum(int num, int p){
        return num + p;
    }
    
}
