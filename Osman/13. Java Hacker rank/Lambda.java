import java.util.*;
import java.util.stream.Collectors;
import static java.lang.Math.*;

public class Lambda {
    public int countDigit(Long n) {
        if (n == 0)
            return 0;

        return 1 + countDigit(n / 10);
    }

    // Returns true if n is Narcissistic number
    public boolean check(Long n) {
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

    public List<Long> functionalProgramming(List<String> listOfIntegers) {

        List<Long> outputList = listOfIntegers.stream().map(s -> Long.parseLong(s)).filter(number -> check(number))
                .collect(Collectors.toList());
        return outputList;
    }

}
