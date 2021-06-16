public class Employee {

    private String name;
    private int strength;
    private static int empcount = 0;

    public Employee() {
        this.name = "Unknown";
        this.strength = 0;
        empcount++;
    }

    public Employee(String n, int s) {
        this.name = n;
        this.strength = s;
        empcount++;
    }

    public void setName(String n) {
        this.name = n;
    }

    public void setStrength(int s) {
        this.strength = s;
    }

    public String getName() {
        return this.name;
    }

    public int getStrength() {
        return this.strength;
    }

    public int getNumberofEmployees() {
        return this.empcount;
    }

    public String toString(){
        return "Employee {name =  " + this.getName() + ", Strength:  " + this.getStrength() + "}\n";
    }
}
