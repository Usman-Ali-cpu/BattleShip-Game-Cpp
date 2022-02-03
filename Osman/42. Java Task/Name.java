import java.util.Scanner;

public class Name {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {

            double mile1, gallon1;
            double totalMiles = 0, totalGallons = 0;
            int i = 1;
            while (i < 6) {
                System.out.println("\nPlease enter the number of miles driven for fill-up " + i);
                mile1 = in.nextDouble();
                System.out.println("Please enter the number of gallons for fill-up " + i);
                gallon1 = in.nextDouble();
                totalGallons += gallon1;
                totalMiles += mile1;
                double avr = mile1 / gallon1;
                System.out.printf(
                        "You drove %.2f miles and used %.2f gallons. You averaged %.2f miles per gallon on fill-up %d.",
                        mile1, gallon1, avr, i);
                i++;
            }
            double tavr = totalMiles / totalGallons;
            System.out.printf(
                    "%nYou drove %.2f miles and used %.2f gallons in total. %nYou averaged %.2f miles per gallon on fill-up.",
                    totalMiles, totalGallons, tavr);
            String again;

            System.out.println("\nWould you like to enter another set of fill-ups? Y/N");
            in.next();
            again = in.next();
            if (again.equals("n") || again.equals("N")) {
                return;
            }

        }

    }

}