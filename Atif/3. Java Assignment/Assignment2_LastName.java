import java.util.Scanner;

public class Assignment2_LastName {

    static Scanner input = new Scanner(System.in);
    static Member me = new Member();

    public static void main(String[] args){

        while(true)
        {
            printMenu();
            System.out.print("Enter your choice : ");
            int key = input.nextInt();
            input.nextLine();

            switch (key) {
                case 0:
                    input.close();
                    System.exit(0);
                break;
                case 1:
                    printMember();
                break;
                case 2:
                    listMissions();
                break;
                case 3:
                    addMission();
                break;
                case 4:
                    completeMission();
                break;
                case 5:
                    deleteMission();
                break;
                default:
                    System.out.println("Invalid input !");
                    break;
            }
        }
       
    }




    public static void readMember(){
        System.out.print("Enter Member Name : ");
        String memberName = input.nextLine();
        // me.setMemName(memberName);

        System.out.print("Enter Maximum number of Missions : ");
        int numMission = input.nextInt();
        input.nextLine();
        // me.setNumberOfMission(numMission);
        me.setMemName(memberName);
        me.setNumberOfMission(numMission);
    }

    public static void printMember(){
        String str = "Member { name = " + me.getMemName() + ", number of Missions = " + me.getCurrent() + " } ";
        System.out.println(str);
    }
    public static void printMenu(){
        System.out.println(" =====================");
        System.out.println(" 0 - Exit");
        System.out.println(" 1 - Print Member");
        System.out.println(" 2 - List Missions");
        System.out.println(" 3 - Add A New Mission");
        System.out.println(" 4 - Complete A Mission");
        System.out.println(" 5 - Delete A Mission");
        System.out.println(" =====================");
    }
    public static void listMissions(){
        if(me.getCurrent() > 0){
            Mission [] missionArr = me.getMissionArr();
            for(int i =0; i< me.getCurrent(); i++){
                System.out.println(i + " : " + missionArr[i].toString());
            }
        }
        else {
            System.out.println("No Mission Assigned");
        }
    }
    public static void addMission(){
        String mis;
        System.out.print("Enter name of mission : ");
        mis = input.nextLine();
        Mission m = new Mission();
        m.setName(mis);
        me.addMission(m);  
    }
    public static void completeMission(){
        System.out.print("Enter index of mission : ");
        int index = input.nextInt();
        input.nextLine();
        if(index > me.getCurrent()){
            System.out.println("Mission does not exits");
            return;
        }
        Mission temp = me.getMission(index);
        if(temp.isCompleted()){
            System.out.println("Mission is Already completed");
            return;
        }
        else {
            me.completeMission(index);
            System.out.println("Mission Completed");
        }
    }
    public static void deleteMission(){
        System.out.print("Enter index of mission : ");
        int index = input.nextInt();
        input.nextLine();
        if(index > me.getCurrent()){
            System.out.println("Mission does not exits");
            return;
        }
        me.deleteMission(index);
    }

}
