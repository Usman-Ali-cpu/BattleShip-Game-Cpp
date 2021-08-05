import java.util.Scanner;
public class Question2 {

    public static void main(String [] agrs){
        Scanner input = new Scanner(System.in);
        int hours;
        System.out.print("Enter number of hours worked in a week: ");
        hours = input.nextInt(); // taking input hours from user
        while(hours > 60){ // hours should be less than or equal to 60
            System.out.print("You can not work more than 60 hours in a week ");
            System.out.print("Enter number of hours worked in a week: ");
            hours = input.nextInt();
        }while(hours > 60);
        double wages = 0.0;

        if(hours <= 40){ //  if hours are less than or equal to 40 per hour
            wages = hours * 30; // cost is 30, total wage is get by multiply hours with 30
        }
        if (hours> 40){ //  if hours are greater 40 per hour
            wages = 40 * 30 + (hours-40) * (30* 1.5); // cost is 30 for fisr 40 and 45 for next
        }
        double socialSecurity = 0.06 * wages;
        double tax = 0.07 * wages;
        double unionDues = 0.03 * wages;

        // display outputs
        System.out.println("Total Wages = " + wages);
        System.out.println("Social Security = " + String.format("%.2f", socialSecurity));
        System.out.println("Taxes = " +String.format("%.2f", tax));
        System.out.println("Union Dues = " + String.format("%.2f", unionDues));
    }
}
