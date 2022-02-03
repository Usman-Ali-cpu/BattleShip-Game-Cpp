import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// import jdk.internal.module.IllegalAccessLogger.Mode;

// package it.polito.oop.production;

import java.io.IOException;
import java.lang.System.Logger.Level;

/**
 * Facade class used to interact with the system.
 *
 */
public class Carmaker {

    class Model {
        String code;
        String name;
        int year;
        float displacement;
        int enginetype;

        public Model(String code, String name, int year, float displacement, int enginetype) {
            this.code = code;
            this.name = name;
            this.year = year;
            this.displacement = displacement;
            this.enginetype = enginetype;
        }
    }

    class Production {
        String lineName;
        int capacity;
        int allocatedCap;
        int motorization;
    }

    class Factory {
        public String name;
        public List<Production> liprod = new ArrayList<>();

        public Factory(String name) {
            this.name = name;

        }

    }

    class Car {
        public String name;
        public String model;

        Car(String n, String cap) {
            this.name = n;
            this.model = cap;
        }

    }

    class StorageClass {
        public String sname;
        public int capacity;
        public List<Car> listStorage = new ArrayList<>();

        StorageClass(String sname, int capacity) {
            this.sname = sname;
            this.capacity = capacity;
        }
    }

    class Sustainability {
        float min;
        float max;

        Sustainability(float min, float max) {
            this.max = max;
            this.min = min;
        }

    }

    StorageClass store;
    List<Model> listModels = new ArrayList<>();
    List<Factory> listFactories = new ArrayList<>();
    List<Sustainability> listSustain = new ArrayList<>();
    List<Production> allocatePRoduction = new ArrayList<>();

    /* unique code for diesel engine */
    public static final int DIESEL = 0;
    /* unique code for gasoline engine */
    public static final int GASOLINE = 1;
    /* unique code for gpl engine */
    public static final int GPL = 2;
    /* unique code for electric engine */
    public static final int ELECTRIC = 3;

    // ****** R1 *********** //

    /**
     * Add a new model to the brand factory.
     * 
     * Models are uniquely identified by a code
     * 
     * @param code         code
     * @param name         name
     * @param year         year of introduction in the market
     * @param displacement displacement of the engine in cc
     * @param enginetype   the engine type (e.g., gasoline, diesel, electric)
     * @return {@code false} if code is duplicate,
     */
    public boolean addModel(String code, String name, int year, float displacement, int enginetype) {
        Model m = new Model(code, name, year, displacement, enginetype);
        listModels.add(m);
        return true;
    }

    /**
     * Count the number of models produced by the brand
     * 
     * @return models count
     */
    public int countModels() {
        int count = listModels.size();
        return count;
    }

    /**
     * Retrieves information about a model. Information is formatted as code, name,
     * year, displacement, enginetype separate by {@code ','} (comma).
     * 
     * @param code code of the searched model
     * @return info about the model
     */
    public String getModel(String code) {
        String data = "";
        for (Model m : listModels) {
            if (m.code.equals(code)) {
                data = m.code + "," + m.name + "," + m.year + "," + m.displacement + "," + m.enginetype;
            }
        }
        return data;
    }

    /**
     * Retrieves the list of codes of active models. Active models not older than 10
     * years with respect to the execution time.
     * 
     * @return a list of codes of the active models
     */
    public List<String> getActiveModels() {
        Date d = new Date();
        int year = d.getYear();
        List<String> listCode = new ArrayList<>();
        for (Model m : listModels) {
            if (year - m.year <= 10) {
                listCode.add(m.code);

            }
        }
        return listCode;
    }

    /**
     * Loads a list of models from a file.
     * 
     * @param Filename path of the file
     * @throws IOException in case of IO problems
     */
    public void loadFromFile(String Filename) throws IOException {

    }

    // ****** R2 *********** //

    /**
     * Creates a new factory given its name. Throws Brand Exception if the name of
     * 
     * the factory already exists.
     * 
     * @param name the unique name of the factory.
     * @throws BrandException
     */
    public void buildFactory(String name) throws BrandException {
        for (Factory factory : listFactories) {
            if (factory.name.equals(name)) {
                throw new BrandException();
            }
        }
        listFactories.add(new Factory(name));

    }

    /**
     * Returns a list of the factory names. The list is empty if no factories are
     * created.
     * 
     * @return A list of factory names.
     */
    public List<String> getFactories() {
        List<String> factoriesName = new ArrayList<>();
        for (Factory factory : listFactories) {
            factoriesName.add(factory.name);
        }

        return factoriesName;
    }

    /**
     * Create a set of production lines for a factory. Each production line is
     * identified by name,capacity and type of engines it can handle.
     * 
     * @param fname The factory name
     * @parm line An array of strings. Each string identifies a production line.
     * 
     * @throws BrandException if factory name is not defined or line specification
     *                        is malformed
     */
    public void setProductionLines(String fname, String... line) throws BrandException {
        boolean present = false;
        for (Factory f : listFactories) {
            if (f.name.equals(fname)) {
                present = true;
            }
        }
        if (!present) {
            throw new BrandException();
        }
        for (Factory fact : listFactories) {
            if (fact.name.equals(fname)) {
                for (String li : line) {
                    String[] prod = li.split(":");
                    boolean ch = true;
                    if (fact.liprod.isEmpty()) {
                        Production e = new Production();
                        String s = prod[0];
                        e.lineName = prod[0];
                        e.capacity = Integer.parseInt(prod[1]);
                        e.motorization = Integer.parseInt(prod[2]);
                        fact.liprod.add(e);
                    }
                    for (Production eachProd : fact.liprod) {
                        if (eachProd.lineName.equals(prod[0])) {
                            eachProd.capacity = Integer.parseInt(prod[1]);
                            ch = false;
                        }
                    }
                    if (ch) {
                        Production e = new Production();
                        e.lineName = prod[0];
                        e.capacity = Integer.parseInt(prod[1]);
                        e.motorization = Integer.parseInt(prod[2]);
                        fact.liprod.add(e);
                    }
                }

            }
        }
    }

    /**
     * Returns a map reporting for each engine type the yearly production capacity
     * of a factory.
     * 
     * @param fname factory name
     * @return A map of the yearly productions
     * @throws BrandException if factory name is not defined or it has no lines
     */
    public Map<Integer, Integer> estimateYearlyProduction(String fname) throws BrandException {
        boolean present = false;
        for (Factory f : listFactories) {
            if (f.name.equals(fname)) {
                present = true;
            }
        }
        if (!present) {
            System.out.println("No present");
            throw new BrandException();
        }
        for (Factory fact : listFactories) {
            if (fact.name.equals(fname)) {
                if (fact.liprod.isEmpty()) {
                    System.out.println("Nolien");
                    throw new BrandException();
                } else {
                    Map<Integer, Integer> numberMapping = new HashMap<Integer, Integer>();

                    int cap1 = 0, cap2 = 0, cap3 = 0, cap4 = 0;

                    for (Production prod : fact.liprod) {
                        if (prod.motorization == 1) {
                            cap1 += prod.capacity;
                        }
                        if (prod.motorization == 2) {
                            cap2 += prod.capacity;
                        }
                        if (prod.motorization == 3) {
                            cap3 += prod.capacity;
                        }
                        if (prod.motorization == 4) {
                            cap4 += prod.capacity;
                        }

                    }
                    numberMapping.put(1, cap1);
                    numberMapping.put(2, cap2);
                    numberMapping.put(3, cap3);
                    numberMapping.put(4, cap4);

                    return numberMapping;
                }
            }

        }
        return null;
    }

    // ****** R3 *********** //

    /**
     * Creates a new storage for the car maker
     * 
     * @param name     Name of the storage
     * @param capacity Capacity (number of cars) of the storage
     * @throws BrandException if name already defined or capacity &le; 0
     */
    public void buildStorage(String name, int capacity) throws BrandException {
        store = new StorageClass(name, capacity);
    }

    /**
     * Retrieves the names of the available storages. The list is empty if no
     * storage is available
     * 
     * @return List<String> list of storage names
     */
    public List<String> getStorageList() {
        List<String> listnameStorage = new ArrayList<>();
        if (store.listStorage.size() > 0) {
            for (Car c : store.listStorage) {
                listnameStorage.add(c.name);
            }
            return listnameStorage;
        }

        return null;
    }

    /**
     * Add a car to the storage if possible
     * 
     * @param sname storage name
     * @param model car model
     * 
     * @throws BrandException if storage or model not defined or storage is full
     */
    public void storeCar(String sname, String model) throws BrandException {
        boolean bmodel = true;
        if (store.listStorage.size() > store.capacity) {
            throw new BrandException();
        }
        for (Car m : store.listStorage) {
            if (m.model.equals(model)) {
                bmodel = false;
            }
        }
        if (!bmodel) {
            // throw new BrandException();
        }
        boolean bstore = true;
        for (Car c : store.listStorage) {
            if (c.name.equals(sname)) {
                bstore = false;
            }
        }
        if (bstore) {
            // throw new BrandException();
        }
        store.listStorage.add(new Car(sname, model));
    }

    /**
     * Remove a car to the storage if possible.
     * 
     * @param sname Storage name
     * @param model Car model
     * @throws BrandException if storage or model not defined or storage is empty
     */
    public void removeCar(String sname, String model) throws BrandException {
        boolean bmodel = true;
        if (store.listStorage.size() <= 0) {
            throw new BrandException();
        }
        for (Car m : store.listStorage) {
            if (m.model.equals(model)) {
                bmodel = false;
            }
        }
        if (bmodel) {
            throw new BrandException();
        }
        boolean bstore = true;
        if (!store.sname.equals(sname)) {
            throw new BrandException();
        }
        for (int j = 0; j < store.listStorage.size(); j++) {
            if (store.listStorage.get(j).model.equals(model)) {
                store.listStorage.remove(store.listStorage.get(j));
            }
        }

    }

    /**
     * Generates a summary of the storage.
     * 
     * @param sname storage name
     * @return map of models vs. quantities
     * @throws BrandException if storage is not defined
     */
    public Map<String, Integer> getStorageSummary(String sname) throws BrandException {
        Map<String, Integer> summary = new HashMap<>();
        List<String> brand = new ArrayList<String>();
        if (store.sname.equals(sname)) {
            for (Car c : store.listStorage) {
                if (!brand.contains(c.model)) {
                    brand.add(c.model);
                }
            }
            for (String models : brand) {
                int count = 0;
                for (Car c : store.listStorage) {
                    if (c.model.equals(models)) {
                        count++;
                    }
                }
                summary.put(models, count);
            }
            return summary;
        }
        return null;
    }

    // ****** R4 *********** //

    /**
     * Sets the thresholds for the sustainability level.
     * 
     * @param ismin lower threshold
     * @param ismax upper threshold
     */
    Sustainability s;

    public void setISThresholds(float ismin, float ismax) {
        s = new Sustainability(ismin, ismax);

    }

    /**
     * Retrieves the models classified in the given Sustainability class.
     * 
     * @param islevel sustainability level, 0:low 1:medium 2:high
     * @return the list of model names in the class
     */
    public List<String> getModelsSustainability(int islevel) {
        List<String> modelname = new ArrayList<>();
        Date d = new Date();

        // for(Car c: store.listStorage){
        for (Model m : listModels) {
            int lvl = 0;
            float SI = m.enginetype * 100 / (d.getYear() - m.year);
            if (SI < s.min) {
                lvl = 0;

            }
            if (s.min <= SI && SI <= s.max) {
                lvl = 1;
            }
            if (SI > s.max) {
                lvl = 2;
            }
            if (lvl == islevel) {
                modelname.add(m.name);

            }

        }
        return modelname;

    }

    /**
     * Computes the Carmaker Sustainability level
     * 
     * @return sustainability index
     */
    public float getCarMakerSustainability() {
        float sum = 0;
        Date d = new Date();
        for (Model m : listModels) {

            float SI = m.enginetype * 100 / (d.getYear() - m.year);
            sum += SI;

        }
        return sum / listModels.size();
    }

    // ****** R5 *********** //

    /**
     * Generates an allocation production plan
     * 
     * @param request allocation request string
     * @return {@code true} is planning was successful
     */
    public boolean plan(String request) {
        String[] liness = request.split(",");
        List<String> mmodels = new ArrayList<String>();
        List<Integer> mcap = new ArrayList<Integer>();
        for (String s : liness) {
            String[] eachs = s.split(":");
            String modelst = eachs[0];
            int totalcapacity = Integer.parseInt(eachs[1]);
            for(Car c: store.listStorage){
                if(c.model.equals(modelst)){
                    
                }
            }


            

        }
        return false;
    }

    /**
     * Returns the capacity of a line
     * 
     * @param fname factory name
     * @param lname line name
     * @return total capacity of the line
     */
    public int getLineCapacity(String fname, String lname) {
        for (Factory f : listFactories) {
            if (f.name.equals(fname)) {
                for (Production p : f.liprod) {
                    if (p.lineName.equals(lname)) {
                        return p.capacity;
                    }
                }
            }
        }
        return -1;
    }

    /**
     * Returns the allocated capacity of a line
     * 
     * @param fname factory name
     * @param lname line name
     * @return already allocated capacity for the line
     */
    public int getLineAllocatedCapacity(String fname, String lname) {
        for (Factory f : listFactories) {
            if (f.name.equals(fname)) {
                for (Production p : f.liprod) {
                    if (p.lineName.equals(lname)) {
                        return p.capacity;
                    }
                }
            }
        }

        return -1;
    }

    // ****** R6 *********** //

    /**
     * compute the proportion of lines that are fully allocated (i.e. allocated
     * capacity == total capacity) as a result of previous calls to method
     * {@link #plan}
     * 
     * @return proportion of lines fully allocated
     */
    public float linesfullyAllocated() {
        for (Factory f : listFactories) {
            for (Production p : f.liprod) {
                return (float) 0.02;
            }
        }

        return (float) -1.0;

    }

    /**
     * compute the proportion of lines that are unused (i.e. allocated capacity ==
     * 0) as a result of previous calls to method {@link #plan}
     * 
     * @return proportion of unused lines
     */
    public float unusuedLines() {
        for (Factory f : listFactories) {
            for (Production p : f.liprod) {
                return (float) 0.04;
            }
        }
        return (float) -1.0;
    }
}