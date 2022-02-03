package IC10;

public class Student {
    private String name;
    private String major;
    private double gpa;
    private int hours;

    public Student() {
        name = "Not set";
        major = "Not decided";
        gpa = 0;
        hours = 0;
    }

    public Student(String name, String major, double gpa, int hours) {
        this.name = name;
        this.major = major;
        this.gpa = gpa;
        this.hours = hours;
    }

    public String getName() {
        return name;
    }

    public boolean setName(String name) {
        boolean valid = false;
        if (name.length() > 3) {
            valid = true;
            this.name = name;
        }
        return valid;
    }

    public String getMajor() {
        return major;
    }

    public boolean setMajor(String major) {
        boolean valid = false;
        if (!major.isBlank()) {
            valid = true;
            this.major = major;
        }
        return valid;

    }

    public double getGpa() {
        return gpa;
    }

    public boolean setGpa(double gpa) {
        boolean valid = gpa > 0 && gpa <= 4;
        if (valid) {
            this.gpa = gpa;
        }
        return valid;
    }

    public int getHours() {
        return hours;
    }

    public boolean setHours(int hours) {
        boolean valid = hours >= 0 && hours <= 17;
        if (valid) {
            this.hours = hours;
        }
        return valid;
    }

    public String toString() {
        return name + "\t\t" + major + "\t\t" + gpa + "\t\t" + hours;
    }
}
