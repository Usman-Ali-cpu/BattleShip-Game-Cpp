import java.util.Scanner;

public class Question1 {

    public static void main(String[] args) {
        // a)
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Interest rate: ");
        double interest = input.nextDouble();
        System.out.print("Enter amount borrowd as credit: ");
        double borrow = input.nextDouble();
        System.out.print("Enter Number of months required to pay: ");
        double months = input.nextInt();

        double year = months / 12;
        double fInterest = intrestCalculator(interest, borrow, year);
        double sInterest = compoundIntrestCalculator(interest, borrow + fInterest, year);
        double totalAmount = borrow + fInterest + sInterest;
        System.out.println("Amount borrowed: " + borrow);
        System.out.println("First Interest : " + interest);
        System.out.println("Second Interest: " + interest);
        System.out.println("Total Amount to pay: " + totalAmount);
        System.out.println("First Computed Interest: " + fInterest);
        System.out.println("Second Computed Interest: " + sInterest);
        input.close();

        // d)
        // Logic Behind The Code
        /*
         * Program Take input of interest rate first, then take input of credit amount
         * borrowed. Then it will take number months to pay amount. we will convert
         * months to year then pass interest rate, borrow amount and years to
         * interestCalculator method. InterestCalculator will calculate interest ammount
         * by formula (amount * year * rate) / 100; and return interest amount . Then
         * Program call compoundIntrestCalculator method, which takes sum of borrow
         * amount and interest calculated in InterestCalculator, and interest rate and
         * time in year it will return second interest amount. Then program will display
         * all values. Amount Borrow. First Interest. Rate Interest. Rate for second
         * Total Amount to pay. First Computed interest. Second Computed interest.
         * 
         */

    }

    // b)
    public static double intrestCalculator(double rate, double amount, double year) {
        double interest = (amount * year * rate) / 100;
        return interest;
    }

    // c)
    public static double compoundIntrestCalculator(double rate, double amount, double year) {
        double inter = (amount * year * rate) / 100;
        return inter;
    }

}
