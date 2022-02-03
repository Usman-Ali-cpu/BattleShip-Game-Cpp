import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Calculator {

    public static void main(String[] args) {
        int regularMinutesUsed, premiumDayMinutes, premiumNightMinutes;
        float totalBill = 0;

        float REGULAR_ACCOUNT_FEE = (float) 40.0;
        float REGULAR_RATE = (float) 1.5;
        float PREMIUM_ACCOUNT_FEE = (float) 100.00;
        float PREMIUM_DAY_RATE = (float) 0.75;
        float PREMIUM_NIGHT_RATE = (float) 0.25;

        BufferedReader reader;
        try {
            int num2 = 0;
            reader = new BufferedReader(new FileReader("bill.txt"));
            String line = reader.readLine();
            String name = line;
            System.out.println(line);
            line = reader.readLine();
            String type = line;
            System.out.println(line);
            line = reader.readLine();
            int num = Integer.parseInt(line);

            if (type.equals("P") || type.equals("p")) {
                line = reader.readLine();
                num2 = Integer.parseInt(line);
            }
            reader.close();
            switch (type) {
                case "r":
                case "R": {
                    regularMinutesUsed = num;
                    if (regularMinutesUsed > 50) {
                        totalBill = ((regularMinutesUsed - 50) * REGULAR_RATE) + REGULAR_ACCOUNT_FEE;
                    } else {
                        totalBill = REGULAR_ACCOUNT_FEE;
                    }
                    int extra = regularMinutesUsed - 50;
                    float amt = ((regularMinutesUsed - 50) * REGULAR_RATE);

                    try {
                        String filename = name + ".txt";
                        FileWriter fw = new FileWriter(filename);
                        fw.write("Regular Service\n");
                        fw.write("50 minutes are free for 40 AED\n");
                        String third = extra + " minutes as extra for " + extra + " * " + REGULAR_RATE + " = " + amt
                                + " AED\n";
                        String fourth = "Total Bill = " + totalBill + " AED\n";
                        fw.write(third);
                        fw.write(fourth);
                        fw.close();
                    } catch (Exception e) {
                        System.out.println(e);
                    }

                }

                    break;
                case "p":
                case "P": {

                    premiumDayMinutes = num;
                    premiumNightMinutes = num2;
                    if (premiumDayMinutes > 75) {
                        int e = premiumDayMinutes - 75;
                        if (e < 0) {
                            e = 0;
                        }
                        totalBill = (e) * PREMIUM_DAY_RATE;
                        System.out.println(totalBill);
                    }
                    if (premiumNightMinutes > 100) {
                        int e = premiumNightMinutes - 100;
                        totalBill = (e) * PREMIUM_NIGHT_RATE;
                    }
                    totalBill += PREMIUM_ACCOUNT_FEE;

                    int extra1 = (premiumDayMinutes - 75);
                    if (extra1 < 0) {
                        extra1 = 0;
                    }
                    float amt1 = (extra1) * PREMIUM_DAY_RATE;

                    int extra2 = (premiumNightMinutes - 100);
                    if (extra2 < 0) {
                        extra2 = 0;
                    }
                    float amt2 = (extra2) * PREMIUM_NIGHT_RATE;

                    try {
                        String filename = name + ".txt";
                        FileWriter fw = new FileWriter(filename);
                        fw.write("Premium Service\n");
                        fw.write("75 morning minutes & 100 evening minutes for free for 100 AED\n");
                        String third = extra1 + " minutes as extra for " + extra1 + " * " + PREMIUM_DAY_RATE + " = "
                                + amt1 + " AED\n";
                        String fourth = extra2 + " minutes as extra for " + extra2 + " * " + PREMIUM_NIGHT_RATE + " = "
                                + amt2 + " AED\n";
                        String fifth = "Total Bill = " + totalBill + " AED\n";
                        fw.write(third);
                        fw.write(fourth);
                        fw.write(fifth);
                        fw.close();
                    } catch (Exception e) {
                        System.out.println(e);
                    }
                }

                    break;
                default:
                    break;
            }

        } catch (

        IOException e) {
            e.printStackTrace();
        }

    }

}