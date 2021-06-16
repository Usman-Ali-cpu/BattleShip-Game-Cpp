import java.util.*;

public class Client {

    String firstName;
    String lastName;
    int numberID;
    List<Bookings> bookinglist = new ArrayList<>();
    Bookings clientBook = new Bookings();

    Client() {
        this.firstName = "No";
        this.lastName = "No";
        this.numberID = 0;
    }

    Client(String f, String l, int num) {
        this.firstName = f;
        this.lastName = l;
        this.numberID = num;
    }

    public void addBooking(Bookings book) {
        bookinglist.add(book);
    }
}
