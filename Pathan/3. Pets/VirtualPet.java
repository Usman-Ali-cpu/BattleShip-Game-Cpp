public class VirtualPet {

    private String name; // private String type variable to store name of pet
    private String description; // private String type variable to store description of pet
    private int hunger; // private int type variable to store hungerness
    private int boredom; // private int type variable to store boreness
    private int thirsty; // private int type variable to store thirstness

    // constructor
    public VirtualPet(String n, String des) {
        name = n; // setting name
        this.description = des; // setting description
        hunger = 1; // initialize hunger
        boredom = 1; // initialize boredom
        thirsty = 1; // initialize thirsty
    }

    // default constructor
    public VirtualPet() {
        name = "Unknown"; // default value
        this.description = "None"; // default description
        hunger = 1; // initialize hunger
        boredom = 1; // initialize boredom
        thirsty = 1; // initialize thirsty

    }
    // create getter methods

    public String getName() {
        return name; // getter of name
    }

    public String getDescription() {
        return description; // getter of description
    }

    public void setDescription(String description) {
        this.description = description; // setter of description
    }

    public int getHunger() {
        return hunger; // getter of hunger
    }

    public int getBoredom() {
        return boredom; // getter of boredom
    }

    public int getThirst() {
        return thirsty; // getter of thirst
    }
    // create setter methods

    public void setHunger(int hgr) {
        hunger = hgr; // setter of hunger
    }

    public void setBoredom(int b) {
        boredom = b; // setter of boredom
    }

    public void setThirst(int t) {
        thirsty = t; // setter of thirst
    }

    public void updateHunger(int hung) {
        hunger += hung; // to modify the value of hunger
    }

    public void updateBoredom(int bore) {
        boredom += bore; // to modify the value of boredom
    }

    public void updateThirst(int thirst) {
        thirsty += thirst; // to modify the value of thirst
    }

    // tick method to randomize game loop
    public void tick() {
        hunger += 2; // tick method add 2 to hunger
        boredom += 2; // tick method add 2 to boredom
        thirsty += 1; // tick method add 2 to thirst
    }

}