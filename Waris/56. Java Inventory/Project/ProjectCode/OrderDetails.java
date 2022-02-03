
public class OrderDetails {

	/********************
	 * Attributes
	 **********************/

	int product, quantity;
	String productname;

	/********************
	 * Constructor
	 **********************/

	public OrderDetails(String product, int quantity) {
		this.productname = product;
		this.quantity = quantity;
	}

	/****************************
	 * Getter/Setter methods
	 ******************************/
	public String getproductname() {
		return productname;
	}

	public void setproductname(String productname) {
		this.productname = productname;
	}

	public int getQuantity() {
		return quantity;
	}

	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}

	/****************************
	 * print method
	 ******************************/

	public String toString() {
		return quantity + " " + productname;
	}

	public void print() {
		System.out.println(this.toString());
	}

}
