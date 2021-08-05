
//unchecked user defined exception 
public class InvalidOperationException extends RuntimeException 
{
	  private String accId; //account id for the item that with error
	  private String transId; //transaction id for the item that with error	  
	  private String errorData; //data for the error or the reason of error
	  
	  
	  public String toString() 
	  {
		  //generate and return specific message that is meaningful to the error
		  if (errorData == null)  // first constructor was called      			  
			  return this.getClass().getSimpleName() + ": Transaction cannot be removed in AccountID:  AccountID: " + accId + "Transaction " + transId; 
		  
		  else // second constructor was called 
			  return this.getClass().getSimpleName() + ": Transaction cannot be removed in AccountID: " + accId + "Transaction " + transId + " reason: " + errorData;

	  }
	  public InvalidOperationException(String transId, String accId)
	  {
			 /*
			  * call super passing message: "Error found while loading the transaction number. TransactionID: " + transId
			  * assign parameter to attribute transId
			  */  
		   super("Error found while loading the object. TransactionID: " +  transId + " AccountID: " + accId);
		   this.accId= accId;
		   this.transId= transId; 
	  }
	  public InvalidOperationException(String transId, String accId, String errorData)
	  {
			// call super passing message: Transaction cannot be removed in AccountID: " + accId + "Transaction " + transId + " reason: " + errorData
		   super(": Transaction cannot be removed in AccountID: " + accId + "Transaction " + transId + " reason: " + errorData);
		   
		   //assign parameter to attribute accId, transId and errorData
		   this.accId= accId;
		   this.transId= transId; 
		   this.errorData= errorData;
	  }
}