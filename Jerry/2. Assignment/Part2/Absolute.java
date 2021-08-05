import java.util.Scanner;


public class Absolute{

    public static void main(String []args){
        Scanner input = new Scanner(System.in);
        System.out.println("Wellcome this program output with larger absolute value");

        System.out.print("Enter a integer : ");
        int num1 = input.nextInt();

        System.out.print("Enter a second integer : ");
        int num2 = input.nextInt();
        System.out.println("Value with higher absolute value between integer "+ num1 + " and "+ num2 + " is " + getAbsolute(num1, num2));
    }

    public static int getAbsolute (int n1,int n2){
        int num1 = n1;
        int  num2= n2;
        if(n1 < 0){
            n1 = n1 * -1;
        }
        if(n2 < 0){
            n2 = n2 * -1;
        }
        if(n1 > n2){
            return num1;
        }
        return num2;
    }

};