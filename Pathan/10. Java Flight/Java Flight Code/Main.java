import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // An empty ArrayList of Traveller objects
        // ● An empty ArrayList of Flight objects
        // ● An empty ArrayList of Flight Reservation objects
        List<Traveller> travellerList = new ArrayList<Traveller>();
        List<Flight> flightList = new ArrayList<Flight>();
        List<Reservation> reservationList = new ArrayList<Reservation>();
        // 0 Bob Smith 255 Main Street Assign a VALID passport number to Bob
        travellerList.add(new Traveller(0, "Bob Smith", "1234Q", "255 Main Street"));
        travellerList.add(new Traveller(2, "Carmen Pope", "1111T", "8 Westgate Road"));
        travellerList.add(new Traveller(1, "Abigail Diaz", "123TQ", "100 Eastern Avenue"));
        // 0 AA281 DFW ICN 6835.70 miles
        // 1 AC306 YVR YUL 2291.00 miles
        // 2 WN3855 PHX STL 1261.38 miles
        flightList.add(new Flight(0, "AA281", "DFW", "ICN", 6835.70));
        flightList.add(new Flight(1, "AC306", "YVR", "YUL", 2291.00));
        flightList.add(new Flight(2, "WN3855", "PHX", "STL", 1261.38));
        System.out.println(
                "*********************************** All Traveller in the List *************************************************");
        for (int i = 0; i < travellerList.size(); i++) {
            System.out.println("\t\t" + travellerList.get(i).toString());
        }
        for (int i = 0; i < travellerList.size(); i++) {
            if (travellerList.get(i).getCustomer_name().contains("Abigail")) {
                Traveller abigail = travellerList.get(i);
                if (abigail.isValid()) {
                    System.out.println("\npassport number is valid");
                } else {
                    System.out.println("\nPassport number is invlaid. Update your passport number");
                }
                System.out.print("To update, Enter " + abigail.getCustomer_name() + "'s email address: ");
                String address = in.nextLine();
                travellerList.get(i).setEmail_address(address);

            }
        }
        System.out.println(
                "\n***************************************** Display list of traveller After Updation ***********************************************");
        System.out.println("All Traveller in the List");
        for (int i = 0; i < travellerList.size(); i++) {
            System.out.println("\t\t" + travellerList.get(i).toString());
        }
        // System.out.println("All Traveller in the List");
        for (int i = 0; i < flightList.size(); i++) {
            if (flightList.get(i).getFlight_number().equals("WN3855")) {
                flightList.get(i).setFlight_number("NU3884");
            }

        }
        System.out.println(
                "\n********************************************** Display list of flight After Updation ******************************************************* ");
        System.out.println("All flight in the List");
        for (int i = 0; i < flightList.size(); i++) {
            System.out.println("\t\t" + flightList.get(i).toString());
        }
        Date date = new Date(2021, 01, 10);
        Reservation reserve1 = new Reservation(flightList.get(0).getFlight_ID(), flightList.get(0).getFlight_number(),
                flightList.get(0).getDeparture_airport(), flightList.get(0).getArrival_airport(),
                flightList.get(0).getFdistance(), 1, travellerList.get(2), date, 20, "Veg");

        Reservation reserve2 = new Reservation(flightList.get(2).getFlight_ID(), flightList.get(2).getFlight_number(),
                flightList.get(2).getDeparture_airport(), flightList.get(2).getArrival_airport(),
                flightList.get(2).getFdistance(), 1, travellerList.get(0), date, 20, "Non-Veg");

        reservationList.add(reserve1);
        reservationList.add(reserve2);
        System.out.println(
                "\n********************************************** All the reservation ******************************************************* ");
        for (int i = 0; i < reservationList.size(); i++) {
            System.out.println(reservationList.get(i).toString());
        }
        System.out.println(
                "\n****************************************** Reserve By Bob ****************************************************");
        for (int i = 0; i < reservationList.size(); i++) {
            if (reservationList.get(i).getPassenger().getCustomer_name().contains("Bob")) {
                System.out.println(reservationList.get(i).toString());
                reservationList.get(i).setMeal_type("Non-Veg");
                reservationList.get(i).setSeat_number(10);
                System.out.println(
                        "\n**************************************** Reserve By Bob After Updating *****************************************");
                System.out.println(reservationList.get(i).toString());
                System.out.println(
                        "\n****************************************** Cost of ticket of Bob *************************************************");
                System.out.println("\t\t\t\tTotal Cost is : " + reservationList.get(i).calculateCost());

            }
        }

        in.close();

    }

}
