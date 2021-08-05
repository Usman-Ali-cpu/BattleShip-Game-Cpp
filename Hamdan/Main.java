import java.util.concurrent.ExecutionException;


public class Main {
    public static void main(String []args) throws Exception{
        // String line = "<purchase><transId>0023-123ABC</transId><date>07/01/2021</date><description>handbag</description><status>true</status><transactionCost>2.99</transactionCost><numOfItems>2</numOfItems><pricePerItem>25.55</pricePerItem></purchase>";
        // Transaction trans = new Purchase(line);

        // System.out.println(trans.getTransId());
        // System.out.println(trans.getDescription());
        // System.out.println(trans.getStatus());
        // System.out.println(trans.getDate());
        // System.out.println(trans.getDate());

        // String line = "<rent><transId>0025-123ABC</transId><date>07/01/2021</date><description>holidayinn</description><status>true</status><transactionCost>2.99</transactionCost><numOfDays>2</numOfDays><rentDailyRate>50.00</rentDailyRate></rent>";
        // Transaction trans = new Rent(line);
        // System.out.println(trans.toString());

        // String line = "<travel><transId>0026-123ABC</transId><date>07/01/2021</date><description>UstoIndia</description><status>true</status><transactionCost>2.99</transactionCost><travelCost>1100.00</travelCost></travel>";
        // Transaction trans = new Travel(line);
        // System.out.println(trans.toString());


        // String line = "<owner><name> User7aman1</name><mailingAddress> MainSt1Apt1</mailingAddress><email> user1@gmail.com</email><phoneNum>111-111-1111</phoneNum></owner>";
        // Owner trans = new Owner(line);
        // System.out.println(trans.toString());
        // System.out.println(trans.getMailingAddress());
        // System.out.println(trans.getName());


        // String filename = "accounts/account-123ABC.txt";
        // try{
        //     Account acc = new Account(filename);
        //     System.out.println(acc.toString());
        //     // acc.removeDraftTransactionFromAccount("0023-123ABC");
        //     acc.addTransactionToAccount(trans);
        //     // System.out.println(acc.getTransObjects().get(0).status);
        //     System.out.println(acc.getTransObjects().size());
        //     // acc.completeTransaction("0023-123ABC");

        //     // System.out.println(acc.calculatePrice("0023-123ABC"));
        //     // acc.openFromTransFile(filename, "0023-123ABC");
        // }
        // catch(ExecutionException e){

        // }

        String directory = "accounts";
        Manager mana = new Manager(directory);

        mana.openFromFile("account-123ABC.txt", "123ABC");
        





        

    }
    
}
