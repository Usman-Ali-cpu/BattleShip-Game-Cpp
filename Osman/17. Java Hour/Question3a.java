import java.util.Scanner;

public class Question3a {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double height = input.nextDouble();
        double weight = input.nextDouble();
        double bmi = calcBMI(height, weight);
        System.out.println("Body Mass Index : " + String.format("%.2f", bmi));

        input.close();

    }

    public static double calcBMI(double height, double weight) {
        height = height / 100;
        height = height * height;
        return weight / height;

    }

}
