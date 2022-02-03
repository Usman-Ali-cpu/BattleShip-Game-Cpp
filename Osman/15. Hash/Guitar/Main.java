import java.util.Scanner;

public class Main {

    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        Inventory invent = new Inventory();
        int schoice = -1;
        while (schoice != 6) {
            System.out.println("\n**************************");
            System.out.println("Enter 1. to Create Guitaar");
            System.out.println("Enter 2. to Charge Customer");
            System.out.println("Enter 3. to Ship Guitaar");
            System.out.println("Enter 4. to getReview Guitaar");
            System.out.println("Enter 5. to List Inventory");
            System.out.println("Enter 6. to Terminate");
            System.out.println("**************************\n");
            System.out.print("Enter choice: ");
            schoice = input.nextInt();

            switch (schoice) {
                case 1: {
                    System.out.println("Choose Color ");
                    System.out.print("Enter color of Guitar: ");
                    input.nextLine();
                    String color = input.nextLine();
                    System.out.println("Choose Size of Guitar");
                    System.out.println("Enter 1 For Small Size");
                    System.out.println("Enter 2 For Medium Size");
                    System.out.println("Enter 3 For Large Size");
                    System.out.print("Enter number : ");
                    int size = input.nextInt();
                    while (size > 3 && size < 1) {
                        System.out.print("Invalid choice! Enter number : ");
                        size = input.nextInt();
                    }

                    String strsize = getSize(size);

                    System.out.println("Choose Type of Guitar");
                    System.out.println("Enter 1 For Classic Acoustic Guitar");
                    System.out.println("Enter 2 For Flamenco Acoustic Guitar");
                    System.out.println("Enter 3 For Single Cut Electric Guitar");
                    System.out.println("Enter 4 For Stratocaster Electric Guitar");
                    System.out.print("Enter number : ");
                    int type = input.nextInt();
                    while (type > 4 && type < 1) {
                        System.out.print("Invalid choice! Enter number : ");
                        type = input.nextInt();
                    }
                    Guitar g = create(strsize, color, type);
                    invent.guitarList.add(g);
                }

                    break;
                case 2: {
                    System.out.print("Enter name of customer: ");
                    input.nextLine();
                    String customer = input.nextLine();
                    invent.chargeCustomer(customer);
                }
                    break;
                case 3: {
                    System.out.print("Enter name of customer: ");
                    input.nextLine();
                    String customer = input.nextLine();
                    invent.shipGuitar(customer);
                }

                    break;
                case 4: {
                    System.out.print("Enter name of customer: ");
                    input.nextLine();
                    String customer = input.nextLine();
                    invent.satisfied(customer);
                }

                    break;
                case 5: {
                    System.out.println("List of Guitars in Inventory");
                    System.out.println("*********************************");
                    invent.List();
                    System.out.println("*********************************\n");
                }
                    break;
                case 6: {
                    System.exit(0);
                }
                    break;

                default:
                    System.out.println("Invalid choice ");
                    break;
            }
        }

    }

    public static Guitar create(String size, String color, int type) {

        Guitar newGuitar = null;
        switch (type) {
            case 1:
                newGuitar = new ClassicAcoustic(size, color);
                input.nextLine();
                System.out.print("Enter your (Customer) Name : ");
                String customer = input.nextLine();
                newGuitar.customerName = customer;

                break;
            case 2:
                newGuitar = new FlamencoAcoustic(size, color);
                input.nextLine();
                System.out.print("Enter your (Customer) Name : ");
                String cust = input.nextLine();
                newGuitar.customerName = cust;

                break;
            case 3:
                newGuitar = new SingleCutElectric(size, color);
                input.nextLine();
                System.out.print("Enter your (Customer) Name : ");
                String custname = input.nextLine();
                newGuitar.customerName = custname;

                break;
            case 4:
                newGuitar = new StratocasterElectric(size, color);
                input.nextLine();
                System.out.print("Enter your (Customer) Name : ");
                String name = input.nextLine();
                newGuitar.customerName = name;

                break;

            default:
                System.out.println("Error! Method don't create Guitar");
                break;
        }
        return newGuitar;
    }

    public static String getSize(int n) {
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
