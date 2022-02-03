import java.util.Scanner;

public class Question2 {

    public static void main(String[] args) {
        // a)
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Name of Employee: ");
        String name = input.nextLine();
        System.out.print("Enter Number of hours worked: ");
        int hours = input.nextInt();

        // c)

        payRole(name, hours);
        input.close();
        // d)
        // Logic Behind The Code
        /*
         * Program is taking input from user which is name of Employee and worked hours.
         * then it will call a payRole method. it will calculate workersalary by
         * multiplying ghc=10 and hours, and then reduce salary by 30% it will calculate
         * tax with is 50% percent of 15% of worker salary, which mean 7.5% Then it will
         * check whether hours is less than 170, if less than then take deduction of 5%
         * of worker salary.
         * 
         */

    }

    // b)
    public static void payRole(String name, int hours) {
        int ghc = 10;
        double workerSalary = (ghc * hours);
        workerSalary = workerSalary - (workerSalary * 0.3);
        System.out.println("Worker Salary : " + workerSalary);
        double tax = workerSalary * 0.075; // it is 50% of 15%
        System.out.println("Income Tax : " + tax);
        if (hours < 170) {
            double deduction = (workerSalary * 0.05);
            System.out.println("Deduction : " + deduction);
        }
    }

}
