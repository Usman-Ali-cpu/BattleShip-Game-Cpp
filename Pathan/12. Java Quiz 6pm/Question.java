import java.util.Scanner;

public class Question {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter value for k: ");
        int k = in.nextInt();
        double[] data = new double[k];
        getIncome(data);
        double minimum = findMin(data);
        isRich(data, minimum);

        in.close();

    }

    public static void getIncome(double[] data) {
        Scanner in = new Scanner(System.in);

        for (int i = 0; i < data.length; i++) {
            System.out.print("Enter value for " + (i + 1) + ": ");
            data[i] = in.nextDouble();
        }
        in.close();
    }

    public static double findMin(double[] data) {
        double min = 25245;
        for (int i = 0; i < data.length; i++) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        return min;
    }

    public static void isRich(double[] data, double min) {
        int count = 0;
        double permin = 0.15 * min;
        for (int i = 0; i < data.length; i++) {
            if (data[i] > permin) {
                count++;
            }
        }
        System.out.println("Count is : " + count);
    }

}
