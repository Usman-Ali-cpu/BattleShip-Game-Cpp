
public class Travel extends Transaction //travel is a child class that inherits all the properties of the parent transaction class
{

	private float travelCost; //cost of travel transaction
	
	  
	    //  calculate price of the travel transaction
	@Override
		// calculate and return the travel price based on the flat fee, travel cost
	  public float calculatePrice()
	  {
		  /*
�	calculate and return the travel price based on the flat fee, travel cost 
�	calculate flat fee plus the travel cost
�	return 2.99 + travel cost	
	  
		   */
		  return (float) (2.99 + travelCost);
	  }
	
	//create and return a copy of the object
	  public Travel clone()
	  {
		  /*
�	Overloaded Travel clone() without parameter
�	create and return a copy of the object
�	return new Travel(this.travelCost);

		   */
		  return new Travel(transId, description, this.travelCost);
	  }
	
	//update travel cost before completing transaction
	  public void updateTravel(float travelCost)
	  {
		  /* �	validate parameters for class
�	assign all the parameters' values to attributes 
�	update travel cost before completing transaction and then complete transaction 

		   */
		this.travelCost = travelCost;
		
	  }
	  
	  @Override
	// method that overrides Object's toString() 
	//toString formats and returns object's data in XML format
	  public String toString() 
	  {
		  /*
		   * have tags for all attributes - unique and inherited (should call parent�s toString() and concatenate)
		   * return a string with tags and values for each attribute that has the following values and format:	
		   *  return "<travel>" + super.toString() + "<travelCost>" + travelCost + "</travelCost>" + "</travel>"; 
		   */
		  return "<travel>" + super.toString() + "<travelCost>" + travelCost + "</travelCost>" + "</travel>";
	  }
	  
	//OVERLOADING: Both of the constructors named, "Travel" below have the same method name but different parameters
	
	//this is a constructor method that is created for the class
	  public Travel(String transId, String description, float travelCost)
	  {
		  super(transId, description);
		  
		  //validate all the parameters, validate that the data is parsing or data is found properly, if not, throw llegalArgumentException 
		 	if (transId == null || transId.length() == 0 || description == null || description.length() == 0
	    			|| travelCost < 0)
	    		throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
		 	
		 	//assign all the parameters' values to attributes 
		 	this.transId = transId;
		 	this.description = description;
		 	this.travelCost = travelCost;
		 	
		  
	  }
	  
	  public Travel(String line) throws RuntimeException
	  {
		  super(line); // parses out and loads fields that are common
		  	  
		  //validate all the parameters, validate that the data is parsing or data is found properly, if not, throw llegalArgumentException 
		 	if ( travelCost < 0 )
	    		throw new IllegalArgumentException("Attribute values cannot be null or empty strings");		 			 		    
		   
		  travelCost = Float.parseFloat(line.substring(line.indexOf("<travelCost>") + 12, line.indexOf("</travelCost>")));        

	  }

	  public Travel clone(String line) 
	  {
		  /*  
�	Overloaded Travel clone() takes 1 parameter
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw llegalArgumentException 
�	the code processes a file 
�	it loads the data from file by reading a line and calls the corresponding constructor to parse data and assign attribute 
		   */

		  return new Travel(line);
	  }

	
	  public float getTravelCost() // get method to return the value of the TravelCost attribute
	  {
		  return travelCost; //get method returns the value of TravelCost on creation		 
	  }

	
	  public void setTravelCost(float travelCost) // set method to update the value of attribute TravelCost
	  { 	//attribute value is changed through a set method instead of changing the attribute directly
		  
		  //should throw IllegalStateException if transaction is already completed
		  if (status == true)
			  throw new IllegalStateException("Transaction is already completed");
		 
		  //throw IllegalArgumentException 
		  if (travelCost < 0)
	    		throw new IllegalArgumentException("Value cannot be null or empty string or a negative number");
			
			this.travelCost = travelCost;
	  }


}