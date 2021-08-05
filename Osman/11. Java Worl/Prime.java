import java.util.Scanner;

public class Prime {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a number : ");
        int number = input.nextInt();
        if (isPrime(number)) {
            System.out.println(number + " is Prime Number");
        } else {
            System.out.println(number + " is Not Prime Number");
        }

    }

    public static boolean isPrime(int number) {
        int i = 1;
        int count = 0;
        while (i < number) {
            if (number % i == 0) {
                count++;
            }
            i++;
        }
        if (count > 1) {
            return false;
        }
        return true;
    }

};