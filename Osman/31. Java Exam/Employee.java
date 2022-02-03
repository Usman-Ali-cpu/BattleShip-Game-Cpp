
import java.util.Scanner;

public class Employee {

    public static void main(String[] agrs) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int M = input.nextInt();
        int[] arr1 = new int[N];
        for (int i = 0; i < N; i++) {
            arr1[i] = input.nextInt();
        }
        for (int i = 0; i < N; i++) {
            System.out.print(arr1[i]);
            int count = 0;
            for (int j = 0; j <= i; j++) {
                if (arr1[i] == arr1[j]) {
                    count++;
                }

            }
            System.out.println(" " + count);

        }

    }

}
