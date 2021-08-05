import java.util.Scanner;

public class AreaPerimeter {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Radius for circle: ");
        int rad = input.nextInt();

        System.out.print("Enter length for rectangle: ");
        int len = input.nextInt();
        System.out.print("Enter width for rectangle: ");
        int wid = input.nextInt();
        System.out.println("Area of Rectangle is : " + areaOfReactangle(len, wid));
        System.out.println("Perimeter of Rectangle is : " + periOfRectangle(len, wid));
        System.out.println("Area of Circle is : " + areaOfCircle(rad));
        System.out.println("Perimeter of Circle is : " + periOfCircle(rad));

    }

    public static float areaOfCircle(int rad) {
        return (float) (3.14 * rad * rad);

    }

    public static float periOfCircle(int rad) {
        return (float) (2 * 3.14 * rad);

    }

    public static int areaOfReactangle(int len, int wid) {
        return len * wid;

    }

    public static int periOfRectangle(int len, int wid) {
        return (2 * (len + wid));
    }

}
