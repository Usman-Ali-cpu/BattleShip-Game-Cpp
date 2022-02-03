import java.io.PrintStream;
import java.util.List;
import java.util.Scanner;
import java.time.Year;
import java.io.*;

public class RacetrackCli {

    public Scanner input = new Scanner(System.in);
    public PrintStream out;
    CompetitionBook book;

    public void doShowCommandLine() {
        out.println("Welcome to the running competition record system");
        out.println("------------------------------------------------");
        while (true) {
            System.out.println("Enter A)dd, R)emove, LY) List by Year, S)ave, L)ist all, or Q)uit");
            try {
                String cmd = input.nextLine().trim().toUpperCase();
                if (cmd.equals("A")) {
                    doAdd();
                } else if (cmd.equals("L")) {
                    doListAll();
                } else if (cmd.equals("LY")) {
                    doListByYear();
                } else if (cmd.equals("R")) {
                    doRemove();
                } else if (cmd.equals("S")) {
                    doSave();
                } else if (cmd.equals("Q")) {
                    System.exit(0);
                }
                /* additional actions here */
                else {
                    out.println("Invalid command");
                }
            } catch (Exception e) {
                out.println("An error occurred .. " + e.getMessage() + " .. try again");
            }
        }
    }

    public RacetrackCli(Scanner in, PrintStream out, CompetitionBook book) {
        this.out = out;
        this.input = in;
        this.book = book;
    }

    public void doAdd() {
        System.out.print("Enter: ");
        String strCom = input.nextLine();
        Competition c = new Competition(strCom, true);

        System.out.println("Added : " + c.toString());
        book.add(c);
    }

    public void doRemove() {
        System.out.print("Enter Competition Name: ");
        String comName = input.nextLine();
        for (Competition c : book.competitionBookList) {
            if (c.competitionName.equals(comName)) {
                book.competitionBookList.remove(c);
            }
        }
    }

    public void doListAll() {

        for (Competition c : book.competitionBookList) {
            System.out.println(c.toString());

        }
    }

    public void doListByYear() {
        List<Competition> li = book.competitionBookList;
        System.out.println("Enter year : ");
        String y = input.nextLine();

        // Year year = Year.parse(y);
        // System.out.println(year);
        for (Competition c : book.competitionBookList) {
            if (c.year.toString().equals(y)) {
                System.out.println(c.toString());
            }
        }
    }

    public void doSave() {
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter(new File(book.fileLogName), true));
            for (Competition c : book.competitionBookList) {
                bw.write(c.renderInLogFileFormat());
                bw.newLine();
            }
            bw.close();
        } catch (Exception e) {

        }
    }

}
