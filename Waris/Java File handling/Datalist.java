import java.util.ArrayList;
import java.util.List;
import java.io.*;

public class Datalist {
    public List<Data> listData; // make a list of Data to store data objects

    public Datalist() { // default constructor
        listData = new ArrayList<>(); // initialize list
        readFile(); // read data from file
    }

    public void insert(Data data) {
        listData.add(data); // append data to list
        try {
            // create Bufferedwriter instance with a FileWriter
            // the flag set to 'true' tells it to append a file if file exists
            BufferedWriter out = new BufferedWriter(new FileWriter("Data.txt", true));
            int id = data.getID();
            String name = data.Name;
            String date = data.getDateOfBirth().toString();
            String city = data.getCity();
            int iq = data.getIQ();
            String line = id + "," + name + "," + date + "," + city + "," + iq; // make a string of all members
            out.write(line); // write string of all data into file
            out.newLine(); // and add new line
            out.close(); // closing wrting operation
        } catch (IOException ioe) { // catch exception if any throws
            ioe.printStackTrace();
        }

    }

    public void remove(int id) {
        for (Data d : listData) { // loop through all the data of list
            if (d.ID == id) {// check if id found
                listData.remove(d); // remove that record
                writingFile(false); // writing data to file after removing
                return; // return from function
            }
        }
        System.out.println("ID Not Found"); // if ID not found return
    }

    public void listing() {
        System.out.println("ID\tName\t\tDate of Birth\t City\t IQ");// print header
        System.out.println("-----------------------------------------------------");

        for (Data d : listData) {
            System.out.print(d.getID() + "\t" + d.getName() + "\t" + d.getDateOfBirth().getString() + "\t" + d.getCity()
                    + "\t" + d.getIQ() + "\n"); // print data
        }
    }

    public void readFile() {
        try (BufferedReader in = new BufferedReader(new FileReader("data.txt"))) {
            String str;
            while ((str = in.readLine()) != null) {
                String[] s = str.split(","); // split string to array by delimeter ,

                int id = Integer.parseInt(s[0]); // first part is ID
                String name = s[1]; // second is name
                String date = s[2];// third is date

                String[] dateArr = date.split(" "); // split date string by space

                int year = Integer.parseInt(dateArr[0]); // first part is year
                int mon = Integer.parseInt(dateArr[1]); // second part is month
                int day = Integer.parseInt(dateArr[2]); // third part id day

                Dates dates = new Dates(day, mon, year); // make date object
                String city = s[3]; // fourth is city name
                int iq = Integer.parseInt(s[4]);// last is iq
                Data dataObject = new Data(id, name, dates, city, iq); // make data object by calling parameterize
                                                                       // constructor
                listData.add(dataObject); // add object
            }
        } catch (IOException e) {
            System.out.println("File Read Error");
        }
    }

    public void sorting() {
        for (int i = 0; i < listData.size(); i++) {
            for (int j = i; j < listData.size(); j++) {
                if (listData.get(j).ID > listData.get(i).ID) {
                    Data temp = listData.get(j);
                    listData.set(j, listData.get(i));
                    listData.set(i, temp);
                }
            }
        }
        listing();
    }

    public void writingFile(boolean append) {
        try {
            // create Bufferedwriter instance with a FileWriter
            // the flag set to 'true' tells it to append a file if file exists
            BufferedWriter out = new BufferedWriter(new FileWriter("Data.txt", append));
            for (Data single : listData) { // loop through all data in the list
                String id = String.valueOf(single.getID());
                String name = single.Name;
                String date = single.getDateOfBirth().toString();
                String city = single.getCity();
                String iq = String.valueOf(single.getIQ());
                String line = id + "," + name + "," + date + "," + city + "," + iq; // make string of data
                out.write(line); // write to file

                out.newLine(); // add new line
            }
            out.close(); // close input operation
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }

    }

}
