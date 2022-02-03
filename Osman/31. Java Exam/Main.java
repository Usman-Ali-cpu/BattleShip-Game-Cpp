import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    public static void main(String[] agrs) throws IOException {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int K = input.nextInt();
        int[] arr1 = new int[N - 1];
        int[] arr2 = new int[N - 1];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine(); // Input the number seperated by space
        int[] arr = new int[2];
        String[] s1 = s.split(" ");
        for (int i = 0; i < 2; i++) {
            arr[i] = Integer.parseInt(s1[i]);
        }
        for (int i = 0; i < N - 1; i++) {
            arr1[i] = arr[0];
            arr2[i] = arr[1];
        }
        int count = 0;
        for (int i = 0; i < K; i++) {
            int var = input.nextInt();
            for (int j = 0; j < N - 1; j++) {
                if (var <= arr1[j] && var >= arr2[j]) {
                    count++;
                    break;
                }
            }
        }

        System.out.println(count);

    }

}