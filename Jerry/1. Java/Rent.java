
public class Rent extends Transaction //rent is a child class that inherits all the properties of the parent transaction class

{

	private int numOfDays; //number of days rent
	
	private float rentDailyRate; //daily rent rate
	
	    //  calculate price of the rent transaction
	@Override
	  // calculate and return the rent price based on the flat fee, number of days & daily rent rate
	  public float calculatePrice() 
	  {
		  /*
�	calculate and return the rent price based on the flat fee, number of days & daily rent rate
�	calculate flat fee plus the number of days multiplied by daily rate
�	return 2.99 + (numOfDays * rentDailyRate)	  
  
		   */
		float price = FLATFEE + (numOfDays * rentDailyRate);
		return price;
	  }
	
	  //create and return a copy of the object
	  public Rent clone() 
	  {
		  /*
�	Overloaded Rent clone() without parameter
�	create and return a copy of the object
�	return new Rent(this.numOfDays, this.rentDailyRate);

		   */
		  return new Rent(this.numOfDays, this.rentDailyRate);
	  }
	
	  //update rent cost before completing transaction
	  public void updateRent(int numOfDays, float rentDailyRate) 
	  {	
		  /* �	validate parameters for class
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw llegalArgumentException
�	assign all the parameters' values to attributes
�	update rent cost before completing transaction and then complete transaction 

		   */
		  this.numOfDays = numOfDays;
		  this.rentDailyRate = rentDailyRate;
	  }
	
	  @Override
	  // method that overrides Object's toString() 
	  //toString formats and returns object's data in XML format
	  public String toString() 
	  {
		  //(for better tracking and visual, added XML tag for pseudo code for each attribute in a separate line)
		  /*
		   * have tags for all attributes - unique and inherited (should call parent�s toString() and concatenate)
		   * return a string with tags and values for each attribute that has the following values and format:	
		   *  return "<rent>" + super.toString() + "<numOfDays>" + numOfDays + "</numOfDays>" 
		   	  + "<rentDailyRate>" + rentDailyRate + "</rentDailyRate>" + "</rent>"; 
		   */

		  return "<rent>" + super.toString() + "<numOfDays>" + numOfDays + "</numOfDays>" 
		   	  + "<rentDailyRate>" + rentDailyRate + "</rentDailyRate>" + "</rent>";
	  }
	  
	//OVERLOADING: Both of the constructors named, "Rent" below have the same method name but different parameters
	//this is a constructor method that is created for the class
	  public Rent(String transId, String description, int numOfDays, float rentDailyRate) 
	  {
		  super(transId, description);  //call parent's constructor
		//validate all the parameters, validate that the data is parsing or data is found properly, if not, throw llegalArgumentException 
		 	if (transId == null || transId.length() == 0 || description == null || description.length() == 0
	    			|| numOfDays < 0 || rentDailyRate < 0)
	    		throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
		 	
		 	//assign all the parameters' values to attributes 
		 	this.transId = transId;
		 	this.description = description;
		 	this.numOfDays = numOfDays;
		 	this.rentDailyRate = rentDailyRate;
		  
	  }
	  
	  public Rent(String line) throws RuntimeException
	  {
		  super(line);  // parses out and loads fields that are common
		  
		  //validate all the parameters, validate that the data is parsing or data is found properly, if not, throw llegalArgumentException
		  if ( numOfDays < 0 || rentDailyRate < 0)
	    		throw new IllegalArgumentException("Attribute values cannot be null or empty strings");
		 			 		     
		  numOfDays = Integer.parseInt(line.substring(line.indexOf("<numOfDays>") + 11, line.indexOf("</numOfDays>")));        		   
		  rentDailyRate = Float.parseFloat(line.substring(line.indexOf("<rentDailyRate>") + 15, line.indexOf("</rentDailyRate>"))); 
	  }


	public Rent(int numOfDays2, float rentDailyRate2) {
		super("None", "None");
		this.numOfDays = numOfDays2;
		this.rentDailyRate = rentDailyRate2; 
	}

	public int getNumOfDays() 	// get method to return the value of the NumOfDays attribute
	  {
		  return numOfDays; // get method returns the value of NumOfDays on creation
	  }

	
	  public float getRentDailyRate() // get method to return the value of the RentDailyRate attribute
	  {
		  return rentDailyRate; //get method returns the value of RentDailyRate on creation		  
	  }

	// set method to update the value of attribute NumOfDays
	  public void setNumOfDays(int numOfDays)
	  {
		  { 	//attribute value is changed through a set method instead of changing the attribute directly
			  
			  //should throw IllegalStateException if transaction is already completed
			  if (status == true)
				  throw new IllegalStateException("Transaction is already completed");
			 
			  //throw IllegalArgumentException 
			  if (numOfDays < 0)
		    		throw new IllegalArgumentException("Value cannot be null or empty string or a negative number");
				
				this.numOfDays = numOfDays;
		  }
	  }

	// set method to update the value of attribute RentDailyRate
	  public void setRentDailyRate(float rentDailyRate) 
	  {

		  { 	//attribute value is changed through a set method instead of changing the attribute directly
			  
			  //should throw IllegalStateException if transaction is already completed
			  if (status == true)
				  throw new IllegalStateException("Transaction is already completed");
			 
			  //throw IllegalArgumentException 
			  if (rentDailyRate < 0)
		    		throw new IllegalArgumentException("Value cannot be null or empty string or a negative number");
				
				this.rentDailyRate = rentDailyRate;
		  }
	  }


	  public Rent clone(String line)
	  {
		  /*  
�	Overloaded Rent clone() takes 1 parameter
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing, or data is found properly, if not, throw llegalArgumentException 
�	the code processes a file and then it loads the data from file by reading a line, then it calls the corresponding constructor to parse data and assign attribute 
		   */
		  return new Rent(line);
	  }

}