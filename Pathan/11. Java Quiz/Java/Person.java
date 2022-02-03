public class Person {
    String firstname;
    String lastname;
    String email;
    Loan loan;

    public Person(String firstname, String lastname, String email, Loan loan) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.email = email;
        this.loan = loan;
    }

    public Person(String first, String last, String email) {
        this.email = email;
        this.firstname = first;
        this.lastname = last;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public String getEmail() {
        return email;
    }

    public String getFirstname() {
        return firstname;
    }

    public String getLastname() {
        return lastname;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return "firstname=" + getFirstname() + ", lastname=" + getLastname() + ", email=" + getEmail() + ", LoanBook="
                + loan.toString() + "\n";
    }

    public Loan getLoan() {
        return loan;
    }

    public void setLoan(Loan loan) {
        this.loan = loan;
    }
}