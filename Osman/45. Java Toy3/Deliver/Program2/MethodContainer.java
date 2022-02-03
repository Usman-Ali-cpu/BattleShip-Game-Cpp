
/**
 * Class: MethodContainer.java
 * 
 * @author
 * @version 1.0 Course : ITEC 2140 Fall 2021 Written: October 6, 2021 This class
 *          contains methods that each student should complete. This class will
 *          be called by Method Tester and its methods will solve the problems
 *          from MethodTester.
 * 
 */
public class MethodContainer {
	/**
	 * Method: add This method should add the two numbers and return the sum.
	 * 
	 * @param first
	 * @param second
	 * @return int containing the sum of the two arguments
	 */
	public int add(int first, int second) {
		return first + second;
	}

	/**
	 * Method: subtract This method should return the difference of two numbers.
	 * 
	 * @param first
	 * @param second
	 * @return int containing the difference of the two numbers
	 */
	public int subtract(int first, int second) {
		return first - second;
	}

	/**
	 * Method: firstWord This method should return the first word in a sentence. For
	 * example: "This is a sentence." should return This
	 * 
	 * @param sentence
	 * @return String containing the first word in the sentence
	 */
	public String firstWord(String sentence) {
		String[] str = sentence.split(" ");
		return str[0];
	}

	/**
	 * Method lastWord This method should return the last word in a sentence. For
	 * this problem assume the last character is always a punctuation mark For
	 * example: "This is a sentence." should return sentence
	 * 
	 * @param sentence
	 * @return
	 */
	public String lastWord(String sentence) {

		String[] str = sentence.split(" ");
		int len = str.length;
		String s = str[len - 1];
		String ss = "";
		for (int i = 0; i < s.length() - 1; i++) {
			ss += s.charAt(i);
		}
		return ss;

	}

	/*
	 * Method: buildString This method passed as arguments. The words should be
	 * separate by a single space.
	 * 
	 * For example: if first = "Fred" and second = "Flintstone" should return
	 * "Fred Flintstone"
	 * 
	 * @param first
	 * 
	 * @param second
	 * 
	 * @return the concatenation of the two Strings separated by a space
	 */
	public String buildString(String first, String second) {
		String str = first + " " + second;
		return str;
	}

	/**
	 * Method: repeatString returns the str repeated number times. Each str should
	 * be on its own line
	 * 
	 * @param str
	 * @param number
	 * @return a String containing the String passed in repeated number times.
	 */
	public String repeatString(String str, int number) {
		String s = "";
		for (int i = 0; i < number; i++) {
			s += str + "\n";
		}
		return s;

	}
}
