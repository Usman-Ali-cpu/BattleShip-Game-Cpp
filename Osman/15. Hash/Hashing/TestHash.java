import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class TestHash {

   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);

      System.out.println("Enter 1 Veriticle Hashing");
      System.out.println("Enter 2 Horizontal Hashing");
      System.out.print("Enter choice: ");
      int num = input.nextInt();
      while (num != 1 && num != 2) {
         System.out.print("Invalid choice! Enter choice");
         num = input.nextInt();
      }

      switch (num) {
         case 1: {
            System.out.println("Verticle Hashing");
            VerticleHashSet vert = new VerticleHashSet(10);
            vert.add(1);
            vert.add(45);
            vert.add(67);
            vert.add(40);
            vert.add(10);
            vert.add(3);
            vert.add(34);
            vert.add(9);
            vert.add(14);
            vert.add(16);
            vert.add(28);
            vert.add(12);
            vert.add(32);
            vert.add(24);
            vert.add(90);
            vert.add(15);
            vert.add(101);
            vert.add(25);
            vert.add(23);
            vert.remove(101);
            vert.remove(39);

            Iterator iter = vert.iterator();
            while (iter.hasNext()) {
               ArrayList<Object> li = new ArrayList<Object>();
               li = (ArrayList<Object>) iter.next();
               if (li.size() > 0) {
                  System.out.print("{");
                  for (Object i : li) {
                     System.out.print(i + ", ");

                  }
                  System.out.println("}");
               }
            }

            if (vert.contains(101)) {
               System.out.println("Yes Contain");
            } else {
               System.out.println("Not Contain");
            }

            if (vert.contains(3)) {
               System.out.println("Yes Contain");
            } else {
               System.out.println("Not Contain");
            }

         }

            break;
         case 2: {
            System.out.println("Horizontal Hashing");
            HorizontalHashSet names = new HorizontalHashSet(101);
            names.add("Harry");
            names.add("Sue");
            names.add("Nina");
            names.add("Susannah");
            names.add("Larry");
            names.add("Eve");
            names.add("Sarah");
            names.add("Adam");
            names.add("Tony");
            names.add("Katherine");
            names.add("Juliet");
            names.add("Romeo");
            names.remove("Romeo");
            names.remove("George");

            Iterator iter = names.iterator();
            System.out.print("{ ");
            while (iter.hasNext()) {
               System.out.print(iter.next() + ", ");
            }
            System.out.print("}\n");
            if (names.contains("Harry")) {
               System.out.println("\nYes Contain");
            } else {
               System.out.println("Not Contain");
            }
         }

            break;

         default:
            System.out.println("inValid Choice ");
            break;
      }

   }
}