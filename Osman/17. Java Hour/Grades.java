import java.util.Scanner;

public class Grades {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter total grades points: ");
        int gradesPoint = input.nextInt();
        final double TOTAL_CH = 120;
        double commulativeGradesPoint = gradesPoint / TOTAL_CH;
        System.out.print("Commulative Grade Point is : " + String.format("%.2f", commulativeGradesPoint));
        input.close();

    }
}