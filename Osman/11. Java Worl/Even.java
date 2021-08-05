import java.util.Scanner;

public class Even {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number to get Even Numbers : ");
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                System.out.println(i + " is a Even number in range of " + n);
            }
        }
    }

}
