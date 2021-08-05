import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;


public class Runner {
    static String directory = "accounts";

    public static void main(String []agrs) throws RuntimeException, IOException{
        Scanner input = new Scanner(System.in);
        Manager mana = new Manager(directory);

        while(true)
        {
            System.out.println("\n********************************* ");
            System.out.println("Enter 1 Open Account from File ");
            System.out.println("Enter 2 To Re-Active Account ");
            System.out.println("Enter 3 To In-Active Account");
            System.out.println("Enter 4 To Add Account");
            System.out.println("Enter 5 To Retrive Account");
            System.out.println("Enter 6 To Display All Accounts");
            System.out.println("Enter 7 To Get Prices of Transaction");
            System.out.println("Enter 8 To Exit");
            System.out.println("********************************* \n");
            
            int choice  = 0;
            System.out.print("Enter your choice : ");
            choice = input.nextInt();
            input.nextLine();

            switch (choice) {
                case 1:  
                {
                    System.out.print("Enter file Name to Open : ");
                    String fileName = input.nextLine();
                    System.out.print("Enter Acc ID : ");
                    String accid = input.nextLine();
                    mana.openFromFile(fileName, accid);
                }
                    break;
                case 2:  
                {
                    System.out.print("Enter Acc ID to re-Active account  : ");
                    String accid = input.nextLine(); // enter 123ABC
                    mana.reactivateInactiveAccount(accid);
                }
                break;
                case 3:  
                {
                    System.out.print("Enter Acc ID to re-Active account  : ");
                    String accid = input.nextLine(); // enter 123ABC
                    mana.inactivateExistingAccount(accid);
                }
                break;
                case 4:  
                {

                    File f = new File("123ABC", "account-123ABC.txt");
                    System.out.println("Enter Account ID : ");
                    String accid = input.nextLine(); // enter 123ABC
                    System.out.println("Enter Account Owner Name : ");
                    String name = input.nextLine(); // enter 123ABC
                    System.out.println("Enter Account mailing Address : ");
                    String mailingAddress = input.nextLine(); // enter 123ABC
                    System.out.println("Enter Account Email : ");
                    String email = input.nextLine(); // enter 123ABC
                    System.out.println("Enter Account owner's Phone : ");
                    String phoneNum = input.nextLine(); // enter 123ABC

                    Owner own = new Owner(name, mailingAddress, email, phoneNum);
                    Account acc = new Account(accid, own);
                    mana.addNewAccount(  acc );
                    System.out.println("Account has been Added Successfully");
                }
                break;
                case 5:  
                {
                    System.out.print("Enter Acc ID to retrive account  : ");
                    String accid = input.nextLine(); // enter 123ABC
                    Account acc = mana.retrieveAccount(accid);
                    System.out.println("\n" + acc.toString() + "\n");
                }
                break;
                case 6:  
                {
                    System.out.println("Printing Data of Accounts ");
                    Vector<Account> accObjects = mana.getAccObjects();
                    int i=0;
                    for(Account acc : accObjects){
                        System.out.println("Account " + i+1 + " : ");
                        System.out.println(acc.toString());
                    }
                }
                break;
                case 7:  
                {
                    System.out.println("Getting Price ");
                    Vector<Account> accObjects = mana.getAccObjects();
                    for(Account acc : accObjects){
                        for(Transaction trans : acc.getTransObjects())
                            System.out.println("Price Calaculated  for transaction "+trans.getTransId() + " : " + acc.calculatePrice(trans.getTransId()));
                    }
                }
                break;
                case 8:  
                {
                    System.out.println("Exiting Program");
                    System.exit(0);
                }
                break;
            
                default:
                    System.out.println("Invalid Value Entered !");
                    break;
            }
        }
    }
    
}
