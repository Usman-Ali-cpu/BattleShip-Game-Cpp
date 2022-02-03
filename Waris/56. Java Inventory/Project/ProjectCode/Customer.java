
import java.util.ArrayList;

public class Customer {

	/************
	 * Attributes
	 **************/
	String name, address;
	ArrayList<OrderDetails> Orders = new ArrayList<OrderDetails>();

	/************
	 * Constructor
	 **************/

	public Customer(String name, String address) {
		this.name = name;
		this.address = address;
	}

	/************
	 * Getter/Setter methods
	 **************/

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	/************
	 * Orders methods
	 **************/

	public void addOrder(OrderDetails a) {
		this.Orders.add(a);
		System.out.println(a + " has been added to orders");
	}

	public void removeOrder(OrderDetails a) {
		this.Orders.remove(a);
		System.out.println(a + " has been removed from orders");
	}

	public void getOrders() {

		for (int i = 0; i < this.Orders.size(); i++) {
			System.out.println("Order " + (i + 1) + ": ");
			System.out.println(this.Orders.get(i));
		}

	}

	/************
	 * toString and Print methods
	 **************/

	public String toString() {
		return "Customer name=" + name + ", address=" + address + ", Orders=" + Orders;
	}

	public void print() {
		System.out.println(toString());
	}

}
