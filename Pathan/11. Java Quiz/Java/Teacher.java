public class Teacher extends Person {
    int taxFileNumber;
    String qualification;

    public Teacher(String firstname, String lastname, String email, Loan loan, int taxFileNumber,
            String qualification) {
        super(firstname, lastname, email, loan);
        this.taxFileNumber = taxFileNumber;
        this.qualification = qualification;
    }

    public Teacher(String first, String last, String email, int taxFileNumber,
            String qualification) {
        super(first, last, email);
        this.taxFileNumber = taxFileNumber;
        this.qualification = qualification;
    }

    public int getTaxFileNumber() {
        return taxFileNumber;
    }

    public void setTaxFileNumber(int taxFileNumber) {
        this.taxFileNumber = taxFileNumber;
    }

    public String getQualification() {
        return qualification;
    }

    public void setQualification(String qualification) {
        this.qualification = qualification;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return super.toString() + ", taxFileNumber=" + this.taxFileNumber + ", qualification=" + this.qualification
                + "\n";
    }

}
