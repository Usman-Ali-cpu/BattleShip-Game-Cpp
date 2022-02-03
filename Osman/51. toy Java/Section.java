package IC10;

import java.io.IOException;
import java.util.ArrayList;

public class Section {
    private int secNum;
    private String title;
    private String inst;
    private String room;
    private ArrayList<Student> students;

    public Section() {
        secNum = 0;
        title = "Not set";
        inst = "TBD";
        room = "TBD";
        students = new ArrayList<>();
    }

    public Section(int secNum, String title, String inst, String room) throws IOException {
        this();
        boolean valid = setSecNum(secNum);
        if (!valid) {
            System.out.println("There was an error in section number");
        }
        this.title = title;
        setInst(inst);
        this.room = room;
    }

    public Section(int secNum, String title, String inst, String room, ArrayList<Student> students) throws IOException {
        this(secNum, title, inst, room);
        this.students = students;
    }

    public int getSecNum() {
        return secNum;
    }

    public boolean setSecNum(int SecNum) {
        boolean valid = secNum >= 1 && secNum <= 15;
        if (valid) {
            this.secNum = secNum;
        }
        return valid;
    }

    public boolean setTitle(String title) {
        boolean valid = !title.isBlank();
        if (valid) {
            this.title = title;
        }
        return valid;
    }

    public String getInst() {
        return inst;

    }

    public void setInst(String inst) throws IOException {
        boolean valid = !inst.isBlank();
        if (!valid) {
            throw new IOException("The instruction cannot be blank");
        }
        this.inst = inst;
    }

    public String getRoom() {
        return room;
    }

    public boolean setRoom(String room) {
        boolean valid = !room.isBlank();
        if (valid) {
            this.room = room;
        }
        return valid;
    }

    public ArrayList<Student> getStudents() {
        return students;
    }

    public void setStudents(ArrayList<Student> students) {
        this.students = students;
    }

    public void addStudent(Student stu) {
        students.add(stu);
    }

    public String toString() {
        String retStr = "";
        retStr += "Section No. \tTitle   \t   Inst   \tRoom\n";
        retStr += secNum + "\t\t" + title + "\t  " + inst + "\t  " + room + "\n  ";
        retStr += "Name \t\tMajor\t\tGPA\t\tHours\n";
        for (Student stu : students) {
            retStr += stu.toString() + "\n";
        }

        return retStr;

    }
}
