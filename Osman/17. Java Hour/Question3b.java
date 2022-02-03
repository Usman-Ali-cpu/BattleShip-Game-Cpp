import java.util.Scanner;

public class Question3b {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        // (i)
        int[] firstArry = new int[10];

        // (ii)
        String[][] secondArry = new String[10][5];

        // (iii)
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(secondArry[i][j]);
            }
            System.out.println();
        }

        // (iv)
        firstArry[9] = 10;

        input.close();

    }

}
