

//import InvalidLoadException;

public class Purchase extends Transaction //purchase is a child class that inherits all the properties of the parent transaction class

{

	private int numOfItems; //purchase item
	
	private float pricePerItem; //price of the item being purchased
	
	    //  calculate price of the purchase transaction
	@Override
	  // calculate and return the purchase price based on the flat fee, purchase item amount, price of each item
	  public float calculatePrice() 
	  {
	  
		  /*
�	calculate and return the purchase price based on the flat fee, purchase item amount, price of each item
�	calculate flat fee plus the number of items multiplied by price per item
�	return 2.99 + (numOfItems * pricePerItem)	
  
		   */

		  float price = (float) (2.99 + (numOfItems * pricePerItem));
		  return price;
	  }
	
	//create and return a copy of the object
	  public Purchase clone() 
	  {
		  /*
�	Overloaded Purchase clone() without parameter
�	create and return a copy of the object
�	return new Purchase(this.numOfItems, this.pricePerItem);

		   */
		  return new Purchase(description, description, this.numOfItems, this.pricePerItem);
	  }
	
	  //update purchase item before completing transaction
	  public void updatePurchase(int numOfItems, float pricePerItems) 
	  {
		  /* 
�	validate parameters 
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw llegalArgumentException
�	assign all the parameters' values to attributes 
�	update purchase item before completing transaction and then complete transaction

		   */
	  }
	  @Override
	// method that overrides Object's toString() 
	//toString formats and returns object's data in XML format
	  public String toString() 
	  {
		//(for better tracking and visual, added XML tag for pseudo code for each attribute in a separate line)
		  /*
		   *  have tags for all attributes - unique and inherited (should call parent�s toString() and concatenate)
		   *  return a string with tags and values for each attribute that has the following values and format:	s
		   *  return "<purchase>" + super.toString() + "<numOfItems>" + numOfItems + "</numOfItems>" 
		      + "<pricePerItem>" + pricePerItem + "</pricePerItem>" + "</purchase>"; 
		   */
		   return "<purchase>" + super.toString() + "<numOfItems>" + numOfItems + "</numOfItems>" 
		      + "<pricePerItem>" + pricePerItem + "</pricePerItem>" + "</purchase>";
	  }
	
	//OVERLOADING: Both of the constructors named, "Purchase" below have the same method name but different parameters
	  
	//this is a constructor method that is created for the class
	  public Purchase(String transId, String description, int numOfItems, float pricePerItem)
	  
	  {	 		  
		  //call parent's constructor
		  super(transId, description);
		  		 	
		  //validate all the parameters, validate that the data is parsing or data is found properly, if not, throw llegalArgumentException 
		 	if (transId == null || transId.length() == 0 || description == null || description.length() == 0
	    			|| numOfItems < 0 || pricePerItem < 0)
	    		throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
		 	
		 	//assign all the parameters' values to attributes 
		 	this.transId = transId;
		 	this.description = description;
		 	this.numOfItems = numOfItems;
		 	this.pricePerItem = pricePerItem;
	  	}
	  
	  
  
	  public Purchase(String line) throws RuntimeException
	  {
		  super(line); // parses out and loads fields that are common
		  		  	  
		  //validate all the parameters, validate that the data is parsing or data is found properly, if not, throw llegalArgumentException 
		 	if ( numOfItems < 0 || pricePerItem < 0)
	    		throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
		 	
		 // method to parse out and assign to attributes the values from toString() formatted line	
		  numOfItems = Integer.parseInt(line.substring(line.indexOf("<numOfItems>") + 12, line.indexOf("</numOfItems>")));        
		  pricePerItem = Float.parseFloat(line.substring(line.indexOf("<pricePerItem>") + 14, line.indexOf("</pricePerItem>")));        

	  }
	  
	  public Purchase clone(String line) 
	  {
		  /*  
�	Overloaded Purchase clone() takes 1 parameter
�	validate that the data is parsing properly, if not, throw llegalArgumentException 
�	the code processes a file 
�	it loads the data from file by reading a line and calls the corresponding constructor to parse data and assign attribute 
		   */
		  return null;
	  }


	  public int getNumOfItems() 	// get method to return the value of the NumOfItems attribute
	  {
		  return numOfItems; // get method returns the value of NumOfItems on creation
	  }

	
	  public float getPricePerItem() // get method to return the value of the PricePerItem attribute
	  {
		  return pricePerItem; //get method returns the value of PricePerItem on creation
	  }


	  public void setNumOfItems(int numOfItems) 	// set method to update the value of attribute NumOfItems
	  {	  //attribute value is changed through a set method instead of changing the attribute directly
		  
		  //should throw IllegalStateException if transaction is already completed
		  if (status == true)
			  throw new IllegalStateException("Transaction is already completed");
		 
		  //throw IllegalArgumentException 
		  if (numOfItems < 0)
	    		throw new IllegalArgumentException("Value cannot be null or empty string or a negative number");
			
			this.numOfItems = numOfItems;
	  }

	//IllegalStateException, is the If condition for status=true good?
	  
	  public void setPricePerItem(float pricePerItem) // set method to update the value of attribute PricePerItem
	  { 	//attribute value is changed through a set method instead of changing the attribute directly
		  
		  //should throw IllegalStateException if transaction is already completed
		  if (status == true)
			  throw new IllegalStateException("Transaction is already completed");
		 
		  //throw IllegalArgumentException 
		  if (pricePerItem < 0)
	    		throw new IllegalArgumentException("Value cannot be null or empty string or a negative number");
			
			this.pricePerItem = pricePerItem;
	  }
}
