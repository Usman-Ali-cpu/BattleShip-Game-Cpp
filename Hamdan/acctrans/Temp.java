import java.util.Vector;

public class Temp {

    public static void main(String []args) throws Exception{
        
        String line = "<rent><transId>0025-123ABC</transId><date>07/01/2021</date><description>holidayinn</description><status>true</status><transactionCost>2.99</transactionCost><numOfDays>2</numOfDays><rentDailyRate>50.00</rentDailyRate></rent>";
        String s = line.substring(line.indexOf("<numOfDays>") + 11, line.indexOf("</numOfDays>")); 
        System.out.println(s);
        //acc.addTransactionToAccount(trans);
        Vector <Integer> t = new Vector<Integer>();
        t.add(1);
        t.add(2);
        t.add(3);
        t.add(4);
        System.out.print(t.size());
        


        

    }
    
}
