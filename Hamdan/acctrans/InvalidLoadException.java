
//unchecked user defined exception 

public class InvalidLoadException extends RuntimeException 

{
	  private String fileName; //name of file from the directory

	  private String errorData; //data for the error or the reason of error 
	  
	  private String directory; //directory 

	  public String toString() 
	  
	  {
		  // generate and return specific message that is meaningful to the error based on which constructor was called 
		
		  if (directory == null)  // call second constructor     
			  return this.getClass().getSimpleName() + ": Error found while loading the file. FileName: " + fileName + " reason: " + errorData; 
			
		  else // call first constructor  
			     return this.getClass().getSimpleName() + "Directory: " + directory + " does not exist or not a directory";
	  }

	   public InvalidLoadException(String directory) //, String errorData) 
	  
	  {
		 //call super passing message: "Directory: " + directory + " does not exist or not a directory"
		   super("Error found while loading the directory: " + directory); // + " reason: " + errorData);
		   
		   //assign parameter to attribute directory
		   this.directory=directory;
		   
	  }

	   public InvalidLoadException(String  fileName, String errorData) //String directory,
	  
	  {

		   //call super passing message: : ": Error found while loading the file. FileName: " + fileName + " reason: " + errorData
		   super("Error found while loading the file. File name:" + fileName + " reason: " + errorData);		   
		   
		  // assign parameter to attribute fileName and errorData
		   this.fileName=fileName;
		   this.errorData=errorData;
	  }

	  
	}

