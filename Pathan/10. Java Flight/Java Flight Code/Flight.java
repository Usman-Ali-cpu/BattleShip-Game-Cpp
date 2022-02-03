import java.util.Date;

public class Flight {
    int flight_ID;
    String flight_number;
    String departure_airport;
    String arrival_airport;
    Date date_departure;
    double fdistance;

    public Flight(int flight_ID, String flight_number, String departure_airport, String arrival_airport,
            double fdistance) {
        this.flight_ID = flight_ID;
        this.flight_number = flight_number;
        this.departure_airport = departure_airport;
        this.arrival_airport = arrival_airport;
        this.fdistance = fdistance;
    }

    public Flight(int flight_ID, String departure_airport, String arrival_airport, Date date_departure,
            double fdistance) {
        this.flight_ID = flight_ID;
        this.departure_airport = departure_airport;
        this.arrival_airport = arrival_airport;
        this.date_departure = date_departure;
        this.fdistance = fdistance;
    }

    public void setArrival_airport(String arrival_airport) {
        this.arrival_airport = arrival_airport;
    }

    public void setDeparture_airport(String departure_airport) {
        this.departure_airport = departure_airport;
    }

    public void setFdistance(double fdistance) {
        this.fdistance = fdistance;
    }

    public void setFlight_ID(int flight_ID) {
        this.flight_ID = flight_ID;
    }

    public String getArrival_airport() {
        return arrival_airport;
    }

    public String getDeparture_airport() {
        return departure_airport;
    }

    public double getFdistance() {
        return fdistance;
    }

    public int getFlight_ID() {
        return flight_ID;
    }

    public Date getDate_departure() {
        return date_departure;
    }

    public void setDate_departure(Date date_departure) {
        this.date_departure = date_departure;
    }

    @Override
    public String toString() {
        return flight_ID + ",\t" + flight_number + ",\t" + departure_airport + ",\t" + arrival_airport + ",\t"
                + date_departure + ",\t"
                + fdistance;
    }

    public String getFlight_number() {
        return flight_number;
    }

    public void setFlight_number(String flight_number) {
        this.flight_number = flight_number;
    }

}