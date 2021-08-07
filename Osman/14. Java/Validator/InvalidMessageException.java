
//unchecked user defined exception 
public class InvalidMessageException extends Exception {
	private String errorData; // data for the error or the reason of error

	public String toString() {
		// generate and return specific message that is meaningful to the error
		if (errorData == null) // first constructor was called
			return this.getClass().getSimpleName() + ": Try Again with valid message";

		else // second constructor was called
			return this.getClass().getSimpleName() + ": Try Again with valid message ";

	}

	public InvalidMessageException(String m) {
		/*
		 * call super passing message:
		 * "Error found while loading the transaction number. TransactionID: " + transId
		 * assign parameter to attribute transId
		 */
		super("InvalidMessageExceptin: " + m);
		return;
	}

	public InvalidMessageException() {
		// call super passing message: Transaction cannot be removed in AccountID: " +
		// accId + "Transaction " + transId + " reason: " + errorData
		super("InvalidMessageExceptin: Try again with valid message");
		return;
	}
}