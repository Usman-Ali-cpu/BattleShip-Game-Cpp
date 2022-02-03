import java.util.Scanner;

public class Question3a {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double[] salaries = new double[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter salary " + (i + 1) + " : ");
            salaries[i] = input.nextDouble();
        }
        System.out.println("Sum is : " + sum(salaries));
        System.out.println("Average is : " + sum(salaries) / 5);
        input.close();
    }

    public static double sum(double[] salaries) {
        double sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += salaries[i];
        }
        return sum;
    }

}
