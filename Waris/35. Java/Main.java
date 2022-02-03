import java.io.*;
import java.util.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		if (args.length != 1) {
			System.out.println("Invalid number of arguments are given");
			System.exit(0);
		}
		String filename = args[0];
		filename = "file.txt";
		File file = new File(filename); // make file object
		if (!file.exists()) { // Check if file exists
			System.out.println("The file " + filename + " does not exist!"); // print message if file does not exists
			System.exit(1); // terminate the program
		}

		Stack<Character> braces = new Stack<>(); // making stack ,
		try (Scanner input = new Scanner(file);) { // Create an input stream for file
			// Continuously read chars from input
			while (input.hasNext()) { // go through all the lines of file
				String line = input.nextLine(); // take next line from file scanner
				for (int i = 0; i < line.length(); i++) { // go through all the characters of line
					char ch = line.charAt(i); // store character
					// Push symbols (, {, and [ on to the stack
					if (ch == '(' || ch == '{' || ch == '[') {
						braces.push(ch); // if, brace is open then push that character in braces stack
					} // Process stack
					else if (ch == ')' || ch == '}' || ch == ']') { // if, brace is closing
						process(braces, ch); // then process it
					}
				}
			}
		}

		System.out.println("The Java source-code " + (braces.isEmpty() ? "has" : "does not have") + " correct pairs.");
	}

	/** Method Matchs grouping symbols */
	private static void process(Stack<Character> braces, Character ch) {
		// Remove matching symbols from stack
		if ((braces.peek() == '(' && ch == ')') || (braces.peek() == '[' && ch == ']')
				|| (braces.peek() == '{' && ch == '}')) { // check if symbol exists ,
			braces.pop(); // remove from the stack braces
		} else if ((braces.peek() != '(' && ch == ')') || (braces.peek() != '[' && ch == ']')
				|| (braces.peek() != '{' && ch == '}')) {
			System.out.println("The Java source-code does not have" + " correct pairs."); // if pairs are equal, then
																							// print correct pair
																							// message
			System.exit(1); // end the program
		}
	}
}