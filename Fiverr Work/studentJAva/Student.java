public class Student {
    int studentID;
        String firstName;
        String lastName;
        String emailAddress;

        public Student() {
            this.firstName = "Unknown";
            this.lastName = "Unknown";
            this.emailAddress = "Unkown@unkown.com";
            this.studentID = 0;
        }

        public Student(int id, String first, String last, String email) {
            this.firstName = first;
            this.lastName = last;
            this.emailAddress = email;
            this.studentID = id;
        }

        public void printStudent() {
            System.out.println("First name :" + this.firstName);
            System.out.println("Last name :" + this.lastName);
            System.out.println("Email Address :" + this.emailAddress);
            System.out.println("Student ID :" + this.studentID + "\n"); 
        }
    
}
