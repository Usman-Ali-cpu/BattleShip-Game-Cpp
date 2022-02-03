import java.util.Scanner;

public class VirtualPetShelterApp {
    private static VirtualPetShelter shelter = new VirtualPetShelter(); // create static object of VirtualPetShelter
                                                                        // class
    private static Scanner input = new Scanner(System.in); // initialize static object of scanner for input

    public static void main(String[] args) {
        generatePets();
        gameLoop();
    }

    private static void showPets() {
        shelter.showPets(); // it will show all the pets in the shelter list
    }

    private static void generatePets() {
        // declare and initialize new objects of type Virtualpet
        VirtualPet pet1 = new VirtualPet("tommy", "smells like a Stargazer lily fresh with morning dew"); // create
                                                                                                          // first
                                                                                                          // virtual pet
        VirtualPet pet2 = new VirtualPet("skippy", "Skippy is Good to me as Pet"); // create second virtual pet

        // navigate to addPet
        shelter.addPet(pet1); // add pet to list of shelter pet
        shelter.addPet(pet2); // add pet to list of shelter pet
    }

    private static void gameLoop() {
        while (true) {

            whatToDo(); // print menu on the console
            shelter.tick(); // call tick function for whole shelter
        }
    }

    private static void whatToDo() {
        // menu propmpt function
        System.out.println("What would you like to do?");
        System.out.println("\t 1: Feed All Pets");
        System.out.println("\t 2: Watering All Pets");
        System.out.println("\t 3: Play with a Pet");
        System.out.println("\t 4: Display Data of Pet");
        System.out.println("\t 5: Display Pet Names");
        System.out.println("\t 6: Remove a Pet");
        System.out.println("\t 7: Adoption of Pet");
        System.out.println("\t 8: Quit");
        System.out.print("Enter choice : ");

        int response = input.nextInt();
        input.nextLine();
        // takes input from user and navigate to desired function

        switch (response) {
            case 1:
                feedAll();
                break;
            case 2:
                wateringAll();
                break;
            case 3:
                playWithPet();
                break;
            case 4:
                displayPets();
                break;
            case 5:
                displayPetNames();
                break;
            case 6:
                removePet();
                break;
            case 7:
                addPet();
                break;
            case 8:
                System.exit(0);
                break;
            default:
                // input validation
                System.out.println("Invalid Input!");
                break;
        }
    }

    // this function will feed all the pet in the shelter
    private static void feedAll() {
        System.out.print("Confirm by YES or Cancel by NO: ");
        // take reponse from user
        String response = input.nextLine();

        // For typing YES
        if (response.toLowerCase().equals("yes")) {
            shelter.feedAllPets();
            System.out.println("All Pet has been Feeded");
            // return void from inside the block
            return;
        }
        // for typing NO
        System.out.println("No Pet Feeded");

    }

    // this function will watered all the pet in the shelter
    private static void wateringAll() {
        System.out.print("Confirm by YES or Cancel by NO: ");
        String response = input.nextLine();
        // takes response from user

        if (response.toLowerCase().equals("yes")) {
            // for typing YES
            shelter.wateringAllPets(); // water all the pets by using method from virtualpet shelter class
            System.out.println("All Pet has been Watered");
            // return void from inside the function
            return;
        }

        // For typing NO
        System.out.println("No Pet Watered");
    }

    // this function will ask for name of pet then play with that pet
    private static void playWithPet() {
        // this function makes you play with your pet
        System.out.print("Enter name of pet: ");
        String response = input.nextLine();
        String name = response.toLowerCase();
        // navigate to playPet Call
        shelter.playPet(name);
        System.out.println("You have Played with pet " + response);
    }

    // this function will display all the pets in the shelter
    private static void displayPets() {
        // this function takes you to the showPets call
        shelter.showPets();
    }

    // this function will display specific pets in the shelter
    private static void displayPetNames() {
        // this function prompts you names of Pets
        shelter.showPetNames();
    }

    // this function remove specific pet from the shelter
    private static void removePet() {
        // it takes you to
        System.out.print("Enter name of pet: ");
        String response = input.nextLine();
        String name = response.toLowerCase();
        VirtualPet n = shelter.getVirtualPet(name);
        shelter.removePet(n);
        System.out.println("Pet has been Removed");
    }

    // this function add pet to shelter
    private static void addPet() {

        System.out.print("Please Enter your pet: ");
        String name = input.nextLine();
        name = name.toLowerCase();
        System.out.print("Please Enter your pet description: ");
        String description = input.nextLine();
        VirtualPet n = new VirtualPet(name, description);
        shelter.addPet(n);
        System.out.println("Pet has been added");
    }

}