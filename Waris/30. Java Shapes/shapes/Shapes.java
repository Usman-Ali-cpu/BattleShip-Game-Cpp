
import static java.lang.Math.*;
import javax.swing.JOptionPane;

public class Shapes {
  public static void main(String[] args) {
    System.out.println("Point");
    Point.runTests();
    System.out.println("Circle");
    Circle.runTests();
    System.out.println("Triangle");
    Triangle.runTasks();

  }
}

abstract class Shape {
  Point center;

  public Shape() {
    center = new Point();
  }

  public Shape(Point p) {
    center = p;
  }

  public String toString() {
    return "Center of Shape is : " + center.toString();
  }

  public Point center() {
    return center;
  }

  public void setCenter(Point c) {
    center = c;
  }

}

class Point {
  public Point() {
    this(0.0, 0.0);
  }

  public Point(double x, double y) {
    this.x = x;
    this.y = y;
  }

  public String toString() {
    return "Point(" + x + "," + y + ")";
  }

  public double distance(Point other) { // in C++ Point& other
    double deltaX = x - other.x;
    double deltaY = y - other.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
  }

  public double x() {
    return x;
  }

  public double y() {
    return y;
  };

  public void setX(double x) {
    this.x = x;
  }

  public void setY(double y) {
    this.y = y;
  }

  public static void runTests() {
    Point pt = new Point(); // don't just say Point pt; you will have a reference to null
    Point pt2 = new Point(2, 3);

    System.out.println("pt is: " + pt);
    System.out.println("pt2 is: " + pt2);
    System.out.println("distance from " + pt + " to  " + pt2 + " is " + String.format("%.2f", pt.distance(pt2)));
  }

  private double x;
  private double y;
}

//// ------------------------------------------------------------------------------
////
class Circle extends Shape { // default ctor
  public Circle() {
    this(0.0);
  }

  public Circle(double radius) {
    this.radius = radius;
    center = new Point();
  }

  public Circle(double radius, Point p) {
    this(radius);
    this.center = p;
  }

  public String toString() {
    return String.format("Circle(r=%.2f, %s)", radius, super.toString());
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

  public static void runTests() { // now this is a Circle class method

    Circle c = new Circle();
    System.out.println("c is: " + c);

    Circle c2 = new Circle(5.0, new Point(3, 4));
    System.out.println("c is: " + c2);

    Circle c3 = new Circle(10);
    System.out.println("c2 is: " + c3);

    c3.setRadius(3.0);
    System.out.println("c3 is now: " + c3);

    System.out.println("c3's radius is: " + c3.radius());

    System.out.println("c3's center=" + c3.center());

    c2.setCenter(new Point(999, -999));
    System.out.println("After c2.setCenter(999, -999), c2's center=" + c2.center());

  }

  private double radius;
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
    return String.format("Triangle(x=%.2f, y=%.2f, z=%.2f) ", this.x, this.y, this.z) + super.toString();
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
  }

  public double peri() {
    return x + y + z;
  }

  public static void runTasks() {
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