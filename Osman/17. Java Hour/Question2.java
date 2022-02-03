import java.util.Scanner;

public class Question2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter total grades points: ");
        int score = input.nextInt();
        if (score >= 80) {
            System.out.println("excellent!");
        } else {
            System.out.println("work harder !");
        }
        input.close();

    }

}