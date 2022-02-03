import java.util.Scanner;

public class Question1B {
    public static void main(String[] args) {
        int a = 4;
        int b = 6;
        double c = 4.0;

        // (i)
        System.out.println(a++); // value will be increment after printing, so a will be 4
        System.out.println(a); // value will be 5 because it has incremented
        System.out.println(++a);// value will be 6, it is incremented first then prints
        System.out.println(a); // value will be 6

        // (ii)
        a = 4;
        b = 6;
        c = 4.0;
        System.out.println(((++a) + (b++) >= ((a++) + (++b)))); // (5)+ (6) >= (6)+ (6) => 11 >= 12
        // sp answer will be false

        // (iii)
        a = 4;
        b = 6;
        c = 4.0;
        System.out.println((a % b == c)); // reminder of a to b
        // 4 % 6 == 4, it is true

        // (iv)
        a = 4;
        b = 6;
        c = 4.0;
        boolean result = (a > 4) || (b < a) && (a != b);
        // (4> 4) || (6< 4) && (4 != 6)
        // false || false && true
        // flase
        System.out.println(result);

    }

}
