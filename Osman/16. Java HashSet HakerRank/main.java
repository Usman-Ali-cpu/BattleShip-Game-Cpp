import java.io.FileNotFoundException;
import java.io.IOException;

public class main {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        if (HSPresent.isHSPresent()) {
            System.out.println("ok");
        }
        else {
            System.out.println("not");
        }

    }

}
