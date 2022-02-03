public class Student {
    String firstname;
    String lastname;
    int id;
    String dateofbirth;
    double grade;
    String email;

    public Student() {
        firstname = "";
        lastname = "";
        id = 0;
        dateofbirth = "";
        grade = 0;
        email = "";
    }

    public Student(String fname, String lname, int ID, String dob, double g, String em) {
        firstname = fname;
        lastname = lname;
        id = ID;
        dateofbirth = dob;
        grade = g;
        email = em;
    }

    public String getDateofbirth() {
        return dateofbirth;
    }

    public String getEmail() {
        return email;
    }

    public String getFirstname() {
        return firstname;
    }

    public double getGrade() {
        return grade;
    }

    public int getId() {
        return id;
    }

    public String getLastname() {
        return lastname;
    }

    public void setDateofbirth(String dateofbirth) {
        this.dateofbirth = dateofbirth;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public String getName() {
        return firstname + " " + lastname;

    }

    @Override
    public String toString() {
        return getFirstname() + " " + getLastname() + ", " + getEmail() + ", " + String.format("%.2f", getGrade());
    }

}