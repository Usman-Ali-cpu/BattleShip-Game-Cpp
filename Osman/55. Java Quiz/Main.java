import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[] { -1, -1, -2, -2, -3, -3 };
        System.out.println(getWin(1, 1));

    }

    public int numberNines(int num) {
        int number = num;
        number = number / 10;
        int count = 0;
        while (number > 10) {
            int remind = number % 10;
            if (remind == 9) {
                count++;
            }
            number = number / 10;
        }
        return count;

    }

}