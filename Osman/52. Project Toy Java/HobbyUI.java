import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class HobbyUI {

    public static void main(String[] args) {
        List<Hobby> li = new ArrayList<Hobby>();
        Hobby hobby = new Hobby();
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < 1; i++) {
            System.out.println("Enter the hobby name");
            String hobbyName = in.nextLine();
            while (!hobby.setName(hobbyName)) {
                System.out.println("Enter the hobby name");
                hobbyName = in.nextLine();
            }
            System.out.println("Please enter the category for Wood working. Gaming, Fishing, Sewing, Crafting");
            String hobbyCata = in.nextLine();
            while (!hobby.setCatagory(hobbyCata)) {
                System.out.println("Please enter the category for Wood working. Gaming, Fishing, Sewing, Crafting");
                hobbyCata = in.nextLine();
            }
            while (true) {
                Reference ref = new Reference();
                System.out.println("Please enter the refernces for " + hobbyName);
                System.out.println("Please enter the title for this reference (blank to exit)");
                String title = in.nextLine();
                while (!ref.setTitle(title)) {
                    System.out.println("Please enter the title for this reference (blank to exit)");
                    title = in.nextLine();
                }

                System.out.println("Please enter the type for " + title);
                String type = in.nextLine();
                while (!ref.setType(type)) {
                    System.out.println("Please enter the type for " + title);
                    type = in.nextLine();
                }

                System.out.println("Please enter the location for " + title);
                String location = in.nextLine();
                while (!ref.setLocation(location)) {
                    System.out.println("Please enter the location for " + title);
                    location = in.nextLine();
                }
                System.out.println("Do you have another reference? (Y/N)");
                String check = in.nextLine();
                if (check.equalsIgnoreCase("y")) {
                    hobby.list.add(ref);
                    continue;
                } else {
                    hobby.list.add(ref);
                    break;
                }
            }
            li.add(hobby);
        }
        for (int j = 0; j < 3; j++) {
            System.out.println(li.get(j).toString() + "\n");
        }

        in.close();
        System.out.println("\n\nThank you for entering hobbies.");

    }

}
