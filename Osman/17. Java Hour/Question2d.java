import java.util.Scanner;

public class Question2d {
    public static void main(String[] args) {
        int num = -1;
        Scanner input = new Scanner(System.in);

        do {

            System.out.print("Enter a number : ");
            num = input.nextInt();

        } while (num != 0);
        input.close();

    }

}
