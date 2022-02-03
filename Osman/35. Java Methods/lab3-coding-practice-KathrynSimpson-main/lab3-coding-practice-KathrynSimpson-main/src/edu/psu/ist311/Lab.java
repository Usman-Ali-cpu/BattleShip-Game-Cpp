import java.util.List;
import java.util.function.Function;
import java.util.ArrayList;

// package edu.psu.ist311;

public class Lab {

    public static void main(String[] args) {
        String[] strList = new String[5];
        strList[0] = "I am";
        strList[1] = "GoinG to";
        strList[2] = "Be a";
        strList[3] = "Java";
        strList[4] = "ProGrammer";
        String[] lowerList = lowerAll(strList);
        for (String s : lowerList) {
            System.out.print(s + " ");
        }
        System.out.println();

        int[] intArray = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int[] added5Arr = add5(intArray);
        System.out.print("{");
        for (int element : added5Arr) {
            System.out.print(element + ", ");
        }
        System.out.print("}\n");

        int[] arr = new int[] { 1, -5, 6, 0, -1 };
        Boolean[] boolOFArr = convertToBools(arr);
        System.out.print("{");
        for (Boolean element : boolOFArr) {
            System.out.print(element + ", ");
        }
        System.out.print("}\n");

        List<Integer> newListInteger = app(List.of(2, 5, 2, 5), (Integer e) -> e + 5);
        System.out.print("{");
        for (Integer element : newListInteger) {
            System.out.print(element + ", ");
        }
        System.out.print("}\n");

    }

    public static String[] lowerAll(String[] list) {
        String[] newList = new String[list.length];
        for (int i = 0; i < list.length; i++) {
            String lower = list[i].toLowerCase();
            newList[i] = lower;
        }
        return newList;
    }

    public static int[] add5(int[] list) {
        int[] newIntList = new int[list.length];
        for (int i = 0; i < list.length; i++) {
            int newint = list[i] + 5;
            newIntList[i] = newint;
        }
        return newIntList;
    }

    public static Boolean[] convertToBools(int[] list) {
        Boolean[] newBoolList = new Boolean[list.length];
        for (int i = 0; i < list.length; i++) {
            if (list[i] >= 0) {
                newBoolList[i] = true;
            } else {
                newBoolList[i] = false;
            }
        }
        return newBoolList;
    }

    public static List<Integer> app(List<Integer> listT, Function<Integer, Integer> f) {
        List<Integer> newList = new ArrayList<Integer>();
        for (Integer item : listT) {
            newList.add(f.apply(item));
        }
        return newList;
    }

}
