import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.print("Enter number:");
        int n = s.nextInt();
        System.out.println("Multiplying Table of " + n);
        printMultiTable(n);
        System.out.println("Fibonacci serries of " + n);
        printFibonacci(n);

    }

    public static void printMultiTable(int n) {
        for (int i = 1; i <= 10; i++) {
            System.out.println(n + " * " + i + " = " + n * i);
        }
    }

    public static void printFibonacci(int n) {
        int n1 = 0, n2 = 1, n3, i;
        System.out.print(n1 + " " + n2);// printing 0 and 1

        for (i = 2; i < n; ++i)// loop starts from 2 because 0 and 1 are already printed
        {
            n3 = n1 + n2;
            System.out.print(" " + n3);
            n1 = n2;
            n2 = n3;
        }
    }

}
