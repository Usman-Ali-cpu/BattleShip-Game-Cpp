import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter an integer between 1 and 999 (inclusive):");
        int num = in.nextInt();
        if (num < 1 || num > 999) {
            System.out.println("Input must be 1-999. Program cannot continue.");
        } else {
            int palindrome = num; // copied number into variable
            int reverse = 0;
            while (palindrome != 0) {
                int remainder = palindrome % 10;
                reverse = reverse * 10 + remainder;
                palindrome = palindrome / 10;
            }
            if (num == reverse) {
                System.out.println(num + " is a numeric palindrome.");
            } else {
                System.out.println(num + " is not a numeric palindrome.");
            }
        }
        in.close();
    }
}