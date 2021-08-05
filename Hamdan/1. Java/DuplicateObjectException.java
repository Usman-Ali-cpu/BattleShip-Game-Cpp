
//unchecked user defined exception 

public class DuplicateObjectException extends RuntimeException 
	{

	  private String accId; //account id for the item that with error

	  private String transId; //transaction id for the item that with error
	  
	  private String errorData; //data for the error or the reason of error

	  public String toString() 
	  {
		  //generate and return specific message that is meaningful to the error based on which constructor was called 

		if (transId == null)  // first constructor was called 
			     return this.getClass().getSimpleName() + ": Account already exists: " + accId; 
			
		else // second constructor was called 
			     return this.getClass().getSimpleName() + ": Transaction already exists "  +  transId +  "in account " + accId + " reason: " + errorData;
	
	  }

	  public DuplicateObjectException(String accId)
	  {
		  //call super passing message: ": Account already exists: " + accId
		   super("Account already exists: " + accId);
		   
		   //assign parameter to attribute accId
		   this.accId=accId;

	  }

	  public DuplicateObjectException(String accId, String transId, String errorData) 
	  {
		   //call super passing message: ": Transaction already exists "  +  transId +  "in account " + accId + " reason: " + errorData
		   super(": Transaction already exists" + accId + "transaction: " +  transId + " reason: " + errorData);
		   
		   //assign parameter to attribute accId, transId and errorData
		   this.accId=accId;
		   this.transId=transId; 
		   this.errorData=errorData;
		  
	  }
	  
	  
	}