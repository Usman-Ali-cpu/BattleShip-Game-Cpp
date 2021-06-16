public class Simple extends Room {

    int m2;
    int price;

    Simple() {
        super();
        m2 = 0;
        type = "simple";    
        price = 0;
    }

    Simple(int m, int p, int n) {
        super(n);
        m2 = m;
        price = p;
        type = "simple";
    }
    
    public void PrintRoom() {
        System.out.println("Room Number : " + number);
        System.out.println("Room Type : " + type);
        System.out.println("Room Price : " + price);
        System.out.println("Room Dimension  : " + this.m2);
        System.out.println("\n");
    }
    
}
