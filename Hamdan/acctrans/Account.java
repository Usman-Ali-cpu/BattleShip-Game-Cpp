
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Vector;


public class Account
{

  private String accId;  //account ID information

  private Owner owner; //owner information which includes multiple info items that would come from the Owner class
  //Relationship & Cardinality: Composition - 1 Account class must have 1 Owner ; 1 to 1 cardinality


	private int size;
  private Vector <Transaction> transObjects = new Vector<Transaction>();//save and manage multiple list of transaction objects
  //Relationship & Cardinality: Composition - 1 Account class can contain none or more transactions; 0..* null or more objects in one Account class



  private boolean status; //specifies which value represents what such as active=true and inactive=false

  //toString formats and returns object's data in XML format
  public String toString()
	  {
		//(for better tracking and visual, added XML tag for pseudo code for each attribute in a separate line)
		  /*
�	return a string with unique tags and values for each attribute that has the following values and format:
return "<account>" + "<accId>" + accId + "</accId>" + "<owner>" + owner + "</owner>" + "<status>" + status + "</status>" + "</account>";

		   */

		return "<account>" + "<accId>" + accId + "</accId>" + "<owner>" + owner + "</owner>" + "<status>" + status + "</status>" + "</account>";
	  }

  public Account clone()
  {
	return new Account(this.accId, this.owner);
  }

//add transaction using the unique transaction ID to the currently loaded transaction
  public void addTransactionToAccount(Transaction transaction)
	  {
		  /*
�	validate parameters
�	if account is inactive, throw IllegalStateException
�	If the parameter is null, the method should throw IllegalArgumentException
�	if transaction already exists, throw DuplicateObjectException
�	When creating transaction, if it already exists in the system, throw DuplicateObjectException
�	once the object is added to the list of objects, a transaction file should be created or updated
�	add transaction clone to transactions

		   */

		// validate the parameter
		if (transaction == null)
			throw new IllegalArgumentException("Passed value is null");

		// TODO: do not allow adding if past date

		// check if already exists and throw exception if does not
		int size = transObjects.size();  // get the number of transactions

		for (int i=0; i < size; i++) { // loop through transactions to find one matching accId

			if (transObjects.get(i).getTransId().equalsIgnoreCase(transaction.getTransId()))
		{
			// already exists so throw exception
			// throw new DuplicateObjectException("Account already exists");

	  /*
	   * If the parameter is null, the method should throw IllegalArgumentException
	   * When creating an account, if it already exists in the system, throw DuplicateObjectException
	   * Validate that the account is not a duplicate and add to the vector
	   * Validate account parameter.
	   * Assign parameter to attribute.
	   * Once the object is added to the list of objects, a new account file should be created
	   */
  	}
}
	  		Transaction trans = transaction.clone(); // create clone to add so UI cannot change directly
	  		transObjects.add(trans);  // add transactions to list/collection that Account stores and manages
			//   System.out.println("Added is class Account ");

	  }

	//UI allows for the system to remove transaction using the unique transaction ID
	//the requirement, page#1, paragraph 4 states that system allows removing of transaction from an account
	//my understanding here is that when the transaction is draft or incomplete, only then system will allow for the transaction to be removed, otherwise it will not

public void removeDraftTransactionFromAccount(String transId)
{
	  /*
�	if account is inactive, throw IllegalStateException
�	if transaction found as draft/incomplete, while removing transaction if there is an error, throw InvalidOperationException
�	find transaction in the list of transactions and check that transaction is incomplete
�	if transaction is not found, throw IllegalArgumentException
�	if transaction is already completed, throw IllegalStateException
�	it should remove from the list of objects and also delete the transaction file


	   */
	if(this.status == false){
		throw new IllegalStateException("Account is inactive");

	}
	  int size = transObjects.size();  // get the number of transactions

	for (int i=0; i < size; i++) { // loop through transactions to find one matching accId

		if (transObjects.get(i).getTransId().equalsIgnoreCase(transId))
		{
			// already exists so throw exception
			if(transObjects.get(i).status == true){
				// throw new IllegalStateException("Transaction is already completed");
				return;
			}
			else{
				transObjects.remove(i);
				return;
			}
  		}
	}
	throw new IllegalArgumentException("Transaction is not found ");



}


//complete transaction using the unique transaction ID
  public void completeTransaction(String transid)
{
		  /*
�	if account is inactive, throw IllegalStateException
�	if transaction was not found, throw IllegalArgumentException
�	check draft transaction using transaction ID
�	once it finds the draft transaction object, then complete transaction from list
		   */
	if(this.status == false){
		throw new IllegalStateException("Account is inactive");
	}
	int size = this.transObjects.size();  // get the number of transactions

		for (int i=0; i < size; i++) { // loop through transactions to find one matching accId

			if (transObjects.get(i).getTransId().equals(transid))

			{
				// already exists so throw exception
				if(transObjects.get(i).status == true){
					throw new IllegalStateException("Transaction is already completed");
				}
				else{
					transObjects.get(i).status = true;
					return;
				}
			}
		}
		throw new IllegalArgumentException("Transaction is not found ");


}

	//retrieve transaction using the unique transaction ID
  public Transaction retrieveTransaction(String transId)
	  {
		  /*
�	validate that a transaction is existing using transaction ID
�	retrieve the transaction for the account that was completed
�	return null if cannot find transaction
�	return clone for inactive account
�	return Transaction

		   */
		if(this.status == false){
			throw new IllegalStateException("Account is inactive");
		}
		int size = transObjects.size();  // get the number of transactions

		for (int i=0; i < size; i++) { // loop through transactions to find one matching accId

				if (transObjects.get(i).getTransId().equalsIgnoreCase(transId))
				{
					// already exists so throw exception
					return transObjects.get(i);
				}
		}
	   	return null;
	  }

  //save current Transaction data to the designated file using the unique transaction ID
  public void saveToTransFile(String fileName, String transId) throws IOException
	  {
		  /*
�	if any error found while loading file or parsing file data, throw InvalidLoadException
�	if transaction was not found, throw IllegalArgumentException
� 	create or overwrite transaction file
�	write out account and transaction using XML tags to the file
�	iterate through transactions
�	call toString() for each transaction object and write data to file
�	close file after saving
�	catch errors (e.g. issues creating file) and cleanup such as closing file
�	this method can only save a single transaction data so it should only call toString() for the one it will save
�	each transaction is saved in a different file*/



	int size = transObjects.size();
	for(int i=0; i< size; i++){
		if(transObjects.get(i).getTransId().equals(transId)){

			BufferedWriter br = null;
			try{
				FileOutputStream fis = new FileOutputStream(fileName);
				br = new BufferedWriter(new OutputStreamWriter(fis));
				String line = transObjects.get(i).toString();
				br.write(line);
			}catch (Exception e) {

				if (br != null)
					br.close();
				throw new InvalidLoadException("directory file not found");  // re-throw so that UI gets and takes appropriate action
			}
		}
	}
	throw new IllegalArgumentException("Transaction not found ");

}

  //load a Transaction object from the designated file using the unique transaction ID
  public void openFromTransFile(String fileName, String transId) throws IOException
	  {
		  /*
�	if any error found while loading file or parsing file data, throw InvalidLoadException
�	if account is inactive, throw IllegalStateException
�	if transaction was not found, throw IllegalArgumentException
�	use file name and transaction ID to open the existing transaction from file
�	after opening file, it needs to do something such as load the data and add to transactions list

		   */  BufferedReader br = null;
  	try {
		transObjects = new Vector<Transaction>(); // create a Vector object for transactions
		FileInputStream fis = new FileInputStream(fileName);
	  br = new BufferedReader(new InputStreamReader(fis));
	  String line = null;
	  // read first line and load account level attributes

	  line = br.readLine();
	  System.out.println(line);
	  System.out.println("Open file "+line.substring(line.indexOf("<accId>") + 7, line.indexOf("</accId>")));
	  
	  accId = line.substring(line.indexOf("<accId>") + 7, line.indexOf("</accId>"));
	  System.out.println("Open file "+accId);
	  owner = new Owner(line.substring(line.indexOf("<owner>") + 7, line.indexOf("</owner>")));
	  status = Boolean.parseBoolean(line.substring(line.indexOf("<status>") + 8, line.indexOf("</status>")));


	  // loop for the rest of the file loading all Transaction objects using appropriate constructors
	  while ((line = br.readLine()) != null)
	  {
		  if (line.substring(0, 10).equals("<purchase>"))   // found purchase transaction so call its constructor
		  {
			  // System.out.println(line.substring(0, 10).equals("<purchase>"));
			  Purchase pur = new Purchase(line);
			  if(pur.getTransId().equals(transId)){
				  System.out.println(pur.toString());
			  }
				// transObjects.add(pur);
		  }
		  else if (line.substring(0, 6).equals("<rent>")) // found rent transaction so call its constructor
		  {
			  Rent rnt = new Rent(line);
			  if(rnt.getTransId().equals(transId)){
				System.out.println(rnt.toString());
			}
			  // transObjects.add(rnt);
		  }
		  else if (line.substring(0, 8).equals("<travel>")) // found travel transaction so call its constructor
		  {
			  Travel trv = new Travel(line);
			  if(trv.getTransId().equals(transId)){
				System.out.println(trv.toString());
			}
			  // transObjects.add(trv);
		  }
	  }
	  br.close();
  } catch (Exception e) {  // caught an error so can close file
	  // log an error
	  System.out.println("Error in Account constructor:" + e.getLocalizedMessage());
	  e.printStackTrace();
	  if (br != null)
		  br.close();
	  throw e;  // re-throw so that UI gets and takes appropriate action
  }
}


  //it needs to get transaction id, find that object in its list, and then call the calculate method for that object
  public float calculatePrice(String transId)
	  {
		  /*
�	iterate through transactions
�	if transaction was not found, throw IllegalArgumentException
�	if transaction is found, it returns the transaction cost for a single transaction

		*/
		if(this.status == false){
			throw new IllegalStateException("Account is inactive");
		}
		int size = this.transObjects.size();  // get the number of transactions

		for (int i=0; i < size; i++) { // loop through transactions to find one matching accId

				if (transObjects.get(i).getTransId().equals(transId))
				{
					// already exists so throw exception
					return transObjects.get(i).calculatePrice();
				}
		}
		  return 0.0f;
	  }

  //this is a constructor method that is created for the class
  public Account(String accId, Owner owner)
	  {
	    	// validate that none of the parameter values are null or empty strings
	    	if (accId == null || owner ==null || accId.length() == 0)
	    		throw new IllegalArgumentException("Parameter values cannot be null or empty strings");

	    	transObjects = new Vector<Transaction>();  // create an empty Vector object for transObjects
	        //Transaction tra = transObject.clone(); // create clone to add so UI cannot change directly
	        //transObjects.add(tra);  // add transaction to the collection of transObjects
	        this.accId = accId;        // assign accId
	        this.owner = owner;    // assign owner object


	  }

  public Vector <Transaction> getTransObjects() // get method to return the value of the TransObjects attribute
	  {
	  		return transObjects; // get method returns the value of TransObjects on creation
	  }


  public String getAccId() // get method to return the value of the AccId attribute
	  {
	   return accId; //get method returns the value of AccId on creation
	  }


  public Owner getOwner() // get method to return the value of the Owner attribute
	  {
	   return owner; //get method returns the value of Owner on creation
	  }


  public boolean getStatus() // get method to return the value of the Status attribute
	  {
	   return status; // get method returns the value of Status on creation
	  }

  // set method to update the value of attribute owner
  public void setOwner(Owner owner)
	  {
	//should throw IllegalStateException if Account is already inactive
	  if (status == false)
		  throw new IllegalStateException("Account is already inactive");

	  this.owner = owner.clone(); // assign clone so caller cannot change directly
	  }

  // set method to update the value of attribute status
  public void setStatus(boolean status)

	  {  //validate that none of the parameter values are null or empty strings
	    	//if (status == null )
	    		//throw new IllegalArgumentException("Parameter value cannot be null or empty string");

	    	this.status = status;
	  }
	  /*
�	set method to update the value of attribute status
�	attribute value is changed through a set method instead of changing the attribute directly
�	reverse the value from active to inactive and inactive to active

	   */

	   int getSize(){
		   System.out.println("Get size : "+transObjects.size());
		   return transObjects.size();
	   }


  public Account(File accountFile) throws Exception
  {
	  BufferedReader br = null;
  	try {
  		// this.transObjects = new Vector<Transaction>(); // create a Vector object for transactions
		  size =0;

  		FileInputStream fis = new FileInputStream(accountFile);
        br = new BufferedReader(new InputStreamReader(fis));
        String line = null;
        // read first line and load account level attributes
        line = br.readLine();
        accId = line.substring(line.indexOf("<accId>") + 7, line.indexOf("</accId>"));
        owner = new Owner(line.substring(line.indexOf("<owner>") + 7, line.indexOf("</owner>")));
        status = Boolean.parseBoolean(line.substring(line.indexOf("<status>") + 8, line.indexOf("</status>")));


        // loop for the rest of the file loading all Transaction objects using appropriate constructors
	// for()
        while ((line = br.readLine()) != null)
        {
            if (line.substring(0, 10).equals("<purchase>"))   // found purchase transaction so call its constructor
            {
                Purchase pur = new Purchase(line);
				System.out.println();
               	this.transObjects.add(pur);
				

            }
            else if (line.substring(0, 6).equals("<rent>")) // found rent transaction so call its constructor
            {
                Rent rnt = new Rent(line);
				System.out.println();
                this.transObjects.add(rnt);
            }
            else if (line.substring(0, 8).equals("<travel>")) // found travel transaction so call its constructor
            {
            	Travel trv = new Travel(line);
            	this.transObjects.add(trv);
            }
        // }
	}
        br.close();
	} catch (Exception e) {  // caught an error so can close file
		// log an error
		System.out.println("Error in Account constructor:" + e.getLocalizedMessage());
		e.printStackTrace();
		if (br != null)
			br.close();
		throw e;  // re-throw so that UI gets and takes appropriate action
    }
  }
  
}
/*
 constructor to create Account object loading values from a file
 * create a Vector object for transactions
 * read first line and load account level attributes
 * loop for the rest of the file loading all Transaction objects using appropriate constructors
 * found purchase transaction so call its constructor
 * found rent transaction so call its constructor
 * found travel transaction so call its constructor
 * caught an error so can close file
 * re-throw so that UI gets and takes appropriate action
 */