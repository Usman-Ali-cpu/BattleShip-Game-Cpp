public class Main {

    public static void main(String[] args) {
        int[] arr = new int[5];
        arr[0] = 4;
        arr[1] = 5;
        arr[2] = 6;
        arr[3] = 9;
        arr[4] = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] < arr[j]) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }

        }
        for (int i = 0; i < 5; i++) {
            System.out.println(arr[i]);
        }
    }

}
