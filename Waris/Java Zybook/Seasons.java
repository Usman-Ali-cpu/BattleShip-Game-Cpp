
import java.util.Scanner;

public class Seasons {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the month: ");

        String mon = getMonth(in);
        String[] mo = mon.split(" ");
        mon = mo[0];
        System.out.print("Enter day: ");
        int day = getDay(in);

        if (mon.equalsIgnoreCase("april")) {
            String season = calcSeason(mon, day);
            displaySeason(season);

        } else {
            if (!validInput(mon, day)) {
                System.out.println("\nInvalid date. Program cannot continue.");
            }

            if (validInput(mon, day)) {
                String season = calcSeason(mon, day);
                displaySeason(season);
            }

        }

        // Type your code here.

    }

    public static String getMonth(Scanner console) {
        String month = console.nextLine();
        return month;

    }

    public static int getDay(Scanner console) {
        int day = console.nextInt();
        return day;

    }

    public static boolean validInput(String inputMonth, int inputDay) {
        String month = inputMonth.toLowerCase();
        if (month.equals("january") && (inputDay <= 31 && inputDay > 0)) {
            return true;
        }
        if (month.equals("feburary") && (inputDay <= 28 && inputDay>0)) {
            return true;
        }
        if (month.equals("march") && (inputDay <= 31 && inputDay > 0)) {
            return true;
        }
        if (month.equals("april") && (inputDay <= 30 && inputDay > 0)) {
            return true;
        }
        if (month.equals("may") && (inputDay <= 31 && inputDay > 0)) {
            return true;
        }
        if (month.equals("june") && (inputDay <= 30 && inputDay > 0)) {
            return true;
        }
        if (month.equals("july") && (inputDay <= 31 && inputDay > 0)) {
            return true;
        }
        if (month.equals("august") && (inputDay <= 31 && inputDay > 0)) {
            return true;
        }
        if (month.equals("september") && (inputDay <= 30 && inputDay > 0)) {
            return true;
        }
        if (month.equals("october") && (inputDay <= 31 && inputDay > 0)) {
            return true;
        }
        if (month.equals("november") && (inputDay <= 30 && inputDay > 0)) {
            return true;
        }
        if (month.equals("december") && (inputDay <= 31 && inputDay > 0)) {
            return true;
        }
        return false;

    }

    public static String calcSeason(String inputMonth, int inputDay) {
        if ((inputMonth.equalsIgnoreCase("january")) || (inputMonth.equalsIgnoreCase("feburary"))) {
            return "winter";
        } else if ((inputMonth.equalsIgnoreCase("april")) || (inputMonth.equalsIgnoreCase("may"))) {
            return "spring";
        } else if ((inputMonth.equalsIgnoreCase("july")) || (inputMonth.equalsIgnoreCase("august"))) {
            return "summmer";
        } else if ((inputMonth.equalsIgnoreCase("october")) || (inputMonth.equalsIgnoreCase("november"))) {
            return "fall";
        } else if ((inputMonth.equalsIgnoreCase("march")) && (inputDay <= 19)) {
            return "winter";
        } else if (inputMonth.equalsIgnoreCase("march")) {
            return "spring";
        } else if ((inputMonth.equalsIgnoreCase("june")) && (inputDay <= 20)) {
            return "spring";
        } else if (inputMonth.equalsIgnoreCase("june")) {
            return "summmer";
        } else if ((inputMonth.equalsIgnoreCase("september")) && (inputDay <= 20)) {
            return "summmer";
        } else if (inputMonth.equalsIgnoreCase("september")) {
            return "fall";
        } else if ((inputMonth.equalsIgnoreCase("december")) && (inputDay <= 20)) {
            return "fall";
        } else if (inputMonth.equalsIgnoreCase("december")) {
            return "winter";
        }
        return "summer";

    }

    public static void displaySeason(String season) {
        System.out.println("This date occurs in the " + season + ".");
    }

}

// if((month==1)||(month==2)){System.out.println("The season is Winter");}else
// if((month==4)||(month==5)){System.out.println("The season is Spring");}else
// if((month==7)||(month==8)){System.out.println("The season is Summer");}else
// if((month==10)||(month==11)){System.out.println("The season is Fall");}else
// if((month==3)&&(day<=19)){System.out.println("The season is Winter");}else
// if(month==3){System.out.println("The season is Spring");}else
// if((month==6)&&(day<=20)){System.out.println("The season is Spring");}else
// if(month==6){System.out.println("The season is Summer");}else
// if((month==9)&&(day<=20)){System.out.println("The season is Summer");}else
// if(month==9){System.out.println("The season is Autumn");}else
// if((month==12)&&(day<=21)){System.out.println("The season is Autumn");}else
// if(month==12){System.out.println("The season is Winter");}