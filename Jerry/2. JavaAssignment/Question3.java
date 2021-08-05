import java.util.Scanner;

public class Question3 {

    public static void main(String []args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter name of car : ");
        String carName = input.nextLine();// input name of car
        int price = 0;
        double tax = 0.0;
        if(carName.toLowerCase().equals("yaris")){ // if car name is yaris
            price = 50000;
            tax = 0.5/100 * price; // tax will be 5%
        }
        else if(carName.toLowerCase().equals("corolla")){ // if car name is corolla
            price = 60000;
            tax = 0.8/100 * price; // tax will be 8%
        }
        else {
            System.out.println("Invalid Input ");
        }
        // display output variable and values 
        System.out.println("Tax on Car : " + String.format("%.2f", tax));
        double govtTax = 0.25 * price;
        price = (int) (price + govtTax);
        System.out.println("Govt incentive Tax on each car: " + String.format("%.2f", govtTax));
        System.out.println("Price of car after Govt incentive Tax: " +  price);
    }
}
