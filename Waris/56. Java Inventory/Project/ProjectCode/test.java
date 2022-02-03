
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class test {
	static ProductDB Database = new ProductDB();
	static Customer Mary;

	public static void main(String[] args) {

		/************************
		 * create products
		 *************************/

		// creating 3 phone objects
		Phone p = new Phone("HTC MATE 5", 235, "5th gen Mate", "HTC", "Mate5", 16);
		Phone p1 = new Phone("Apple iphone 6", 679, "6th gen iphone", "iphone", "6", 64);
		Phone p2 = new Phone("samsung galaxy s8", 899, "8th generation galaxy flagship samsung phone", "Samsung",
				"Galaxy s8", 128);

		/************************
		 * add products to Database
		 *************************/
		Database.add(p);

		Database.add(p1);

		Database.add(p2);

		/************************
		 * create Customer, add orders to customer and test
		 *************************/

		Mary = new Customer("Mary", "Mary's house, Cork");
		List<Customer> listcus = new ArrayList<Customer>();

		// System.out.println("---test: is mary created?---------");
		// Mary.print();

		// create 2 orderDetails objects

		OrderDetails o1 = new OrderDetails(p.getName(), 2);
		OrderDetails o2 = new OrderDetails(p1.getName(), 1);

		// System.out.println("---test: have items been added to mary?---------");
		// Mary.print();
		Mary.addOrder(o1);
		Mary.addOrder(o2);
		// Mary.print();
		OrderDetails o3 = new OrderDetails(p2.getName(), 3);

		Mary.addOrder(o3);

		// System.out.println("---test: final result of Mary?---------");
		// Mary.print();

		/************************
		 * User Menu
		 * 
		 *************************/

		Scanner sc = new Scanner(System.in);

		while (true) {
			printMenu();

			String s = sc.nextLine();
			while (!checkinput(s)) {
				System.out.println("Invalid Input Exception!\n");
				printMenu();
				s = sc.nextLine();
			}
			int i = Integer.parseInt(s);

			switch (i) {

				case 1: // create new phone
					// Phone(String name, double price, String description, String make, String
					// model, int storageSpace)

					System.out.println("---creating a new phone---");

					System.out.println("Enter name of phone");
					String name = sc.nextLine();

					System.out.println("Enter description of phone");
					String description = sc.nextLine();

					System.out.println("Enter make");
					String make = sc.nextLine();

					System.out.println("Enter model");
					String model = sc.nextLine();

					System.out.println("Enter Storage capacity in GB");
					int storageSpace = sc.nextInt();
					sc.nextLine();

					System.out.println("Enter price");
					double price = sc.nextDouble();

					Phone newPhone = new Phone(name, price, description, make, model, storageSpace);
					// Phone(String name, double price, String description, String make, String
					// model,int storageSpace)
					Database.add(newPhone);

					break;

				case 2: // search by product ID
					int searchID;
					System.out.println("---Search for product---");

					System.out.println("Enter product ID"); // p2's productID = 10214859
					searchID = sc.nextInt();

					System.out.println(Database.find(searchID));

					break;

				case 3: // Display all products
					System.out.println("---Displaying all products---");
					Database.getAll();

					break;

				case 4: // order products
					System.out.println("---Ordering Products---");

					System.out.println("Enter product name"); // p2's productID = 10214859
					String addname = sc.nextLine();

					System.out.println("Enter Quantity to order");
					int amount = sc.nextInt();
					sc.nextLine();

					OrderDetails o = new OrderDetails(addname, amount);

					Mary.addOrder(o);

					break;

				case 5: // display all orders
					System.out.println("---Displaying your orders for: Mary---");
					Mary.getOrders();

					break;

				case 6: // create customer
					System.out.println("Enter customer name : ");
					String cusname = sc.nextLine();
					System.out.println("Enter customer ID : ");
					String ID = sc.nextLine();
					Customer c = new Customer(cusname, ID);
					listcus.add(c);
					int j = 1;
					if (listcus.size() > 0) {
						for (Customer cc : listcus) {
							System.out.println(j++ + ". " + cc.toString());
						}
						System.out.println("Enter choice number : ");
						int num = sc.nextInt();
						sc.nextLine();

						Customer Mary = listcus.get(num - 1);
						System.out.println(Mary.toString());

					} else {

						System.out.println("No other customer is here ");
					}

					break;

				case 7: // quit
					System.out.println("---Quitting---");
					System.out.println("Goodbye");
					System.exit(0);
					break;// good practice to close cases.

			}

		}

	}

	public static void printMenu() {
		System.out.println();
		System.out.println("--------Menu---------");
		System.out.println();
		System.out.println("Please Enter a menu option");
		System.out.println("1: Create a new (phone or TV).");
		System.out.println("2: Search for a product by supplying the productid");
		System.out.println("3: Display all Products");
		System.out.println(
				"4: Allow a customer to order some products by supplying the productID and quantity for each product.");
		System.out.println(
				"5. Display all the orders that a customer has made and all the OrderDetails that are in each order.");
		System.out.println("6. Create a new customer.");
		System.out.println("7: Quit");
	}

	public static boolean checkinput(String str) {
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if (!Character.isDigit(c)) {
				return false;
			}
		}
		return true;
	}

}
