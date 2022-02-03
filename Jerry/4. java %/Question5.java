
// a) 
/* 
Arrays are used when there is a need to use many variables of the same type. 
It can be defined as a sequence of objects which are of the same data type. 
It is used to store a collection of data, 
and it is more useful to think of an array as a collection of variables of the same type. 
Arrays can be declared and used.
Array Saves memory.
Array has Easier debugging.
Array helps in reusability of code.


*/

public class Question5 {
    public static void main(String[] args) {

        // b)
        String[] BANANAREPUBLIC = new String[4];
        BANANAREPUBLIC[0] = "First Element";
        BANANAREPUBLIC[1] = "Second Element";
        BANANAREPUBLIC[2] = Integer.toString(3);
        BANANAREPUBLIC[3] = Double.toString(4.0);

        // c)
        for (int i = 0; i < 4; i++) {
            System.out.println(BANANAREPUBLIC[i]);
        }

        // d)
        /*
         * If amateur programmer try to call BongoBar[5], it would give a index access
         * error. As the size of array is 4, while the indexes of array where the data
         * is actually present are 0, 1, 2, 3. You can asscess only these index other it
         * will throw a Exception.
         * 
         */

    }

}
