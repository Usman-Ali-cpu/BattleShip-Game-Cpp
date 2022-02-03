import java.util.*;

public class Main {
    private static boolean isPrime(int number) {
        int i = 2;
        boolean flag = false;
        while (i <= number / 2) {
            // condition for nonprime number
            if (number % i == 0) {
                flag = true;
                break;
            }
            ++i;
        }
        return !flag;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int num;
        int i;
        int tnum;
        do {

            System.out.println("Please enter a number, -1 to terminate:");
            num = scanner.nextInt();

            tnum = num;
            i = 2;

            if (isPrime(num)) {
                System.out.println(num + " is a prime number.");
            } else {
                System.out.print("\tFactors are [");
                while (tnum > 1) {
                    if (isPrime(i)) {
                        while (tnum % i == 0) {
                            System.out.print(i + ", ");
                            tnum = tnum / i;
                        }
                    }
                    i++;
                }
                System.out.println("]");
            }
        } while (num != -1);
        scanner.close();
    }
}