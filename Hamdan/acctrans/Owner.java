

public class Owner {

	private String name; //owner's name

	private String mailingAddress; //owner's mailing address

	private String email; //owner's email address

	private String phoneNum; //owner's phone number
	  
	  //toString formats and returns object's data in XML format
	  public String toString() 
	  {
		 //for better tracking and visual, added XML tag for pseudo code for each attribute in a separate line)
		  /*return a string with tags and values for each attribute that has the following values and format:	 
		   *  return "<owner>" + "<name>" + name + "</name>" 
		      + "<mailingAddress>" + mailingAddress + "</mailingAddress>" 
		      + "<email>" + email + "</email>" 
		      + "<phoneNum>" + phoneNum + "</phoneNum>" + "</owner>"; 
		   */
		  return "<owner>" + "<name>" + name + "</name>" 
		  + "<mailingAddress>" + mailingAddress + "</mailingAddress>" 
		  + "<email>" + email + "</email>" 
		  + "<phoneNum>" + phoneNum + "</phoneNum>" + "</owner>";
	  }
	  
	  //create and return a copy of the object
	  public Owner clone() 
	  {
		  /*
		   *	return new Owner(this.name, this.mailingAddress, this.email, this.phoneNum);
		   */
		  return new Owner(this.name, this.mailingAddress, this.email, this.phoneNum);
	  }

	  //update owner information 
	  public void updateOwnerInfo(String name, String mailingAddress, String email, String phoneNum) 
	  {
		  /* 
�	validate parameters
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw llegalArgumentException
�	assign all the parameters' values to attributes
�	update owner information
		   */  
		this.name = name;
		this.email = email;
		this.mailingAddress = mailingAddress;
		this.phoneNum = phoneNum;
	  }

	//this is a constructor that is created to assign values to a new Owner object
	  public Owner(String name, String mailingAddress, String email, String phoneNum) 
	  {
		//  validate that all the parameters have values, if not, then throw IllegalArgumentException for null or empty strings
		  if (name == null || mailingAddress == null || email== null || phoneNum == null 
			||name.length() == 0 || mailingAddress.length() == 0 || email.length() == 0 || phoneNum.length() == 0)
				throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
		  
		  this.name = name;
		  this.mailingAddress = mailingAddress;
		  this.email = email;
		  this.phoneNum = phoneNum;
		  
		  /* 
�	validate parameters 
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw IllegalArgumentException
�	assign all the parameters' values to attributes

		   */
	  }
	  
	  
	  public String getName() // get method to return the value of the Name attribute
		  {
		  	return name; // get method returns the value of Name on creation		   
		  }

	  	 // set method to update the value of attribute Name
		  public void setName(String name) 
		  {  //validate that none of the parameter values are null or empty strings
		    	if (name ==null || name.length() == 0)
		    		throw new IllegalArgumentException("Parameter value cannot be null or empty string");
				
		    	this.name = name;
		  }

		  
		  public String getMailingAddress() // get method to return the value of the MailingAddress attribute
		  {
			  	return mailingAddress; // get method returns the value of MailingAddress on creation
		  }

		  // set method to update the value of attribute MailingAddress
		  public void setMailingAddress(String mailingAddress)
		  {    	// validate that none of the parameter values are null or empty strings
		    	if (mailingAddress ==null || mailingAddress.length() == 0)
		    		throw new IllegalArgumentException("Parameter value cannot be null or empty string");
				
		    	this.mailingAddress = mailingAddress;
		  }

		  // get method to return the value of the Email attribute
		  public String getEmail() 
		  {
			  // get method returns the value of Email on creation
				return email;
		  }

		  // set method to update the value of attribute Email
		  public void setEmail(String email) 
		  {
			   	// validate that none of the parameter values are null or empty strings
		    	if (email ==null || email.length() == 0)
		    		throw new IllegalArgumentException("Parameter value cannot be null or empty string");
				
		    	this.email = email;
		  }

		  
		  public String getPhoneNum() // get method to return the value of the PhoneNum attribute
		  {
			  return phoneNum; //get method returns the value of PhoneNum on creation			   
		  }

		  // set method to update the value of attribute PhoneNum
		  public void setPhoneNum(String phoneNum) 
		  {
			// validate that parameter value is not null or empty string
		    	if (phoneNum ==null || phoneNum.length() == 0)
		    		throw new IllegalArgumentException("Parameter value cannot be null or empty string");
				
		    	this.phoneNum = phoneNum;

		  }
		  
		  //create and return a copy of the object
		  public Owner clone(String line)
		  	{
			  /*  
�	the code processes a file 
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw llegalArgumentException
�	it loads the data from file by reading a line and calls the corresponding constructor to parse data and assign attribute 
�	create and return a copy of the object 

			   */
			  return null;
			}

			  public Owner(String line) 
			  {
				// method to parse out and assign to attributes the values from toString() formatted line	  
				  name = line.substring(line.indexOf("<name>") + 6, line.indexOf("</name>"));
				  mailingAddress = line.substring(line.indexOf("<mailingAddress>") + 16, line.indexOf("</mailingAddress>"));
				  email = line.substring(line.indexOf("<email>") + 7, line.indexOf("</email>"));
				  phoneNum = line.substring(line.indexOf("<phoneNum>") + 10, line.indexOf("</phoneNum>"));
				  
				// validate that parameter value is not null or empty string
				     if (name == null || mailingAddress == null || email == null || phoneNum == null
				     		|| name.length() == 0 || mailingAddress.length() == 0 || email.length() == 0 || phoneNum.length() == 0)
				 			throw new IllegalArgumentException("Parameter values cannot be null or empty strings");
		  
				  /*  (String name, String mailingAddress, String email, String phoneNum) 
�	the code processes a file 
�	if any error found while loading file or parsing file data, throw InvalidLoadException 
�	validate that the data is parsing properly, if not, throw IllegalArgumentException
�	it should be parsing the string it gets in parameter for the values and calls the corresponding constructor to parse data and assign attribute 

				   */
			  }


	}