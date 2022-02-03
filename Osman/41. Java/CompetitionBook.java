import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.function.Predicate;
import java.io.*;

public class CompetitionBook {
    List<Competition> competitionBookList = new ArrayList<>();

    String fileLogName;

    CompetitionBook(String fileLogName) {
        this.fileLogName = fileLogName;
        try {
            // the file to be opened for reading
            FileInputStream fis = new FileInputStream(this.fileLogName);
            Scanner sc = new Scanner(fis); // file to be scanned
            // returns true if there is another line to read
            while (sc.hasNextLine()) {
                Competition newCom = new Competition(sc.nextLine(), true);
                // System.out.println(sc.nextLine()); // returns the line that was skipped
                competitionBookList.add(newCom);

            }
            sc.close(); // closes the scanner
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    String getBackingFileName() {
        return this.fileLogName;
    }

    void add(Competition e) {
        competitionBookList.add(e);
    }

    void remove(Competition e) {
        competitionBookList.remove(e);
    }

    int lookupindex(Competition com) {
        for (int i = 0; i < competitionBookList.size(); i++) {
            if (competitionBookList.get(i).equals(com)) {
                return i;
            }
        }
        return -1;
    }

    List<Competition> competitions(Predicate<Competition> p) {
        List<Competition> li = new ArrayList<>();
        for (Competition c : competitionBookList) {
            if (p.test(c)) {
                li.add(c);
            }
        }
        return li;
    }

}
