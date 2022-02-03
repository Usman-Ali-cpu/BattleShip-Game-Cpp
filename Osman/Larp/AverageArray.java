import java.util.Scanner;

public class AverageArray {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of elements : ");
        int size = input.nextInt();
        int[] array = new int[size];
        float sum = 0;
        for (int i = 0; i < array.length; i++) {
            System.out.print("Enter element " + (i + 1) + " : ");
            array[i] = input.nextInt();
        }
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        float average = sum / size;
        System.out.println("Enter Average is : " + average);
        input.close();

    }

}
