import java.util.Scanner;

public class ReadInt {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = -1;
        while (num <= 0) {
            System.out.print("Enter number of ints you want to read: ");
            num = input.nextInt();
        }

        int[] arr = new int[num];
        System.out.print("Enter " + num + " the number: ");
        for (int i = 0; i < num; i++) {
            arr[i] = input.nextInt();
        }
        System.out.print("The number you entered are : ");
        for (int i = 0; i < num; i++) {
            System.out.print(arr[i] + " ");
        }
        input.close();

    }

}