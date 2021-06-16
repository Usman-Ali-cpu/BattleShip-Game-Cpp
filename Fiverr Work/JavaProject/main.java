
import java.util.Scanner;

public class main {

  public static void main(String[] args) {
    Hotel h = new Hotel();
    Room[] room = new Room[10];
    String firstName;
    String lastName;
    int numberID;

    Scanner input = new Scanner(System.in);

    while (true) {
      menu();
      int choice = Integer.parseInt(input.nextLine());

      switch (choice) {
        case 1:
          System.out.print("Enter Customer's First Name : ");
          firstName = input.nextLine();

          System.out.print("Enter Customer's Last Name : ");
          lastName = input.nextLine();

          System.out.print("Enter Customer's ID Number : ");
          numberID = Integer.parseInt(input.nextLine());

          Client c = new Client(firstName, lastName, numberID);
          h.addClient(c);
          break;
        case 2:
          // input.nextLine();
          int number;
          int type;
          System.out.print("Enter Room Number  : ");
          number = Integer.parseInt(input.nextLine());

          System.out.println("1.Simple type | 2.suite type | 3.double type");
          System.out.print("Enter Room type :(1,2,3) :  ");
          type = Integer.parseInt(input.nextLine());
          Room r = new Room();
          switch (type) {
            case 1:
              int d;
              System.out.print("Enter dimension of room : ");
              d = Integer.parseInt(input.nextLine());
              int p;
              System.out.print("Enter Price of room : ");
              p = Integer.parseInt(input.nextLine());
              r = new Simple(d, p, number);
              h.addRoom(r);
              break;
            case 2:
              int db;
              System.out.print("Enter dimension of bedroom : ");
              db = Integer.parseInt(input.nextLine());
              int lb;
              System.out.print("Enter dimension of livingroom : ");
              lb = Integer.parseInt(input.nextLine());
              // int p;
              System.out.print("Enter price of room : ");
              p = Integer.parseInt(input.nextLine());
              r = new Suite(db, lb, p, number);
              h.addRoom(r);
              input.nextLine();
              break;
            case 3:
              // int d;
              System.out.print("Enter dimension of room : ");
              d = Integer.parseInt(input.nextLine());
              String bedtype;
              input.nextLine();
              System.out.print("Enter bedType : ");
              bedtype = input.nextLine();
              input.nextLine();
              // int p;
              System.out.print("Enter price of room : ");
              p = Integer.parseInt(input.nextLine());
              r = new Double(p, d, bedtype, number);
              h.addRoom(r);
              break;
            default:
              System.out.println("Invalid Choice ");
              break;
          }
          break;
        case 3:
          // int number;
          // int type;
          int cID;
          int intime;
          int outTime;
          System.out.print("Enter Client ID:   : ");
          cID = Integer.parseInt(input.nextLine());
          System.out.print("Enter Check in time:   : ");
          intime = Integer.parseInt(input.nextLine());
          System.out.print("Enter Check out time:   : ");
          outTime = Integer.parseInt(input.nextLine());

          System.out.println("1.Simple type | 2.suite type | 3.double type");
          System.out.print("Enter Room type :(1,2,3) :  ");
          type = Integer.parseInt(input.nextLine());
          String s = " ";
          if (type == 1) {
            s = "simple";
          }
          if (type == 2) {
            s = "suite";
          }
          if (type == 3) {
            s = "double";
          }

          if (h.getClientCount() > 0) {
            h.reservationRoom(cID, intime, outTime, s);
          } else {
            System.out.println("You dont have to Client OR Room ");
          }
          break;
        case 4:
          int start = -1;
          int end = -1;
          while (start < 0 || start > 30) {
            System.out.println("Enter Checkin date (dd): ");
            start = Integer.parseInt(input.nextLine());
          }
          while (end < start || end > 30) {
            System.out.println("Enter Checkout date (dd): ");
            end = Integer.parseInt(input.nextLine());
          }
          h.PrintavailableRoomInPeriod(start, end);
          break;
        case 5:
          start = -1;
          end = -1;
          while (start < 0 || start > 30) {
            System.out.println("Enter Check in date (dd): ");
            start = Integer.parseInt(input.nextLine());
          }
          while (end < start || end > 30) {
            System.out.println("Enter Checkout date (dd): ");
            end = Integer.parseInt(input.nextLine());
          }
          h.PrintHotelBookings(start, end);
          break;
        case 6:
          // input.nextLine();
          start = -1;
          end = -1;
          while (start < 0 || start > 30) {
            System.out.println("Enter Check in date (dd): ");
            start = Integer.parseInt(input.nextLine());
          }
          while (end < start || end > 30) {
            System.out.println("Enter Check out date (dd): ");
            end = Integer.parseInt(input.nextLine());
          }
          h.PrintClientsBookings(start, end);

          break;
        case 7:
          System.exit(1);
          break;
        default:
          System.out.println("In valid Input ");
          break;
      }

      System.out.println("||   ------------------------------------  ||");
      System.out.println("You want to Proceed Again : ");
      System.out.println("1 Yes : ");
      System.out.println("2 No: ");
      System.out.println("||   ------------------------------------  ||");
      System.out.println("Enter choice : ");
      int n = Integer.parseInt(input.nextLine());
      if (n != 1) {
        break;
      }
    }

    input.close();
  }

  public static void menu() {
    System.out.println("||   ------------------------------------  ||");
    System.out.println("1. Add Customer to Hotel.");
    System.out.println("2. Add Room to Hotel.");
    System.out.println("3. Do reservation.");
    System.out.println(
      "4. Print Rooms Available, (by room type between a given period)."
    );
    System.out.println("5. Print Bookings made between a given period..");
    System.out.println("6. Bookings by clients within a given period.");
    System.out.println("7. Exit.");
    System.out.println("||   ------------------------------------   ||\n");
    System.out.print("Enter your choice : ");
  }
}