public class Student extends Person {

    int currentYear;
    boolean hasSchoolarship;

    public Student(String firstname, String lastname, String email, Loan loan, int currentYear,
            boolean hasSchoolarship) {
        super(firstname, lastname, email, loan);
        this.currentYear = currentYear;
        this.hasSchoolarship = hasSchoolarship;
    }

    public Student(String first, String last, String email, int year, boolean schoolar) {
        super(first, last, email);
        this.currentYear = year;
        this.hasSchoolarship = schoolar;

        // TODO Auto-generated constructor stub
    }

    public int getCurrentYear() {
        return currentYear;
    }

    public void setCurrentYear(int currentYear) {
        this.currentYear = currentYear;
    }

    public boolean isHasSchoolarship() {
        return hasSchoolarship;
    }

    public void setHasSchoolarship(boolean hasSchoolarship) {
        this.hasSchoolarship = hasSchoolarship;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return super.toString() + ", currentYear=" + getCurrentYear() + ", has Schoolarship=" + isHasSchoolarship()
                + "\n";
    }

}
