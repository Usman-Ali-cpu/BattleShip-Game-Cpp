

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Vector;



public class Manager 
{
	
  private Vector <Account> accObjects; // save and manage multiple account objects
  //Relationship & Cardinality: Aggregation - 1 Manager class can contain none or more accounts; 0..* null or more objects in one Manager system    
  
  private String directory; //store the directory that UI will pass from where files will be loaded 

//add the account object to the list of accounts that manager is storing
  public void addNewAccount(Account account) 
  {
	  
		// validate the parameter
		if (account == null)
			throw new IllegalArgumentException("Passed value is null");
		
		// TODO: do not allow adding if past date
  	
		// check if already exists and throw exception if does not
		int size = accObjects.size();  // get the number of accounts
		
		for (int i=0; i < size; i++) { // loop through accounts to find one matching accId
  		
			if (accObjects.get(i).getAccId().equalsIgnoreCase(account.getAccId())) 
  			{
  			// already exists so throw exception
  				throw new DuplicateObjectException("Account already exists");
  
	  /*
	   * If the parameter is null, the method should throw IllegalArgumentException
	   * When creating an account, if it already exists in the system, throw DuplicateObjectException
	   * Validate that the account is not a duplicate and add to the vector
	   * Validate account parameter.
	   * Assign parameter to attribute.
	   * Once the object is added to the list of objects, a new account file should be created
	   */
    		}		
	  		Account acc = account.clone(); // create clone to add so UI cannot change directly
	  		accObjects.add(acc);  // add accounts to list/collection that Manager stores and manages
		}	
  }

//inactive existing account using the unique account ID
  public void inactivateExistingAccount(String accId) 
  {
	  /*
�	Validate that an account is existing using account ID
�	If the account was not found, throw IllegalArgumentException
�	Inactive account after finding the account is existing 

	   */
	int size = accObjects.size();  // get the number of accounts
		
		for (int i=0; i < size; i++) { // loop through accounts to find one matching accId
			
			if (accObjects.get(i).getAccId().equals(accId)) 
			{
				accObjects.get(i).setStatus(false);
				System.out.println("Account has been In-Activated Successfully");
				return;
    		}	
		
  	}
	throw new IllegalArgumentException("Account is not found ! ");
  }

//reactivate inactive account using the unique account ID
  public void reactivateInactiveAccount(String accId) 
  {
	  /*
	   * �	Validate that an account is inactive using account ID
�	If the account was not found, throw IllegalArgumentException
�	Reactive account after finding the account is currently inactive 

	   */
	int size = accObjects.size();  // get the number of accounts
	

	

		for (int i=0; i < size; i++) { // loop through accounts to find one matching accId
			if (accObjects.get(i).getAccId().equals(accId)) 
  			{
					  accObjects.get(i).setStatus(true);
					  System.out.println("Account has been Re-Activated Successfully");
					  return ;
    		}	
  		}
	throw new IllegalArgumentException("Account is not found ! ");

  }

//retrieve account using the unique account ID
  public Account retrieveAccount(String accId) 
  {
  
	  /*
�	Validate that an account is existing using account ID
�	This method will loop through the accounts vector and return the object that matches the parameter ID value
�	find the account object it should return account 
if it cannot find it then it should return null 

	   */
	  int size = accObjects.size();  // get the number of accounts
		
		for (int i=0; i < size; i++) { // loop through accounts to find one matching accId
  		
			if (accObjects.get(i).getAccId().equalsIgnoreCase(accId)) 
  			{
				return  accObjects.get(i);
    		}	
		
  		}
	  return null;
  }

  // save current Account data to the designated file using the unique account ID
public void saveToAccFile(String fileName, String accId) throws IOException 
{
	  /*
�	If any error found while loading file or parsing file data, throw InvalidLoadException 
�	If the account was not found, throw IllegalArgumentException 
�	After the data is updated based on the file name and account ID, save the account file
�	After account id is found based on the fileName, change/update the account data as needed

	   */
	int size = accObjects.size();  // get the number of accounts
		
	for (int i=0; i < size; i++) { // loop through accounts to find one matching accId
  		
			if (accObjects.get(i).getAccId().equalsIgnoreCase(accId)) 
  			{
				// Account acc = accObjects.get(i);
				BufferedWriter br = null;
				try{
					File file = new File(fileName);
					FileWriter fw = new FileWriter(file);
					br = new BufferedWriter(fw);
					String line = accObjects.get(i).toString();
					br.write(line);
				}catch (Exception e) {

					if (br != null)
						br.close();
					throw new InvalidLoadException("directory file not found");  // re-throw so that UI gets and takes appropriate action
				}
    		}	
  	}
}

  // load a Account object from the designated file using the unique account ID
  public void openFromFile(String fileName, String accId) 
  {


	File[] listOfFiles = new File(directory).listFiles(); //get all files in the directory
	  File[] translist = listOfFiles;
	  //validate that the directory exists and is a directory folder otherwise throw exception
	  if(listOfFiles == null)
		  throw new IllegalArgumentException("Directory does not exists or is not a directory folder: " + directory);
	  
	  for(File accountFile : listOfFiles) { //loop through all files, loop through list and for each file that matches the account filename
		  String accountFileName = accountFile.getName(); //get file name
		  
		  // account-id.txt
		  String fi = "account-"+accId;
		  if(accountFileName.startsWith(fi)) {  //only process files that start with "account-id-number.txt" string
			  try {
				  
				  Account acc = new Account(accountFile.getAbsolutePath());	       //Call addAccount passing Account object.
				System.out.print( "Account : \n" +acc.toString()+ "\n" );
				  String dir = "accounts\\"+acc.getAccId();
				  translist = new File(dir).listFiles();
				 

				  for(File transFile : translist) { //loop through all files, loop through list and for each file that matches the transaction filename
					  String transFileName = transFile.getName();
											  
					  // trans-id-acc-id.txt, file convention

					  if(transFileName.startsWith("trans-")){
						  // if(transFileName.contains("-acc-" + acc.getAccId() + ".txt")){
							  // String fileText = Files.readString(transFile.getAbsolutePath());
							  // Read transaction data into String line 
							  String line = new String(Files.readAllBytes(Paths.get(transFile.getAbsolutePath())));
							  // System.out.print(line);
							  
							  if (line.startsWith("<purchase>")) {
								  if(!line.endsWith("</purchase>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
								  
								  String transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>"));
								  String description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));
								  int numOfItems = Integer.parseInt(line.substring(line.indexOf("<numOfItems>") + 12, line.indexOf("</numOfItems>")));
								  float pricePerItem = Float.parseFloat(line.substring(line.indexOf("<pricePerItem>") + 14, line.indexOf("</pricePerItem>")));
								
								  Purchase trans = new Purchase(transId, description, numOfItems, pricePerItem);
								  // acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
								  System.out.println("Purchase: ");
								  System.out.println(trans.toString());
								  System.out.println();
							  }
							
							  else if (line.startsWith("<rent>")) 
							  { //String transId, String description, int numOfDays, float rentDailyRate
								  if(!line.endsWith("</rent>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
			
								  Rent trans = new Rent(line);

								  //Rent trans = new Rent(transId, description,numOfDays, rentDailyRate);
								  System.out.println("Rent: ");
								  System.out.println(trans.toString());
								  System.out.println();
								  // acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
							  }
							  else if (line.startsWith("<travel>")) 
							  {
								  if(!line.endsWith("</travel>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
								//   String transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>"));
								//   String description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));
								//   float travelCost = Float.parseFloat(line.substring(line.indexOf("<travelCost>") + 12, line.indexOf("</travelCost>")));
								Travel trans = new Travel(line);
								  // Travel trans = new Travel(transId, description,travelCost);
								  // acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
								  System.out.println("Travel ");
								  System.out.println(trans.toString());
								  System.out.println();
							  }
						  //}
					  }
				  }
				  accObjects.add(acc);
			  }
			  catch (Exception accException){
				  
			  }
		  }
	  }
	  /* 
	   * If any error found while loading file or parsing file data, throw InvalidLoadException 
	   * If the account was not found, throw IllegalArgumentException 
	   * it should call the Account constructor passing it the filename
	   * use parameters file name and account ID to open the existing account from file

	   */
}
 
 /* For Manager constructor
  * If storeToDirectory is null or blank throw IllegalArgumentException
	If storeToDirectory does not exist or is not a directory throw InvalidLoadException 
  initialize accObjects attribute empty list--
  Set directory storeToDirectory attribute 
  Get list of all files in parent directory 
  Loop through list and for each file that matches the account filename do the following: 
  Call the Account constructor, passing in the full path filename. 
  Call addAccount passing Account object. 
  Get sub folder for matching Account. 
  Get list of all files in Account's directory.  This will be the transaction data files. 
  Loop through list for all files that match transaction filename 
  Determine which transaction type the file holds 
  Read transaction data into String line 
  Call the appropriate Transaction constructor, passing in the String line       
  Call account.addTransaction. */
	
//this is a constructor method that is created for the class			    	  
  public Manager(String directory) throws RuntimeException, IOException{
	this.directory = directory;
	  accObjects = new Vector<Account>();  // create a Vector object for accObjects, initialize accObjects attribute empty list
	  File[] listOfFiles = new File(directory).listFiles(); //get all files in the directory
	  File[] translist = listOfFiles;
	  //validate that the directory exists and is a directory folder otherwise throw exception
	  if(listOfFiles == null)
		  throw new IllegalArgumentException("Directory does not exists or is not a directory folder: " + directory);
	  
	  for(File accountFile : listOfFiles) { //loop through all files, loop through list and for each file that matches the account filename
		  String accountFileName = accountFile.getName(); //get file name
		  
		  // account-id.txt
		  if(accountFileName.startsWith("account-")) {  //only process files that start with "account-id-number.txt" string
			  try {
				  
				  Account acc = new Account(accountFile.getAbsolutePath());	       //Call addAccount passing Account object.
				  String dir = "accounts\\"+acc.getAccId();
				  translist = new File(dir).listFiles();

				  for(File transFile : translist) { //loop through all files, loop through list and for each file that matches the transaction filename
					  String transFileName = transFile.getName();					  
					  // trans-id-acc-id.txt, file convention

					  if(transFileName.startsWith("trans-")){
						  // if(transFileName.contains("-acc-" + acc.getAccId() + ".txt")){
							  // String fileText = Files.readString(transFile.getAbsolutePath());
							  // Read transaction data into String line 
							  String line = new String(Files.readAllBytes(Paths.get(transFile.getAbsolutePath())));
							  
							  if (line.startsWith("<purchase>")) {
								  if(!line.endsWith("</purchase>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
								  
								  String transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>"));
								  String description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));
								  int numOfItems = Integer.parseInt(line.substring(line.indexOf("<numOfItems>") + 12, line.indexOf("</numOfItems>")));
								  float pricePerItem = Float.parseFloat(line.substring(line.indexOf("<pricePerItem>") + 14, line.indexOf("</pricePerItem>")));
				
								  Purchase trans = new Purchase(transId, description, numOfItems, pricePerItem);
								  acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
							  }
							
							  else if (line.startsWith("<rent>")) 
							  { //String transId, String description, int numOfDays, float rentDailyRate
								  if(!line.endsWith("</rent>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
								
								  Rent trans = new Rent(line);
								  acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
							  }
							  else if (line.startsWith("<travel>")) 
							  {
								  if(!line.endsWith("</travel>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
								//   String transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>"));
								//   String description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));
								//   float travelCost = Float.parseFloat(line.substring(line.indexOf("<travelCost>") + 12, line.indexOf("</travelCost>")));
								Travel trans = new Travel(line);
								  // Travel trans = new Travel(transId, description,travelCost);
								  acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
								
							  }
						  //}
					  }
				  }
				  accObjects.add(acc);
			  }
			  catch (Exception accException){
				  
			  }
		  }
	  }
	  // this.accObjects = accObjects;
  	}	     		    	

  

  public void loadFiles(String fileName, String accId) throws Exception 
  {
	  /*
�	If any error found while loading file or parsing file data, throw InvalidLoadException 
�	If the account was not found, throw IllegalArgumentException 
�	Loads each account file based on specific account ID which already contains the transaction within itself

	   */
	  File[] listOfFiles = new File(directory).listFiles();
	  for(File accountFile : listOfFiles) { //loop through all files, loop through list and for each file that matches the account filename
		String accountFileName = accountFile.getName(); //get file name
		
		// account-id.txt
		if(accountFileName.startsWith("account-")) {  //only process files that start with "account-id-number.txt" string
			try {
				
				Account acc = new Account(accountFile.getAbsolutePath());	       //Call addAccount passing Account object.
				if(acc.getAccId().equals(accId))
				{
					for(File transFile : listOfFiles) { //loop through all files, loop through list and for each file that matches the transaction filename
						String transFileName = transFile.getName();
													
						// trans-id-acc-id.txt, file convention
						if(transFileName.startsWith("trans-")){
							if(transFileName.contains("-acc-" + acc.getAccId() + ".txt")){
								// String fileText = Files.readString(transFile.getAbsolutePath());
								// Read transaction data into String line 
								String line = new String(Files.readAllBytes(Paths.get(transFile.getAbsolutePath())));
								if (line.startsWith("<purchase>")) {
									if(!line.endsWith("</purchase>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
									
									String transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>"));
									String description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));
									int numOfItems = Integer.parseInt(line.substring(line.indexOf("<numOfItems>") + 12, line.indexOf("</numOfItems>")));
									float pricePerItem = Float.parseFloat(line.substring(line.indexOf("<pricePerItem>") + 14, line.indexOf("</pricePerItem>")));
									
									Purchase trans = new Purchase(transId, description, numOfItems, pricePerItem);
									acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
								}
								else if (line.startsWith("<rent>")) 
								{ //String transId, String description, int numOfDays, float rentDailyRate
									if(!line.endsWith("</rent>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
									
									String transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>"));
									String description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));
									int numOfDays = Integer.parseInt(line.substring(line.indexOf("<numOfDays>") + 12, line.indexOf("</numOfDays>")));        		   
									float rentDailyRate = Float.parseFloat(line.substring(line.indexOf("<rentDailyRate>") + 15, line.indexOf("</rentDailyRate>")));
									
									Rent trans = new Rent(transId, description,numOfDays, rentDailyRate);
									acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
								}
								else if (line.startsWith("<travel>")) 
								{
									if(!line.endsWith("</travel>")) throw new IllegalArgumentException("File is incorrect or not a proper file");
									String transId = line.substring(line.indexOf("<transId>") + 9, line.indexOf("</transId>"));
									String description = line.substring(line.indexOf("<description>") + 13, line.indexOf("</description>"));
									float travelCost = Float.parseFloat(line.substring(line.indexOf("<travelCost>") + 12, line.indexOf("</travelCost>")));
									
									Travel trans = new Travel(transId, description,travelCost);
									acc.addTransactionToAccount(trans); //Call account.addTransactionToAccount.
								}
							}
						}
					}
				}
				accObjects.add(acc);
			}
			catch (Exception accException){
				
			}
		}
	}  
}

  
  public Vector <Account> getAccObjects() // get method to return the value of the AccObjects attribute
  {
 	   return accObjects; // get method returns the value of AccObjects on creation
  }

  
  public String getDirectory() // get method to return the value of the StoreToDirectory attribute
  {
	  return directory; //get method returns the value of StoreToDirectory 
  }
  

}