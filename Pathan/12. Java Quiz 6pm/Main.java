import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < 100; i++) {
            System.out.print("Enter visitor age: ");
            int age = in.nextInt();
            in.nextLine();
            System.out.print("Enter ticket type: ");
            char type = in.nextLine().charAt(0);
            System.out.print("Enter discount amount: ");
            double discount = in.nextDouble();
            in.nextLine();
            double price = getTicketPrice(age, type, discount);
            printDiscountTicket(price, discount);

        }
        in.close();

    }

    public static double getTicketPrice(int age, char type, double amount) {
        double price = 0;
        if (age < 10 || age >= 70) {
            price = 15;
        } else {
            price = 30;
        }
        if (type == 'A') {
            price += 20;
        }
        if (type == 'B') {
            price += 10;
        }
        return price;

    }

    public static void printDiscountTicket(double price, double discount) {
        System.out.println("ticket price is : " + (price - (price * discount)) + " ADE");

    }

}