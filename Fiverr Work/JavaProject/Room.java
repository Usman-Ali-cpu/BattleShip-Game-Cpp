import java.util.*;

public class Room {
    

    int number;
    String type;
    List<Bookings> bookinglist = new ArrayList<>();

    Room() {
        number = 0;
    }
    
    Room(int n) {
        number = n;
    }

    public void addRoomBooking(Bookings book) {
        bookinglist.add(book);
        number++;
    }

    public void checkAvailable() {
        if (bookinglist.size() > 0) {
            for (Bookings book : bookinglist) {
                System.out.println("Start date : " + book.dateCheckIn);
                System.out.println("End date : " + book.dateCheckout);
                System.out.println("Available Bookings : " + book.numberBook);
            }
        }
    }

    public Boolean checkdates(int in, int out) {
        if (bookinglist.size() > 0) {
            for (Bookings book : bookinglist) {
                if (book.dateCheckIn >= in && book.dateCheckout <= out) {
                    System.out.println("Return true");
                    return true;
                }
            }
        }
        System.out.println("Return false ");
        return false; 
    }

    


    public void PrintRoom() {
        System.out.println("Room Number : " + number);
        System.out.println("Room Type : " + type);
    }
    
}
