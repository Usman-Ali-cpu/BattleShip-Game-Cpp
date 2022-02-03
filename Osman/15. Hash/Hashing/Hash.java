import java.lang.Math;

public class Hash {

    public static int folding(int key) {
        int arraySize = 1021;
        int keyDigitCount = getDigitCount(key);
        int groupSize = getDigitCount(arraySize);
        int groupSum = 0;
        String keyString = Integer.toString(key);
        int i;
        for (i = 0; i < keyString.length(); i += groupSize) {
            if (i + groupSize <= keyString.length()) {
                String group = keyString.substring(i, i + groupSize);
                groupSum += Integer.parseInt(group);
            }
        }
        // There is no remaining part if count is divisible by groupsize.
        if (keyDigitCount % groupSize != 0) {
            String remainingPart = keyString.substring(i - groupSize, keyString.length());
            groupSum += Integer.parseInt(remainingPart);
        }
        return groupSum % arraySize;
    }

    public static int division(int key, int size) {
        int hashed = 0;
        hashed = key % size;
        return hashed;
    }

    public static int MAD(int key, int N) {
        int a = getRandom(N);
        int b = getRandom(N);
        int p = getPrime(N);
        int num = Math.abs((a * key + b) % p) % N;
        return num;
    }

    public static int CyclicShift(String str) {
        int h = 0;
        for (int i = 0; i < str.length(); i++) {
            h = (h << 5) | (h >>> 27); // 5-bit cyclic shift of the running sum
            h += (int) str.charAt(i); // add in next character
        }
        if (h < 0) {
            h = -h;
        }
        return h;
    }

    private static int getRandom(int N) {
        return (int) ((Math.random() * (N - 1 - 0)) + 0);
    }

    private static int getPrime(int p) {
        for (int i = p - 1; i >= 1; i--) {
            if (isPrime(i)) {
                return i;
            }
        }
        return 1;
    }

    private static boolean isPrime(int number) {
        int i = 1;
        int count = 0;
        while (i < number) {
            if (number % i == 0) {
                count++;
            }
            i++;
        }
        if (count > 1) {
            return false;
        }
        return true;

    }

    private static int getDigitCount(int n) {
        int numDigits = 1;
        while (n > 9) {
            n /= 10;
            numDigits++;
        }
        return numDigits;
    }

}
