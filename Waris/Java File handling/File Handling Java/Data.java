// class of data to store resources of object
public class Data {
    int ID; // to store ID of object
    String Name; // to store name of object
    Dates DateOfBirth; // to store birthday
    String City; // to store city name
    int IQ; // to store IQ level

    // parameterize constructor of Data, passing values would be assign to data
    // members
    public Data(int id, String name, Dates date, String city, int iq) {
        this.ID = id; // setting id
        this.Name = name; // setting name
        this.City = city; // setting city
        this.IQ = iq; // setting iq
        this.DateOfBirth = date; // setting birthday
    }

    // set for city
    public void setCity(String city) {
        City = city;
    }

    // setter for date of birth
    public void setDateOfBirth(Dates dateOfBirth) {
        DateOfBirth = dateOfBirth;
    }

    // setter for ID
    public void setID(int iD) {
        ID = iD;
    }

    // setter for IQ
    public void setIQ(int iQ) {
        IQ = iQ;
    }

    // setter for name
    public void setName(String name) {
        Name = name;
    }

    // getter for city
    public String getCity() {
        return City;
    }

    // getter for date of birth
    public Dates getDateOfBirth() {
        return DateOfBirth;
    }

    // return string to date
    public String getStringDate() {
        String str = "";
        str = DateOfBirth.toString();
        return str;
    }

    // getter for ID
    public int getID() {
        return ID;
    }

    // getter for IQ
    public int getIQ() {
        return IQ;
    }

    // getter for name
    public String getName() {
        return Name;
    }

}
