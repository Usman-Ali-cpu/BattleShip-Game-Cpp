
public class TV extends Product {

	/************
	 * Attributes
	 **************/

	String make, type;
	int screenSize;
	boolean is3D = false;

	/************
	 * Constructor
	 **************/

	public TV(String name, double price, String description, String make, String type, int screenSize, boolean is3d) {
		super(name, price, description);
		this.make = make;
		this.type = type;
		this.screenSize = screenSize;
		is3D = is3d;
	}

	/************
	 * Getter/Setter methods
	 **************/

	public String getMake() {
		return make;
	}

	public void setMake(String make) {
		this.make = make;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public int getScreenSize() {
		return screenSize;
	}

	public void setScreenSize(int screenSize) {
		this.screenSize = screenSize;
	}

	public boolean isIs3D() {
		return is3D;
	}

	public void setIs3D(boolean is3d) {
		is3D = is3d;
	}

	/************
	 * To String and Print
	 **************/

	public String toString() {
		return "TV [make=" + make + ", type=" + type + ", screenSize=" + screenSize + ", is3D=" + is3D
				+ ", getMake()=" + getMake() + ", getType()=" + getType() + ", Screen Size=" + getScreenSize()
				+ ", is 3D? -> " + isIs3D() + ", getProductID()=" + getProductID() + ", getPrice()=" + getPrice()
				+ ", getName()=" + getName() + ", getDescription()=" + getDescription() + ", toString()="
				+ super.toString() + ", getClass()=" + getClass() + ", hashCode()=" + hashCode() + "]";
	}

	public void print() {
		System.out.println(toString());

	}

}
