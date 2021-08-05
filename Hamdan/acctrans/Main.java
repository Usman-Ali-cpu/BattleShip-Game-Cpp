import java.io.File;
import java.io.IOException;

public class Main {
    public static void main(String []args) throws Exception{
        // Manager mana = new Manager("123ABC");

        // mana.openFromFile("account-123ABC.txt", "123ABC");
        File f = new File("123ABC", "account-123ABC.txt");
        Account acc = new Account(f);
        System.out.println("acc.getAccId()");
        System.out.println(acc.getAccId());
        System.out.println(acc.toString());
        System.out.println(acc.getOwner().toString());
        System.out.println(acc.getStatus());
        System.out.println("acc.getAccId()");
        System.out.println("size constructro :  " + acc.getSize());
        // acc.openFromTransFile(fileName, transId);
        // acc.openFromTransFile("123ABC/account-123ABC.txt" , "0023-123ABC");
        System.out.println(acc.calculatePrice("0023-123ABC"));
        System.out.println("I am 18 ");
        Transaction trans = new Rent("<rent><transId>0025-123ABC</transId><date>07/01/2021</date><description>holidayinn</description><status>true</status><transactionCost>2.99</transactionCost><numOfDays>2</numOfDays><rentDailyRate>50.00</rentDailyRate></rent>");
        acc.addTransactionToAccount(trans);
        System.out.println("hehehe : "+acc.getTransObjects().get(0).getTransId());
        acc.completeTransaction("0023-123ABC");
        acc.removeDraftTransactionFromAccount("0023-123ABC");


        

    }
}
