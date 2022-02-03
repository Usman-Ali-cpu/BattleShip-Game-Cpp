
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Lottery[] ticketscollection = new Lottery[1000];

        Random rn = new Random();
        rn.setSeed(0); // set the pseudorandom number generator

        for (int x = 0; x < ticketscollection.length; ++x) {
            rn = new Random();
            ticketscollection[x] = new Lottery(rn);
        }

        Lottery.Sort(ticketscollection);

        System.out.println("Beginning Test Cases");

        System.out.println("*********************************");

        String test = Lottery.GenerateRandomWinner(rn); // random ticket
        int index = Lottery.GenerateSelectWinner(999, rn); // index of a winning ticket

        System.out.println("TEST 1");
        System.out.println("TESTING When Array holds 1000 Tickets");

        System.out.println("Testing Solution 1");

        if (Lottery.Solution1(ticketscollection, test, 99) == false
                && Lottery.Solution1(ticketscollection, ticketscollection[index].GetTicket(), 999) == true)
            System.out.println("Solution 1 Test 1 Passed!");
        else
            System.out.println("Solution 1 Test 1 Failed!");

        System.out.println("Testing Solution 2");

        if (Lottery.Solution2(ticketscollection, 0, 999, test) == false
                && Lottery.Solution2(ticketscollection, 0, 999, ticketscollection[index].GetTicket()) == true)
            System.out.println("Solution 2 Test 1 Passed!");
        else
            System.out.println("Solution 2 Test 1 Failed!");

        System.out.println("*********************************");

    }

}
