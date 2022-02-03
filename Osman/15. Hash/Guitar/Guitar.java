public abstract class Guitar {
    public String color;
    public String size;
    public String customerName;

    public Guitar() {
        size = "undefined";
        color = "undefined";
        customerName = "undefined";

    }

    public void playme() {
        System.out.println("Playing Guitar");
}

abstract String getType();
}