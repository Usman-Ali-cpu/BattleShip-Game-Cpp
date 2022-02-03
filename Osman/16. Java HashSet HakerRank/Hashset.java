package com.fresco;

import java.util.*;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Hashset {

    public static String getOut(int numberOfMatches, String squads, int squad1, int squad2) {
        String[] spliting = squads.split("#");
        for (String s : spliting) {
            System.out.println(s);
        }
        String[] match1 = spliting[squad1 - 1].split(" ");
        String[] match2 = spliting[squad2 - 1].split(" ");

        HashSet<String> set2 = new HashSet();
        for (String s : match2) {
            set2.add(s);
        }
        HashSet<String> out = new HashSet();

        for (String mat : match1) {
            try {
                if (!set2.contains(mat)) {
                    System.out.println("First : " + mat);
                    out.add(mat);
                }
            } catch (NoSuchElementException e) {

            }
        }
        Iterator<String> j = out.iterator();
        while (j.hasNext()) {
            System.out.print(j.next() + " ");
        }
        System.out.print(", ");
        HashSet<String> output = new HashSet();

        String[] first = spliting[0].split(" ");

        for (String f : first) {
            boolean flag = true;

            HashSet<String> teams = new HashSet();
            for (String s : spliting) {
                String[] player = s.split(" ");
                HashSet<String> output3 = new HashSet();
                for (String p : player) {
                    output3.add(p);
                }
                if (!output3.contains(f)) {
                    flag = false;
                    break;
                }

            }
            if (flag) {
                output.add(f);
            }
        }
        String stringre = "";
        Iterator<String> k = output.iterator();
        while (k.hasNext()) {
            System.out.print(k.next() + " ");
            stringre += k.next() + " ";
        }

        return stringre;
    }

}