import java.util.Scanner;

public class Question2c {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter total grades points: ");
        int score = input.nextInt();
        if (score < 80) {
            score = 1;
        }
        switch (score) {
            case 1:
                System.out.println("work harder !");

                break;

            default:
                System.out.println("excelent !");
                break;
        }
        input.close();

    }

}
