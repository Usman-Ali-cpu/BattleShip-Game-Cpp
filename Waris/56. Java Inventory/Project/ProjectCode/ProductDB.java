
import java.util.ArrayList;

public class ProductDB {

	/************
	 * Attributes
	 **************/

	ArrayList<Product> list = new ArrayList<Product>();

	/************
	 * Constructor
	 **************/

	public ProductDB() {
		list = new ArrayList<Product>();
	}

	/************
	 * Methods
	 **************/

	// add

	public void add(Product a) {
		this.list.add(a);

	}

	// remove

	public void remove(Product p) {
		this.list.remove(p);
		System.out.println(p + " has been removed");
	}

	// find

	public Product find(int searchID) {

		// set and initialize product to be returned.
		Product p = null;

		// this for loop searches through the ArrayList for a product ID that matches
		// the product ID of p, which changes on each iteration of loop
		for (int i = 0; i < list.size(); i++) {

			p = this.list.get(i);

			if (p.getProductID() == searchID) {
				return p;
			}

		}

		if (p == null) {
			System.out.println("productID not found");
			return null;
		}

		return p;

	}

	// getAll

	public void getAll() {

		for (int i = 0; i < this.list.size(); i++) {
			System.out.println(this.list.get(i));
		}

	}

}
