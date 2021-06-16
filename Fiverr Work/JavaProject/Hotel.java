import java.util.*;

public class Hotel {


    Client[] clients = new Client[10];
    List<Bookings> hotelbookinglist = new ArrayList<>();
    Bookings booking = new Bookings();
    String name;
    String address;
    String city;
    Room[] rooms = new Room[10];
    int roomCount;
    int clientCount;

    public Hotel() {
        booking.numberBook = 0;
        booking.dateCheckIn = 1;
        booking.dateCheckout = 1;
        name = "unkown";
        address = "Unknow ";
        city = "unknown";
        roomCount = 0;
        clientCount = 0;
    }

    public Hotel(String n, String a, String c, int numBook, int dateIn, int dateOut,
            Room[] room, Client[] client, int roomCount, int clientCount) {
        name = n;
        address = a;
        city = c;
        booking.numberBook = numBook;
        booking.dateCheckIn = dateIn;
        booking.dateCheckout = dateOut;
        this.rooms = room;
        this.clients = client;
        this.clientCount = clientCount;
        this.roomCount = roomCount;
    }
    public Hotel(String n, String a, String c, int numBook, int dateIn, int dateOut) {
        name = n;
        address = a;
        city = c;
        booking.numberBook = numBook;
        booking.dateCheckIn = dateIn;
        booking.dateCheckout = dateOut;
        roomCount = 0;
        clientCount = 0;
    }

    public void addRoom(Room r) {
        boolean flag = true;
        if (roomCount > 0)
        {
            for (Room room : this.rooms) {
                // if (room.number != r.number) {
                //     flag = false;
                // }
            }
        }
        if (flag) {

            rooms[roomCount] = r;
            roomCount++;
            int in, out, booknum;
            System.out.print("Enter Checkin time:  ");
            Scanner inner = new Scanner(System.in);
            in = inner.nextInt();
            System.out.print("Enter Checkout time:  ");
            out = inner.nextInt();
            System.out.print("Enter Booking number:  ");
            booknum = inner.nextInt();

            Bookings book = new Bookings(in, out, booknum);
            hotelbookinglist.add(book);
            System.out.println("*************  Room Added successfully ! ************* \n");
        } else {
            System.out.println("This Room Number is already there ! ");
        }
    }
    

    public void addClient(Client c) {
        boolean flag = true;
        if (clientCount > 0) {
            for (Client client : this.clients) {
                if (client.numberID != c.numberID) {
                    flag = false;
                }
            }
        }
        if (flag) {
            clients[clientCount] = c;
            clientCount++;
            System.out.println("***********   Customer Added successfully ! **************\n");
        } else {
            System.out.println("This Client is already there ! ");
        }
    }

    public int getClientCount() {
        return this.clientCount;
    }

    public void reservationRoom(int clientID, int checkin, int checkout, String type) {

        boolean flag = false;
        if (clientCount > 0) {
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].numberID == clientID) {
                    Bookings b = new Bookings(checkin, checkout);
                    for (Room r : this.rooms) {
                        flag = true;
                        System.out.println("*********  You have Room, It has been booked ************\n ");
                        clients[i].bookinglist.add(b);
                        hotelbookinglist.add(b);
                        break;
                    }
                }
            }
        }
    }

    public void PrintavailableRoomInPeriod(int start, int end) {
        System.out.println(" ------------------------------  ");
        System.out.println(" Available Rooms In Period  ");
        if (roomCount > 0) {
            for (int i = 0; i < roomCount; i++) {
                rooms[i].PrintRoom();
                System.out.println(" ------------------------------");
                
            }
        }
        else {
            System.out.println("No Room is Available ");
        }
        System.out.println(" ------------------------------\n");
    }

    public Room[] getRooms() {
        return this.rooms;
    }

    public void PrintHotelBookings(int start, int end) {
        System.out.println(" ------------------------------  ");
        System.out.println(" Available Rooms In Period  ");
        System.out.println("Booking Number \t Check in date  \t Check out date ");
        for (Bookings b : this.hotelbookinglist) {
            if (b.dateCheckIn <= start && b.dateCheckout >= end) {
                System.out.println(b.numberBook + "\t\t      " + b.dateCheckIn + "\t\t\t" + b.dateCheckout);
            }
        }
        System.out.println(" ------------------------------\n");
    }


    public void PrintClientsBookings(int start, int end) {
        if (clientCount > 0)
        {
            System.out.println("Booking Number \t Check in \t Check out ");
            for (Client c : this.clients) {
                {
                    for (Bookings b : this.hotelbookinglist) {
                        if (b.dateCheckIn <= start && b.dateCheckout >= end) {
                            System.out.println(b.numberBook + "\t\t      " + b.dateCheckIn + "\t\t\t" + b.dateCheckout);
                        }
                    }
                }
            }
        }
        else {
            System.out.println("You have no Client ! ");
        }
    }

}
