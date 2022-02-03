import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        double basePrice = 2;
        double X = 2000; // it a variable of type double to store price by distance
        double Y = 12.19;// it is a variable of type double to store price by weight
        Y = Y * 0.5; // for every ounce, multiply by 0.5 of dollar = 50 cent
        X = (X / 1000 * 0.30); // for every 1000 miles , multiply by 0.3of dollar = 30 cent
        double Z = basePrice + X + Y; // formula to calculate total postage
        System.out.println("Base price" + "\t\t  $" + basePrice); // printing base price
        System.out.println("Extra cost for distance" + "\t  $" + String.format("%.1f", X)); // printing Extra cost by
                                                                                            // distance
        System.out.println("Extra cost for weight" + "\t  $" + String.format("%.1f", Y)); // printing Extra cost by
                                                                                          // weight
        System.out.println("------------------------------------------------");
        System.out.println("Total postage cost" + "\t  $" + String.format("%.1f", Z)); // total postage
        System.out.println("\n\n\n\n");
    }
}