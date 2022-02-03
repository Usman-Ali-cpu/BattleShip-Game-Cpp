// date class for storing date 
public class Dates {
    int year; // store year
    int month; // store month
    int day; // store day

    // paramterize constructor
    public Dates(int d, int m, int y) {
        this.day = d;
        this.year = y;
        this.month = m;
    }

    // getter
    public int getDay() {
        return day;
    }

    // getter
    public int getMonth() {
        return month;
    }

    // getter
    public int getYear() {
        return year;
    }

    // setter
    public void setDay(int day) {
        this.day = day;
    }

    // setter
    public void setMonth(int month) {
        this.month = month;
    }

    // setter
    public void setYear(int year) {
        this.year = year;
    }

    // get string of date
    public String toString() {
        return String.valueOf(year) + " " + String.valueOf(month) + " " + String.valueOf(day);
    }

    // get date in string
    public String getString() {
        return String.valueOf(year) + "." + String.valueOf(month) + "." + String.valueOf(day);
    }
}
