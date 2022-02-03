import java.util.Scanner;

public class CreditCheck {
    Scanner in = new Scanner(System.in);
    double annualSalary;
    double creditRating;
    String name;

    public void getInfo() {
        System.out.println("Please enter your name ");
        this.name = in.nextLine();
        System.out.println("Please enter the salary for " + this.name);
        this.annualSalary = in.nextDouble();
        in.nextLine();
        System.out.println("Please enter the credit rating for " + this.name);
        this.creditRating = in.nextDouble();
        in.nextLine();
    }

    public Boolean getApproval() {
        if (this.creditRating >= 600 && this.annualSalary > 20000) {
            return true;
        } else
            return false;
    }

    public void printApproval() {
        System.out.println(this.name + " - Approved");
    }

    public void printDisapproval() {
        System.out.println(this.name + " - Disapproved");
    }

}
