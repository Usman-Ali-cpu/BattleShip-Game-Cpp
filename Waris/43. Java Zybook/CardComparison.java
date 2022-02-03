import java.util.Scanner;

public class CardComparison {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter monthly expenses: ");
        int monthExp = in.nextInt();
        System.out.println("=== Credit Card 1 Offer ===");
        System.out.print("Enter annual fee: ");
        int annual1 = in.nextInt();
        double rate1 = getRate(in);
        System.out.println("=== Credit Card 2 Offer ===");
        System.out.print("Enter annual fee: ");
        int annual2 = in.nextInt();
        double rate2 = getRate(in);
        result(monthExp, rate1, rate2, annual1, annual2);
        in.close();
    }

    public static double getRate(Scanner in) {
        System.out.println("Enter points per dollar spent: ");
        double rate1 = in.nextDouble();
        return rate1;
    }

    public static double getDollar(int monthExp, double rate1, int annual1) {
        int yearExpense = monthExp * 12;
        double amount1 = yearExpense * rate1;
        amount1 = amount1 / 100;
        double dollars1 = amount1 - annual1;
        if (dollars1 < 0) {
            dollars1 = 0;
        }
        return dollars1;
    }

    public static void result(int monthExp, double rate1, double rate2, int annual1, int annual2) {
        double dollars1 = getDollar(monthExp, rate1, annual1);

        double dollars2 = getDollar(monthExp, rate2, annual2);
        System.out.println("Credit Card 1 annual award dollars = $" + String.format("%.2f", dollars1));
        System.out.println("Credit Card 2 annual award dollars = $" + String.format("%.2f", dollars2) + "\n");
        if (dollars1 == dollars2) {
            System.out.println("Both cards result in the same total award dollars.");
        } else if (dollars1 > dollars2) {
            System.out.println("We recommend applying for Credit Card 1.");
        } else {
            System.out.println("We recommend applying for Credit Card 2.");
        }
    }
}