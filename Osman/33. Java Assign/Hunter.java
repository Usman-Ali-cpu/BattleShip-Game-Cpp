public class Hunter {
    String name;
    String color;
    int x;
    int y;

    Hunter(String n, String c) {
        name = n;
        color = n;

    }

    Hunter() {
        name = "default";
        color = "defualt";

    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;

    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getColor() {
        return color;
    }

    public String getName() {
        return name;
    }

    void move(Hunter obj) {
        System.out.println("Hunder is moving, X:" + x + "  Y:" + y);
        this.x = obj.x;
        this.y = obj.y;

    }

    void hunt(Board myborad) {
        System.out.println("Hunting " + myborad.getType());
        myborad.huntIndex(x++, y++);

    }

}