// Student Name : -------------
// Student Id : --------------

import java.util.Scanner; // importing for taking inut on console 

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // initialzing input scanner
        int[] arr = new int[5]; // declare array of size 5
        for (int i = 0; i < 5; i++) { // loop through the array
            System.out.print("How many people came to campus on day " + (i + 1) + "? "); // display message to take
                                                                                         // input
            arr[i] = in.nextInt(); // input integer in array at index i
        }
        System.out.println("\nChart Of People"); // print header for chart

        for (int i = 0; i < 5; i++) { // loop 5 time which is size of array
            int stars = arr[i] / 10; // as each star is of vlaue 10, so divide number at index i by 10, to get number
                                     // of stars
            System.out.print("Day " + (i + 1) + " : "); // print day number
            for (int j = 0; j < stars; j++) {
                System.out.print("*"); // and print how many star it has
            }
            System.out.println(); // add new line
        }
        in.close(); // close the input
    }
}