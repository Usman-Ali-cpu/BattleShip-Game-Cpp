
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class main
{
    public static void main(String[] args)
    throws FileNotFoundException
    {
            File file = new File("java.txt");
            Scanner sc = new Scanner(file);

            // we just need to use \\Z as delimiter
            sc.useDelimiter("\\Z");
            String s = sc.next();

            System.out.println(s);
    }
}