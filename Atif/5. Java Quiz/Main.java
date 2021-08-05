
import java.util.*;

public class Main {

public static int x = 0;

public static void main(String[] args) {

        new Test(1).run();
        System.out.println(" ");

        new Test(-1).run();
    }
}

class Test extends Thread {
    private int inc;

    public Test(int inc) {
    this.inc = inc;
    }

    public void run() {

        for (int i = 0; i < 3; i++) {

            Main.x += inc;

            System.out.print(Main.x);
        }
    }

}