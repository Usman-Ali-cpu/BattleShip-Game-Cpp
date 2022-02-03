import static java.lang.Math.*;

public class Mai {

    public static void main(String[] args) {
        Circle c = new Circle();
        c.runTasks();
        Triangle t = new Triangle();
        t.runTasks();

    }

}

abstract class Shape {
    public abstract String toString();

    public abstract void runTasks();

    public abstract double area();

    public abstract double peri();
}

class Circle extends Shape {
    double radius;

    public Circle() {
        this(0.0);
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public String toString() {
        return String.format("Circle(r=%.2f)", radius);
    }

    public double radius() {
        return radius;
    } // double radius() const;

    public void setRadius(double radius) {
        this.radius = radius;
    } // void radius(double radius);

    public double area() {
        return PI * radius * radius;
    } // PI comes from java.lang.Math

    public double peri() {
        return 2.0 * PI * radius;
    }

    public void runTasks() {
        Circle c = new Circle();
        System.out.println("c is: " + c);

        // Circle c2 = new Circle(5.0, new Point(3, 4));
        // System.out.println("c is: " + c2);

        Circle c3 = new Circle(10);
        System.out.println("c2 is: " + c3);

        c3.setRadius(3.0);
        System.out.println("c3 is now: " + c3);

        System.out.println("c3's radius is: " + c3.radius());

    }
}

class Triangle extends Shape {
    double x;
    double y;
    double z;

    public Triangle() {
        this(0.0, 0.0, 0.0);
    }

    public Triangle(double b, double h, double i) {
        this.x = b;
        this.y = h;
        this.z = i;
    }

    public String toString() {
        return String.format("Triangle(x=%.2f, y=%.2f, z=%.2f)", this.x, this.y, this.z);
    }

    public double x() {
        return this.x;
    }

    public void setx(double x) {
        this.x = x;
    }

    public double y() {
        return this.y;
    } // double radius() const;

    public void sety(double y) {
        this.y = y;
    } // void radius(double radius);

    public double z() {
        return this.z;
    }

    public void setz(double z) {
        this.z = z;
    }

    public double area() {
        double s = (x + y + z) / 2;
        return Math.sqrt(s * (s - x) * (s - y) * (s - z));
    } // PI comes from java.lang.Math

    public double peri() {
        return x + y + z;
    }

    public void runTasks() {
        Triangle t = new Triangle();
        System.out.println("t is: " + t);

        Triangle c2 = new Triangle(5.0, 6.0, 4.0);
        System.out.println("t is: " + c2);

        Triangle t3 = new Triangle(10, 12, 15);
        System.out.println("t2 is: " + t3);

        t3.setx(3.0);
        t3.sety(2.0);
        t3.setz(4.0);
        System.out.println("t3 is now: " + t3);

        System.out.println("t3's x is: " + t3.x());
        System.out.println("t3's y is: " + t3.y());
        System.out.println("t3's z is: " + t3.z());

    }

}
