import java.util.ArrayList;

public class Inventory {
    public ArrayList<Guitar> guitarList = new ArrayList<Guitar>();

    public void chargeCustomer(String customer) {
        for (Guitar g : guitarList) {
            if (g.customerName.equals(customer)) {
                System.out.println(customer + " has been charged for a Guitar of type " + g.getType());
                return;
            }
        }
        System.out.println("Customer is not found");
    }

    public void shipGuitar(String customer) {
        for (Guitar g : guitarList) {
            if (g.customerName.equals(customer)) {
                System.out.println(customer + "'s Guitar has been Shipped of type " + g.getType());
                return;
            }
        }

        System.out.println("Customer is not found");

    }

    public void satisfied(String customer) {
        for (Guitar g : guitarList) {
            if (g.customerName.equals(customer)) {
                System.out.println(customer + "'s Guitar is statified with guitar of type " + g.getType());
                return;
            }
        }
        System.out.println("Customer is not found");
    }

    public void List() {
        if (guitarList.size() <= 0) {
            System.out.println("No Invertory!");
        } else {
            for (Guitar g : guitarList) {
                System.out.print("------------------------\n");
                System.out.println("Guitar of type " + g.getType());
                System.out.println("Guitar Size : " + g.size);
                System.out.println("Guitar color : " + g.color);
                System.out.println("Customer : " + g.customerName);
                System.out.print("------------------------\n");
            }
        }
    }

}
