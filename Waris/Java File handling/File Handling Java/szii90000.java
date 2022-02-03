
import java.util.Scanner;

public class szii90000 {
    public static void main(String[] agrs) {

        Scanner input = new Scanner(System.in); // scanner object for input
        Datalist dl = new Datalist(); // object of datalist

        while (true) {
            // menu program
            System.out.println("0. Exit");
            System.out.println("1. Listing");
            System.out.println("2. Insertion");
            System.out.println("3. Deleting");
            System.out.println("4. Sorting");
            System.out.print("Enter the number of selected menu: ");
            int choice = input.nextInt(); // input choice
            switch (choice) {
                case 0:
                    input.close(); // close input scanner
                    System.exit(0); // terminate program

                    break;
                case 1: {
                    System.out.println("********************* LISTING ***********************");
                    dl.listing(); // printing data
                    System.out.println("********************* ******* ***********************");
                }

                    break;
                case 2:
                    System.out.print("Enter ID : ");
                    int id = input.nextInt(); // ask for id
                    System.out.print("Enter Name : ");
                    String name = input.nextLine(); // ask for name
                    name = input.nextLine();

                    System.out.print("Enter Birthday : ");
                    String brithday = input.nextLine(); // ask for day of birthday
                    while (brithday.length() > 10) {
                        System.out.println("Invalid Length!");
                        System.out.print("Enter Birthday : ");
                        brithday = input.nextLine(); // ask for day of birthday

                    }

                    String y = brithday.substring(0, 4);
                    String m = brithday.substring(5, 7);
                    String d = brithday.substring(8, 10);

                    int day = Integer.parseInt(d);
                    int mon = Integer.parseInt(m);// ask for month of birthday
                    int year = Integer.parseInt(y);// ask for year of birthday

                    System.out.print("Enter City : ");
                    Dates date = new Dates(day, mon, year);
                    String city = input.nextLine(); // ask for city
                    System.out.print("Enter IQ : ");
                    int iq = input.nextInt();// ask for iq
                    Data dataa = new Data(id, name, date, city, iq); // make object
                    dl.insert(dataa); // data to list

                    break;
                case 3:
                    System.out.print("Enter ID to remove data : ");
                    int idr = input.nextInt(); // ask for id
                    dl.remove(idr);// remove data of that id
                case 4: {
                    dl.sorting();
                }

                    break;
                default:
                    System.out.println("Invalid Input! ");
                    break;
            }

        }

    }

}