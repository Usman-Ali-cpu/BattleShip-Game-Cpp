import java.util.Scanner;

public class LCF {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a first number : ");
        int number1 = input.nextInt();
        System.out.print("Enter a second number : ");
        int number2 = input.nextInt();
        System.out.println("Least Common Factor is : " + leastCommonFactor(number1, number2));

    }

    public static int leastCommonFactor(int number1, int number2) {
        if (number1 == 0 || number2 == 0) {
            return 0;
        }
        int absNumber1 = Math.abs(number1);
        int absNumber2 = Math.abs(number2);
        int absHigherNumber = Math.max(absNumber1, absNumber2);
        int absLowerNumber = Math.min(absNumber1, absNumber2);
        int lcf = absHigherNumber;
        while (lcf % absLowerNumber != 0) {
            lcf += absHigherNumber;
        }
        return lcf;
    }

}
