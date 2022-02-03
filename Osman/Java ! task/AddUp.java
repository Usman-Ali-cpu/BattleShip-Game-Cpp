import java.util.Scanner;

public class AddUp {

    public static void main(String[] args) {
        final String BANNER = "*** RESULT ***\n"; // String of banner to print on top.
        Scanner kbInput = new Scanner(System.in); // make a scanner object to take input from user.

        System.out.println("Enter the first integer: "); // print message to enter first integer
        int firstInt = kbInput.nextInt(); // input first integer in firstInt variable type int

        System.out.println("Enter the second integer: "); // print message to enter second integer
        int secondInt = kbInput.nextInt(); // input first integer in second variable type int

        System.out.println("Enter the first floating point number : "); // print message to enter first double
        double firstDbl = kbInput.nextDouble(); // input first Double in firstDbl variable type double

        System.out.println("Enter the second floating point number : "); // print message to enter second double
        double secondDbl = kbInput.nextDouble(); // input second Double in secondDbl variable type double

        int compInt = firstInt + secondInt; // adding two integer
        double compDbl = firstDbl + secondDbl;// adding two double

        System.out.println(BANNER); // printing banner
        System.out.println("INT: " + compInt); // print sum of int
        System.out.println("DOUBLE: " + compDbl); // print sum of double
        kbInput.close();

    }
}