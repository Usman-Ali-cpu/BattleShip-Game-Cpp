import java.util.Scanner;

public class Question4 {
    public static void main(String []args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Name of country : ");
        String name = input.nextLine(); // take name of country as input 
        System.out.print("Enter your Age : ");
        int age = input.nextInt(); // take age of voter as input
        isEligible(name, age);
    }
    public static void isEligible(String name, int age){
        if(name.toLowerCase().equals("ghana") && age>=18){ // check if country is ghana and age is greater than 18, 
            System.out.println("Your Are Eligible for Vote"); // display message you are voter
        }
        else{
            System.out.println("You are not Eligible for vote");// otherwise not eligible for vote
        }
    }
}
