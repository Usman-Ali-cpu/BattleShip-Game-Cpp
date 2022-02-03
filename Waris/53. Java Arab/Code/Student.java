public class Student {
    String firstname; // member of type string for storing first name
    String lastname; // member of type string for storing last name
    int id; // member of type int for storing id
    String dateofbirth; // member of type string for storing date of birth
    double grade; // member of type double for storing grade
    String email; // member of type string for storing email

    public Student() { // contructor without parameter
        firstname = "";
        lastname = "";
        id = 0;
        dateofbirth = "";
        grade = 0;
        email = "";
    }

    public Student(String fname, String lname, int ID, String dob, double g, String em) { // contructor with
                                                                                          // parameters
        firstname = fname;
        lastname = lname;
        id = ID;
        dateofbirth = dob;
        grade = g;
        email = em;
    }

    public String getDateofbirth() { // getter for date of birth
        return dateofbirth;
    }

    public String getEmail() { // getter for email
        return email;
    }

    public String getFirstname() { // getter for first name
        return firstname;
    }

    public double getGrade() { // getter for grade
        return grade;
    }

    public int getId() { // getter for id
        return id;
    }

    public String getLastname() { // getter for last name
        return lastname;
    }

    public void setDateofbirth(String dateofbirth) { // setter for date of birth
        this.dateofbirth = dateofbirth;
    }

    public void setEmail(String email) { // setter for email
        this.email = email;
    }

    public void setFirstname(String firstname) { // setter for firt name
        this.firstname = firstname;
    }

    public void setGrade(double grade) { // setter for grade
        this.grade = grade;
    }

    public void setId(int id) { // setter for id
        this.id = id;
    }

    public void setLastname(String lastname) { // setter for last name
        this.lastname = lastname;
    }

    public String getName() { // to get full name
        return firstname + " " + lastname;

    }

    @Override
    public String toString() { // method return a string having data of members
        return getFirstname() + " " + getLastname() + ", " + getEmail() + ", " + String.format("%.2f", getGrade());
    }

}