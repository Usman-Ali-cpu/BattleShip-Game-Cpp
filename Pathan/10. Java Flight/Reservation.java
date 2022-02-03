import java.util.Date;

public class Reservation extends Flight {
    int id;
    Traveller passenger;
    Date date;
    int seat_number;
    String meal_type;

    public Reservation(int flight_ID, String flight_number, String departure_airport, String arrival_airport,
            double fdistance, int id, Traveller passenger, Date date, int seat_number, String meal_type) {
        super(flight_ID, flight_number, departure_airport, arrival_airport, fdistance);
        this.id = id;
        this.passenger = passenger;
        this.date = date;
        this.seat_number = seat_number;
        this.meal_type = meal_type;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Traveller getPassenger() {
        return passenger;
    }

    public void setPassenger(Traveller passenger) {
        this.passenger = passenger;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public int getSeat_number() {
        return seat_number;
    }

    public void setSeat_number(int seat_number) {
        this.seat_number = seat_number;
    }

    public String getMeal_type() {
        return meal_type;
    }

    public void setMeal_type(String meal_type) {
        this.meal_type = meal_type;
    }

    // calculateCost() method that calculates and returns the cost of the
    // reservation. The formula is:
    // $100 + (Flight Distance * $0.12)
    double calculateCost() {
        return 100 + (getFdistance() * 0.12);
    }

    @Override
    public String toString() {
        return id + ",\t" + passenger.toString() + ",\t" + date.toString() + ",\t" + seat_number + ",\t" + meal_type;
    }

}
