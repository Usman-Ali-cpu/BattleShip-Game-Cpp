

import java.util.Scanner;

public class Data {
    public static void main(String []args){ 
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your name : ");
        String name = input.nextLine();
        System.out.print("Enter your Age : ");
        String age = input.nextLine();
        System.out.print("Enter your College : ");
        String college = input.nextLine();

        printName(name);
        printAge(age);
        printcollege(college);
    }
    public static void printName(String n){
        System.out.println("My name is : " + n);
    }
    public static void printAge(String n){
        System.out.println("My Age is : " + n);
    }
    public static void printcollege(String n){
        System.out.println("My  College name is : " + n);
    }
    
}
