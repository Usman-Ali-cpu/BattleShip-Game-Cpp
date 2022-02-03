import java.util.Scanner;

public class Read {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = -1;
        System.out.print("Enter number of ints you want to read (>0): ");
        num = input.nextInt();
        while (num <= 0) {
            System.out.println("Number must be > 0");
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
        if (num > 0) {
            arr[0] = 6;
        }
        // 2
        if (num >= 5) {
            arr[4] = 5;
        }

        // 3
        System.out.print("\nEnter the number i(>0): ");
        int i = input.nextInt();
        int index = i * 2;
        if (index < num) {
            arr[index] = 4;

        }
        // print array
        System.out.print("Printed Array : ");
        for (int j = 0; j < num; j++) {
            System.out.print(arr[j] + " ");
        }

        input.close();

    }

}