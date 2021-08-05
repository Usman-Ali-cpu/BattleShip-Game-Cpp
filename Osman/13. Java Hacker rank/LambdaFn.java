import java.util.*;
import java.util.stream.Collectors;
import static java.lang.Math.*;

public class LambdaFn {

    public static void main(String[] args) {
        List<String> listOfIntergers = new ArrayList<String>();
        listOfIntergers.add("301");
        listOfIntergers.add("371");
        listOfIntergers.add("312");
        listOfIntergers.add("370");
        listOfIntergers.add("350");
        listOfIntergers.add("400");
        List<Long> out = functionalProgramming(listOfIntergers);
        for (Long l : out) {
            System.out.println(l);
        }
    }

    public static int countDigit(Long n) {
        if (n == 0)
            return 0;

        return 1 + countDigit(n / 10);
    }

    // Returns true if n is Narcissistic number
    public static boolean check(Long n) {
        // count the number of digits
        int l = countDigit(n);
        Long dup = n;
        int sum = 0;

        // calculates the sum of
        // digits raised to power
        while (dup > 0) {
            sum += pow(dup % 10, l);
            dup /= 10;
        }

        return (n == sum);
    }

    public static List<Long> functionalProgramming(List<String> listOfIntergers) {

        List<Long> outputList = listOfIntergers.stream().map(s -> Long.parseLong(s)).filter(number -> check(number))
                .collect(Collectors.toList());
        return outputList;
    }

}