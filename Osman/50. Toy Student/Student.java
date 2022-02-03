public class Student {

    String name;
    String student_class;
    double gpa;

    public Student() {
        name = "not set";
        student_class = "Freshman";
        gpa = 0;
    }

    public Student(String a_name, String a_class, double a_gpa) {
        name = a_name;
        student_class = a_class;
        gpa = a_gpa;
    }

    public void setGpa(double gpa) {
        this.gpa = gpa;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setStudent_class(String student_class) {
        this.student_class = student_class;
    }

    public double getGpa() {
        return gpa;
    }

    public String getName() {
        return name;
    }

    public String getStudent_class() {
        return student_class;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        String strname = "Student name is " + getName() + "\n";
        String strclass = getName() + "'s class is " + getStudent_class() + "\n";
        String strgpa = getName() + "'s gpa is " + getGpa();
        return strname + strclass + strgpa;
    }

}
