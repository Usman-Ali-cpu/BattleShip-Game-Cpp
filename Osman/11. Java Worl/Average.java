import java.util.Scanner;

public class Average {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter total numbers (n) : ");
        int n = input.nextInt();
        float sum = 0;
        for (int i = 0; i < n; i++) {
            int number;
            System.out.print("Enter number : ");
            number = input.nextInt();
            sum += number;
        }
        float avr = sum / n;
        System.out.println("Average of " + n + " numbers is : " + avr);
        input.close();

    }

}
