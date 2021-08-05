import java.util.Scanner;


public class Midterm_MyCars_Alhindi{

    static class Car{
        private String owner;
        private String color;
        private int year;

        public Car(){
            this.color = " ";
            this.owner = " ";
            this.year = 0;
        }
        public Car(String name, String col, int i) {
            this.color = col;
            this.owner = name;
            this.year = i;
        }
        public String getColor() {
            return color;
        }
        public String getOwner() {
            return owner;
        }
        public int getYear() {
            return year;
        }
        public void setColor(String color) {
            this.color = color;
        }
        public void setOwner(String owner) {
            this.owner = owner;
        }
        public void setYear(int year) {
            this.year = year;
        }
        @Override
        public String toString() {
            return "Car {owner: " +getOwner() + ", color: "+ this.getColor() + ", year: " + getYear()+ "}";
        }
    }

    public static void main(String [] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter owner's name : ");
        String name = input.nextLine();
        while(name.length() <= 2){
            System.out.println("Name must be 3 letters or longer!");
            System.out.print("Enter owner's name : ");
            name = input.nextLine();
        }
        Car [] carArr = new Car[5];
        carArr[0] = new Car(name, "Black", 1965);
        carArr[1] = new Car(name, "Grey", 1975);
        carArr[2] = new Car(name, "White", 1985);
        carArr[3] = new Car(name, "Red", 1995);
        carArr[4] = new Car(name, "Black", 2005);

        Car old = getOldestCar(carArr);
        System.out.println("Oldest Car : "+ old.toString());
        System.out.println(getNumberOfCars(carArr, "Black"));
    }

    public static Car getOldestCar(Car [] arr){
        Car old = arr[0];
        int y = 3000;

        for(int i=0; i<arr.length; i++){
            if(arr[i].getYear() < y){
                y = arr[i].getYear();
                old = arr[i];
            }
        }
        return old;
    }
    public static int getNumberOfCars(Car []arr, String col){
        int count =0;
        for(int i=0; i< arr.length; i++){
            if(col == arr[i].getColor()){
                count++;
            }
        }
        return count;
    }







}