import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (true) {

            System.out.println("What is the bowler's name : ");
            String name = in.nextLine();
            if (name.equals("")) {
                in.close();
                System.out.println("Thank you for using the bowling average program");
                return;
            }
            int sum = 0;
            for (int i = 1; i < 6; i++) {

                System.out.println("Please enter the score for " + name + " for game " + i);
                int score = in.nextInt();
                while (score > 300 || score < 0) {
                    System.out.println("Invalid score. The score must be between 0 and 300 inclusive ");
                    System.out.println("Please enter the score for " + name + " for game " + i);
                    score = in.nextInt();
                }
                sum += score;
            }
            double average = sum / 5.0;
            System.out.println(name + " has an average score of " + String.format("%.2f", average) + ".");
            in.nextLine();
        }
    }

}