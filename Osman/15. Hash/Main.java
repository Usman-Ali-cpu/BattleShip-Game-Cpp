import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Choose Color ");
        System.out.print("Enter color of Guitar: ");
        String color = input.nextLine();
        System.out.println("Choose Size of Guitar");
        System.out.println("Enter 1 For Small Size");
        System.out.println("Enter 2 For Medium Size");
        System.out.println("Enter 3 For Large Size");
        System.out.print("Enter number : ");
        int size = input.nextInt();

        System.out.println("Choose Type of Guitar");
        System.out.println("Enter 1 For Classic Acoustic Guitar");
        System.out.println("Enter 2 For Flamenco Acoustic Guitar");
        System.out.println("Enter 3 For Single Cut Electric Guitar");
        System.out.println("Enter 4 For Stratocaster Electric Guitar");
        int type = input.nextInt();

        switch (type) {
            case 1:
                



                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;

            default:
                break;
        }

    }

    public String getSize(int n) {
        String size = "";
        switch (n) {
            case 1:
                size = "Small";

                break;
            case 2:
                size = "Medium";

                break;
            case 3:
                size = "Large";
                break;

            default:
                break;
        }
        return size;
    }

}
