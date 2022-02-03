import java.util.Random;

public class Lottery {
    private String ticket;

    public Lottery() {
        ticket = "";
    }

    public Lottery(Random r) {
        ticket = GenerateRandomWinner(r);
    }

    public String GetTicket() {
        return ticket;
    }

    public void setTicket(String tick) {
        ticket = tick;
    }

    public static String GenerateRandomWinner(Random r) {
        r = new Random();
        String tick = "";
        for (int i = 0; i < 6; i++) {
            int rand = r.nextInt(9);
            tick += rand;
        }
        return tick;
    }

    public static int GenerateSelectWinner(int n, Random rn) {
        return rn.nextInt(n);
    }

    public static void Sort(Lottery[] array) {
        // System.out.println("Please wait! Sorting... ");
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = i + 1; j < array.length - 1; j++) {
                // compares each elements of the array to all the remaining elements
                if (array[i].GetTicket().compareTo(array[j].GetTicket()) > 0) {
                    // System.out.println("Please wait! Sorting... ");
                    // swapping array elements
                    String temp = array[i].GetTicket();
                    array[i].setTicket(array[j].GetTicket());
                    array[j].setTicket(temp);
                }
            }
        }
    }

    public static boolean Solution1(Lottery[] array, String test, int num) {
        for (int i = 0; i < num; i++) {
            if (array[i].GetTicket().equals(test)) {
                return true;
            }
        }
        return false;
    }

    public static boolean Solution2(Lottery[] array, int n1, int n2, String test) {
        int low = n1;
        int high = n2 - 1;

        while (high >= low) {
            int mid = (low + high) / 2;
            if (test.compareTo(array[mid].GetTicket()) < 0)
                high = mid - 1;
            else if (test.equals(array[mid].GetTicket()))
                return true;
            else
                low = mid + 1;
        }

        return false;
    }

}