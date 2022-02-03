import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // args[0] = "runlog.txt";
        // if (args.length < 1) {
        // System.out.println("Error no file specified, usage: [filename.txt]");
        // return; // no sense in continuing (missing race data)..
        // }

        // uncomment these when ready:
        Scanner in = new Scanner(System.in);
        CompetitionBook book = new CompetitionBook("Demo.txt");
        RacetrackCli u = new RacetrackCli(in, System.out, book);
        u.doShowCommandLine();
    }

}
