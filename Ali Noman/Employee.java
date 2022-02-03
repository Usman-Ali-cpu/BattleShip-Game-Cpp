public class Employee {
    private String name;
    private double hourlyRate;
    private double hoursWorked;

    public Employee(String name, double hourlyRate, double hoursWorked) {
        this.name = name;
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    public Employee() {
        name = "Defualt";
        hourlyRate = 0;
        hoursWorked = 0;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getHourlyRate() {
        return hourlyRate;
    }

    public void setHourlyRate(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }

    public double getHoursWorked() {
        return hoursWorked;
    }

    public void setHoursWorked(double hoursWorked) {
        this.hoursWorked = hoursWorked;
    }

    public final double weeklypay() {
        if (hoursWorked > 40) {
            return hoursWorked * (1.5 * hourlyRate);
        }
        return hoursWorked * hourlyRate;
    }

    public void print() {
        System.out.println("Name: " + getName() + ",\thourlyrate: " + getHourlyRate() + ",\thoursworked: "
                + getHoursWorked() + ",\tweekly pay: " + weeklypay());
    }

}
