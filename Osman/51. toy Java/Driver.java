package IC10;

import java.io.IOException;
import java.nio.file.FileSystemNotFoundException;
import java.rmi.ConnectIOException;
import java.util.Scanner;

public class Driver {
    private Scanner input;

    public static void main(String[] args) {

        Driver drv = new Driver();
        Section sec = new Section();
        try {
            System.out.println("Please enter section number(1 - 15)");
            drv.input = new Scanner(System.in);
            int secNum = drv.input.nextInt();
            drv.input.nextLine();

            while (secNum < 1 || secNum > 15) {
                System.out.println("Invalid section. Please enter the section number (1 to 15) ");
                secNum = drv.input.nextInt();
                drv.input.nextLine();
            }
            System.out.println("Please enter the course name");
            String courceName = drv.input.nextLine();

            if (!courceName.equalsIgnoreCase("Programming Fundamentals")) {
                while (!courceName.equalsIgnoreCase("Programming Fundamentals")
                        || !courceName.equalsIgnoreCase("Intermediate Programming")) {
                    System.out.println("Course must be either Programming Fundamentals or Intermediate Programming");
                    courceName = drv.input.nextLine();
                    if (courceName.equalsIgnoreCase("Programming Fundamentals")) {
                        break;
                    } else if (courceName.equalsIgnoreCase("Intermediate Programming")) {
                        break;
                    }
                }
            } else if (courceName.equalsIgnoreCase("Intermediate Programming")) {
                while (!courceName.equalsIgnoreCase("Programming Fundamentals")
                        || !courceName.equalsIgnoreCase("Intermediate Programming")) {
                    System.out.println("Course must be either Programming Fundamentals or Intermediate Programming");
                    courceName = drv.input.nextLine();
                    if (courceName.equalsIgnoreCase("Programming Fundamentals")) {
                        break;
                    } else if (courceName.equalsIgnoreCase("Intermediate Programming")) {
                        break;
                    }
                }
            }

            System.out.println("Please enter the instructor’s name : ");
            String instructor = drv.input.nextLine();
            while (instructor.isBlank()) {
                System.out.println("Invalid instructor name. This cannot be blank");
                instructor = drv.input.nextLine();
            }
            System.out.println("Please enter the room for " + courceName);
            String room = drv.input.nextLine();
            while (room.isBlank()) {
                System.out.println("Invalid room. This cannot be blank \nPlease enter the room for " + courceName);
                room = drv.input.nextLine();
            }
            sec.setSecNum(secNum);
            sec.setInst(instructor);
            sec.setRoom(room);
            sec.setTitle(courceName);

            // Student
            for (int i = 0; i < 2; i++) {
                System.out.println("Please enter the student's name");
                String stname = drv.input.nextLine();
                System.out.println("Please enter the major for " + stname);
                String major = drv.input.nextLine();
                while (major.isBlank()) {
                    System.out.println("Major cannot be blank");
                    System.out.println("Please enter the major for " + stname);
                    major = drv.input.nextLine();
                }
                System.out.println("Please enter the GPA for " + stname);
                double stgpa = drv.input.nextDouble();
                drv.input.nextLine();
                while (stgpa > 4 || stgpa < 0) {
                    System.out.println("GPA must be between 0 and 4, inclusive\nPlease enter the GPA for " + stname);
                    stgpa = drv.input.nextDouble();
                    drv.input.nextLine();
                }
                System.out.println("Please enter the hours for " + stname);
                int sthour = drv.input.nextInt();
                drv.input.nextLine();
                while (sthour < 1 || sthour > 17) {
                    System.out
                            .println("Hours must be between 1 and 17, inclusive\nPlease enter the hours for " + stname);
                    sthour = drv.input.nextInt();
                    drv.input.nextLine();
                }
                Student newSt = new Student(stname, major, stgpa, sthour);
                sec.addStudent(newSt);
            }

            // end student

        } catch (IOException ioe) {
            System.out.println(ioe.getMessage());
        }

        System.out.println(sec.toString());

        drv.input.close();
    }

    public Student getStudent() {
        Student stu = new Student();
        boolean valid;
        do {
            System.out.println("Please enter a name");
            String name = input.nextLine();
            valid = stu.setName(name);

        } while (!valid);
        do {
            System.out.println("Please enter a major");
            String major = input.nextLine();
            valid = stu.setMajor(major);

        } while (!valid);
        do {
            System.out.println("Please enter gpa");
            double gpa = input.nextDouble();
            valid = stu.setGpa(gpa);

        } while (!valid);
        do {
            System.out.println("Please enter hours");
            int hours = input.nextInt();
            valid = stu.setHours(hours);
        } while (!valid);
        return stu;
    }
}
