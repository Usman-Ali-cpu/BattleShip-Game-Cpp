import java.util.Scanner;

public class Question1{
    public static void main(String []args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Profit of a Company : ");
        int profit = input.nextInt(); // Enter profit of comapny
        String catagory = ""; // from profit , we will assume catagory of company
        if(profit <= 5000){ // if profit is less than 5000
            catagory = "small"; // catagory of company will be small 
        }
        else if(profit > 5000 && profit <= 10000){ // if profit is graeter than 5000 and less than equal to 10000
            catagory = "medium"; // catagory of company will be meduim
        }
        else { // if profit is greater than 10000
            catagory = "large"; // catagory of company will be large
        }
        float sumTax = computeTaxes(profit, catagory); // getting tax
        float refuseTax = (float) (0.02 * sumTax); // extra refuse tax
        float totalTax = sumTax + refuseTax; // suming for total tax
        System.out.println("Catagory : " + catagory);
        System.out.println("Tax Before Refuse : " +  String.format("%.2f", sumTax));
        System.out.println("Refuse Tax: " + String.format("%.2f", refuseTax));
        System.out.println("Total Tax: " +  String.format("%.2f", totalTax));
        input.close();
    }

    public static float computeTaxes(int GHs, String catagory){ // passing profit in Ghs and catagory as parameter
        float tax = 0;
        if(catagory.equals("small")){ // if catagory of company is small
            if(GHs <= 3000){
                tax = (float) (0.03 * GHs); // if profit is less than equal to 3000, then tax is 3.3%
            }
            else{
                tax = (float) (0.05 * GHs);
            }
        }
        else if(catagory.equals("medium")){ // if catagory of company is meduim
            if(GHs <= 8000){
                tax = (float) (0.05 * GHs); // if profit is less than equal to 8000, then tax is 5.5%
            }
            else{
                tax = (float) (0.08 * GHs);
            }
            
        }
        else if(catagory.equals("large")){ // if catagory of company is large
            if(GHs <= 15000){ 
                tax = (float) (0.085 * GHs); // if profit is less than equal to 1500, then tax is 8.5%
            }
            else{
                tax = (float) (0.12 * GHs);
            }
        }
        return tax; // return calculated tax

    }
}