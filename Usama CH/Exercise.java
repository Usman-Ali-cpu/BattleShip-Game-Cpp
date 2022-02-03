
import java.util.Scanner;

public class Exercise {
    // Main Method
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter card number : ");
        long number = input.nextLong();

        System.out.println(number + " is " +
                (isValid(number) ? "valid" : "invalid"));
        if (isValid(number)) {
            System.out.println("Type : " + getType(number));
        }
        input.close();
    }

    // Return true if the card number is valid
    public static boolean isValid(long number) {
        return (getSize(number) >= 13 &&
                getSize(number) <= 16) &&
                (prefixMatched(number, 4) ||
                        prefixMatched(number, 5) ||
                        prefixMatched(number, 37) ||
                        prefixMatched(number, 6))
                &&
                ((sumOfDoubleEvenPlace(number) +
                        sumOfOddPlace(number)) % 10 == 0);
    }

    public static String getType(Long type) {
        if (prefixMatched(type, 4)) {
            return "Visa Card";
        }
        if (prefixMatched(type, 5)) {
            return "Master Card";
        }
        if (prefixMatched(type, 37)) {
            return "American Express cards";
        }
        if (prefixMatched(type, 6)) {
            return "Discover Card";

        }
        return "invalid";

    }

    // Get the result from Step 2
    public static int sumOfDoubleEvenPlace(long number) {
        int sum = 0;
        String num = number + "";
        for (int i = getSize(number) - 2; i >= 0; i -= 2)
            sum += numberofDigits(Integer.parseInt(num.charAt(i) + "") * 2);

        return sum;
    }

    public static int numberofDigits(int number) {
        if (number < 9)
            return number;
        return number / 10 + number % 10;
    }

    // Return sum of odd-place digits in number
    public static int sumOfOddPlace(long number) {
        int sum = 0;
        String num = number + "";
        for (int i = getSize(number) - 1; i >= 0; i -= 2)
            sum += Integer.parseInt(num.charAt(i) + "");
        return sum;
    }

    // Return true if the digit d is a prefix for number
    public static boolean prefixMatched(long number, int d) {
        return getPrefix(number, getSize(d)) == d;
    }

    public static int getSize(long d) {
        String num = d + "";
        return num.length();
    }

    public static long getPrefix(long number, int k) {
        if (getSize(number) > k) {
            String num = number + "";
            return Long.parseLong(num.substring(0, k));
        }
        return number;
    }
}
