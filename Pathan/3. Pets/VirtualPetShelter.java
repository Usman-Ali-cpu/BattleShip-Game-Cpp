import java.util.ArrayList;
import java.util.List;

public class VirtualPetShelter {
    List<VirtualPet> listpet; // list of pets of shelter

    public VirtualPetShelter() {
        listpet = new ArrayList<VirtualPet>(); // initializing array of pets in the shelter
    }

    // method takes pet object as an argument and add pet to list of pets
    public void addPet(VirtualPet pet) {
        listpet.add(pet); // add pet to the list
    }

    // method takes pet object as an argument and remove pet to list of pets
    public void removePet(VirtualPet pet) {
        listpet.remove(pet); // remove pet from the list
    }

    // method show all the pets in the list, also print pet's data on the console
    public void showPets() {
        for (VirtualPet value : listpet) { // loop through all the pets in the list
            System.out.println("Name : " + value.getName()); // print name of pet
            System.out.println("Description : " + value.getDescription()); // print description of pet
            System.out.println("Hunger : " + value.getHunger()); // print value of hunger
            System.out.println("Thirst : " + value.getThirst()); // print value of thirst
            System.out.println("Boredom : " + value.getBoredom()); // print value of boredom
            System.out.println();
        }
    }

    // method show all the pets in the list, prints only names
    public void showPetNames() {
        for (VirtualPet value : listpet) { // loop through all the pets in the list
            System.out.println("Name : " + value.getName()); // print name of pet
        }
        System.out.println();
    }

    // this method will feed all the pets in the shelter
    public void feedAllPets() {
        for (VirtualPet value : listpet) // loop through all the pets in the list
            value.updateHunger(-1); // feed the pet will decrease hunger by one
    }

    // this method will watered all the pets in the shelter
    public void wateringAllPets() {
        for (VirtualPet value : listpet) // loop through all the pets in the list
            value.updateThirst(-1); // watering the pet will decrease thirst by one
    }

    // this method will play all the pets in the shelter
    public void playAllPets() {
        for (VirtualPet value : listpet) // loop through all the pets in the list
            value.updateBoredom(-1); // play with the pet will decrease boredom by one
    }

    // this method will feed specific pet in the shelter
    public void feedPet(String name) {
        for (VirtualPet pet : listpet) { // loop through all the pets in the list
            if (pet.getName().equals(name)) { // check if name is equal
                pet.updateHunger(-1); // feed the pet will decrease hunger by one
            }
        }
    }

    // this method will watered specific pet in the shelter
    public void WateringPet(String name) {
        for (VirtualPet pet : listpet) { // loop through all the pets in the list
            if (pet.getName().equals(name)) { // check if name is equal
                pet.updateThirst(-1); // watering the pet will decrease thirst by one

            }
        }
    }

    // this method will play specific pet in the shelter
    public void playPet(String name) {
        for (VirtualPet pet : listpet) { // loop through all the pets in the list
            if (pet.getName().equals(name)) { // check if name is equal
                pet.updateBoredom(-1); // play with the pet will decrease boredom by one

            }
        }
    }

    // this method will tick all pet in the shelter
    public void tick() {
        for (VirtualPet value : listpet) // loop through all the pets in the list
            value.tick(); // tick that pet
    }

    public List<VirtualPet> getAllPetShelter() {
        return listpet; // return list of pets in the shelter
    }

    public VirtualPet getVirtualPet(String name) {
        for (VirtualPet pet : listpet) { // loop through all the pets in the list
            if (pet.getName().equals(name)) { // check if name is equal
                return pet; // return that pet

            }
        }
        return null; // else return null
    }

}
