
public class Product {

	/************
	 * Attributes
	 **************/
	private static int IDCounter = 10214856;
	private int ProductID;
	private double price;
	private String name, description;

	/************
	 * Constructor
	 **************/

	public Product(String name, double price, String description) {

		// product ID =
		ProductID = IDCounter + 1;

		this.price = price;
		this.name = name;
		this.description = description;

		// increment IDCounter because there's a new product, next new product will have
		// an ID 1 higher than this.
		IDCounter++;
	}

	/************
	 * Getter/Setter methods
	 **************/

	public static int getIDCounter() {
		return IDCounter;
	}

	public static void setIDCounter(int iDCounter) {
		IDCounter = iDCounter;
	}

	public int getProductID() {
		return ProductID;
	}

	public void setProductID(int productID) {
		ProductID = productID;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	/************
	 * toString and Print methods
	 **************/

	public String toString() {
		return "Product ID=" + ProductID + ", price=" + price + ", name=" + name + ", description="
				+ description;
	}

	public void print() {
		System.out.println(toString());
	}

}
