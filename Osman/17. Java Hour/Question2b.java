import java.util.Scanner;

public class Question2b {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter total grades points: ");
        int score = input.nextInt();
        String result = (score >= 80) ? "excellent!" : "work harder !";
        System.out.println(result);
        input.close();

    }

}
