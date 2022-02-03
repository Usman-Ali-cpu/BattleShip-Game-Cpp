
import java.util.Scanner;

public class Question2e {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = 1;
        for (int j = 0; j < 6; j++) {
            for (int i = 0; i < n; i++) {
                System.out.print(n);
            }
            n++;
            System.out.println();
        }
        input.close();

    }

}
