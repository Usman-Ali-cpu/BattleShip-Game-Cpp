public class Bookings {
    int numberBook;
    int dateCheckIn;
    int dateCheckout;

    Bookings() {
        numberBook = 0;
        dateCheckIn = 1;
        dateCheckout = 1;
    }

    Bookings(int fdate, int lastd, int n) {
        numberBook = n;
        dateCheckIn = fdate;
        dateCheckout = lastd;
    }
    Bookings(int fdate, int lastd) {
        numberBook = 1;
        dateCheckIn = fdate;
        dateCheckout= lastd;
    }

}
