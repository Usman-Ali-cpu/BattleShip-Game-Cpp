import java.util.Random;
import java.util.Scanner;

public class VirtualPetApp {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in); // initialze scannner for the input
        Random rand = new Random(); // calling random function

        System.out.print("Please Enter your pet: ");
        String name = input.nextLine(); // input the name of pet
        name = name.toLowerCase();
        System.out.print("Please Enter your description: ");
        String description = input.nextLine(); // input the description of pet
        VirtualPet pet = new VirtualPet(name, description); // calling virtual pet constructor to make object
        System.out.println("Hi " + pet.getName() + "! Let's have some fun"); // print a message

        int select;

        do {
            // menu prompt
            System.out.println("\nPick a number.");
            System.out.println("Enter 0. To Quit ");
            System.out.println("Enter 1. Play with Pet");
            System.out.println("Enter 2. Feed the Pet");
            System.out.println("Enter 3. Drink water ");

            select = input.nextInt();
            switch (select) {
                case 1: { // if user enter 1
                    if (pet.getHunger() + 1 > 6) {// if hunger reaches max
                        System.out.println("Alright... But Please give me feed to play");
                        continue;
                    }
                    System.out.println("Let's go out and play!");
                    pet.updateHunger(1); // if pet play, increase hunger
                    pet.updateBoredom(-1); // decrease bore
                }
                    break;
                case 2: {
                    if (pet.getHunger() - 1 < 0) {
                        System.out.println("ugggg....no more. I'm already full.");
                        continue;
                    }
                    pet.updateHunger(-1); // by taking feed decrease hunger
                    System.out.println("mmmhh mmhh delicious...this feed is my favorite.");

                }

                    break;
                case 3: {
                    // If Boredom is at max.

                    System.out.println("Let's Drink Water!");
                    pet.updateThirst(-1);

                    // randomize the movie it picks when selected

                }

                    break;
                case 0: {

                    // if Boredom is 0.
                    // exit the switch
                    System.exit(0);

                    // and move to next iteration
                    continue;
                }

                default:
                    // for default values prompt statement and break switch
                    System.out.println("Invalid selection. Please select one of the numbers listed");
                    break;
            }
            // tick method
            pet.tick();

        } while (select != 0);

        input.close();

    }

}