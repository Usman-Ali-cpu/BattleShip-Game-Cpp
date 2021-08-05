
import java.util.Date;

public abstract class Transaction //transaction is a parent class that holds 3 child classes: rent, travel & purchase

{

	protected String transId; //unique ID for transaction   
	
	public float FLATFEE; //flat fee for any type of transaction is $2.99
	
	protected Date date; //date of the transaction completion
	
	protected String description; //description of the transaction, there is 500 char restriction
	
	protected boolean status; //specifies which value represents what such as active=true and inactive=false
		  
	protected float transactionCost; //transaction cost based on specific transaction
	
	/*
	 * Overriding method for child classes: purchase, rent, travel
	 * method that overrides Object's toString()
	 */
 	//toString formats and returns object's data in XML format
	  public String toString() 
	  {
		//(for better tracking and visual, added XML tag for pseudo code for each attribute in a separate line)
		  /*return a string with tags and values for each attribute that has the following values and format:	
		   * should have unique tags for all attributes
		   *  return "<transaction>" + "<transId>" + transId + "</transId>" 
		      + "<date>" + date + "</date>" 
		      + "<description>" + description + "</description>" 
		      + "<status>" + status + "</status>" 
		      + "<transactionCost>" + transactionCost + "</transactionCost>" + "</transaction>"; 
		   */
		  return "<transaction>" + "<transId>" + transId + "</transId>" 
		  + "<date>" + date + "</date>" 
		  + "<description>" + description + "</description>" 
		  + "<status>" + status + "</status>" 
		  + "<transactionCost>" + transactionCost + "</transactionCost>" + "</transaction>";
	  }
	
	// abstract method so that children classes must implement clone
	  public abstract Transaction clone(); 
	    /*
	     *  abstract method
	     *  it has no body
	     */
	  
	  public boolean transactionComplete() 
	  {
		  /*
�	if transaction is already completed, throw IllegalStateException 
�	return the Boolean value if the transaction is completed using true or false
�	it checks for incomplete transaction and then set date, status, call calculate method and set transaction cost
�	it also updates the transaction file

		   */
		  
		  return false;
	  }
	
	  
	  public float calculatePrice()
	  {
		  /*
		   * Overriding method for child classes: purchase, rent, travel
		   * return flat fee 2.99 
		   */
		  
		  return 2.99f;
	  }
	
	  
	  //OVERLOADING: Both of the constructors named, "Transaction" below have the same method name but different parameters
	   	  
	  //this is a constructor method that is created for the class
	  public  Transaction(String transId, String description) 
	  {
		  
	    	// validate parameters
	    	if (transId == null || transId.length() == 0 || description == null || description.length() == 0)
	    		throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
	    	
	    	this.transId = transId;
	    	this.description = description;
	    	
		  /* 
�	Overloaded Transaction takes 2 parameters
�	validate parameters 
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw IllegalArgumentException

		   */
	  } 

		  public Transaction(String line) 
		  {
			  
			  //validate all the parameters, validate that the data is parsing or data is found properly, if not, throw llegalArgumentException 
			 	if (transId == null || transId.length() == 0 || description == null || description.length() <= 500)
		    		// throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
			 	
			 // method to parse out and assign to attributes the values from toString() formatted line	
			 	transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>")); 
				 
			 	description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));        

			  /*  
�	Overloaded Transaction takes 1 parameter
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw IllegalArgumentException 
�	the code processes a file 
�	it loads the data from file and calls the corresponding constructor to parse data and assign attribute
			   */
		  }
		  
		  
		  /*
		   * constructor to create Transaction object loading values from a file
		   * create a Vector object for transactions
		   * read first line and load transaction level attributes
		   * loop for the rest of the file loading all Transaction objects using appropriate constructors
		   * found purchase transaction so call its constructor
		   * found rent transaction so call its constructor
		   * found travel transaction so call its constructor
		   * caught an error so can close file
		   * re-throw so that UI gets and takes appropriate action
		   */
		  

		// abstract method so that children must implement clone
		  public abstract Transaction clone(String line); 
		    /*
		     *  abstract method
		     *  it has no body
		     */
		   
		  
		  // get method to return the value of the TransId attribute
		  public String getTransId()
		  {
			  /*
			   * get method returns the value of TransId on creation
			   */
			  return transId;
		  }

		  
		  // get method to return the value of the Date attribute
		  public Date getDate() 
		  {
			  /*
			   * get method returns the value of Date on creation
			   */
			  return date;
		  }

		  // get method to return the value of the Description attribute
		  public String getDescription() 
		  {
			  /*
			   * get method returns the value of Description on creation
			   */
			  return description;
		  }

		  // get method to return the value of the Status attribute
		  public boolean getStatus()
		  {
			  /*
			   * get method returns the value of Status on creation
			   */
			  return status;
		  }

		  // get method to return the value of the TransactionCost attribute
		  public float getTransactionCost()
		  {
			  /*
			   * get method returns the value of TransactionCost on creation
			   */
			  return transactionCost;
		  }


		  // set method to update the value of attribute Description
		  public void setDescription(String description) 
		  {

			  /*

�	should throw IllegalStateException if transaction is already completed
�	set method to update the value of attribute Description
�	attribute value is changed through a set method instead of changing the attribute directly
�	should also validate max 500 characters

			   */
			//should throw IllegalStateException if transaction is already completed
			  if (status = true)
				  throw new IllegalStateException("Transaction is already completed");
			  
				// validate that parameter value is not null or empty string
			  //should also validate max 500 characters
		    	if (description ==null || description.length() <= 500)
		    		throw new IllegalArgumentException("Parameter value cannot be null or empty string");
				this.description = description;
		  }


	  }

