public class Double extends Room{

    int m2;
    int price;
    String typeBed;

    Double() {
        super();
        this.m2 = 0;
        this.price = 0;
        this.typeBed = "Unkown";
        type = "double";
    }

    Double(int price, int m, String t, int n) {
        super(n);
        this.m2 = m;
        this.price = price;
        this.typeBed = t;
        type = "double";
    }
    public void PrintRoom() {
        System.out.println("Room Number : " + number);
        System.out.println("Room Type : " + type);
        System.out.println("Room Price : " + price);
        System.out.println("Room Dimension  : " + this.m2);
        System.out.println("Type bed  : " + this.typeBed);
        System.out.println("\n");
    }
    
}
