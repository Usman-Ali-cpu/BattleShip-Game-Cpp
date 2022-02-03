import java.util.Scanner;

public class Question1d {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Marks in exam: ");
        int gradesPoint = input.nextInt();
        if (gradesPoint <= 0 && gradesPoint >= 100) {
            System.out.println("Valid");
        } else {
            System.out.println("Not Valid");
        }
        input.close();

    }

}
