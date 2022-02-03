import java.util.ArrayList;

public class Question4 {

	public static String getMostCommon(Object[] o) {
		String[] stringArray = Arrays.copyOf(arr, arr.length, String[].class);

		int occur = 0;
		int max = 0;
		String str = "";
		for (int i = 0; i < stringArray.length; i++) {
			String s = stringArray[i];
			for (int j = 0; j < stringArray.length; j++) {
				if (s.equalsIgnoreCase(stringArray[i])) {
					occur++;

				}
			}
			if (occur > max) {
				max = occur;
				str = s;
			}
			if (occur == max) {
				str = "it's a tie";
			}
			occur = 0;
		}
		return str;

	}

	public static ArrayList<Pair> findPairs(int[] array, int product) {
		int size = A.length;
		Pair<Integer, Integer> pair = new Pair(0, 0);
		for (int i = 0; i < (size - 1); i++) {
			for (int j = (i + 1); j < size; j++) {
				if (A[i] * A[j] == product) {
					pair = new Pair(A[i], A[j]);
				}
			}
		}
		return pair;
	}

	public static int[][] reverseArray(int[][] array, boolean b1, boolean b2) {
		int M = array.length;
		int N = array[0].length;
		if (b1 == true) {
			for (int i = 0; i < M; i++) {

				// Initialise start and end index
				int start = 0;
				int end = N - 1;

				// Till start < end, swap the element
				// at start and end index
				while (start < end) {

					// Swap the element
					int temp = array[i][start];
					array[i][start] = array[i][end];
					array[i][end] = temp;

					// Increment start and decrement
					// end for next pair of swapping
					start++;
					end--;
				}
			}
		}
		if(b2 == true){
			for (int i = 0; i < N; i++) {

				// Initialise start and end index
				int start = 0;
				int end = M - 1;

				// Till start < end, swap the element
				// at start and end index
				while (start < end) {

					// Swap the element
					int temp = array[i][start];
					array[i][start] = array[i][end];
					array[i][end] = temp;

					// Increment start and decrement
					// end for next pair of swapping
					start++;
					end--;
				}
			}
		}
		return array;

	}
}

class Pair {

	private int a, b;

	public Pair(int a, int b) {
		this.a = a;
		this.b = b;
	}

	public boolean equals(Object o) {
		if (o instanceof Pair) {
			return (((Pair) o).a == a && ((Pair) o).b == b) || (((Pair) o).a == b && ((Pair) o).b == a);
		} else {
			return false;
		}
	}

	public String toString() {
		return "(" + a + "," + b + ")";
	}
}
