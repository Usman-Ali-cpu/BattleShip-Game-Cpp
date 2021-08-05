#include <stdio.h>
#include <string.h>
#include <math.h>
#define seam 0.25 // declare a global variable 

#pragma warning (disable:4996)



int numColors, side, length, width; // variavle for number of colors, sidelength, length and width
int whole; // while getting fraction, to store whole number
float triB, Bhyp, triC, Cbase, Chyp; // store altitude , base and hypothesis of triangles 
// where triB, triC are pieces, they are in the shapes of triAngles 
float  sqrA,sqrD;
// where sqrA , sqrD is also a piece, while it is in the shape of square 
float total; // total yard that is required 
float b; // store yard of fabrics
char choice; // choice while taking input Y/N
char color[3][20]; // array of colors
char input[20]; // store input from user 
int numSquare[2]; // array of Square 

void takeInput(); // prototype of function to take inputs from user 
float gettingTotal(); // prototype of function to get total
int check(int in); // prototype of function to check validation
void calculate(); // prototype of function to do calculation
void printResults(); // prototype of function to print result

// main function
int main()
{
	printf("Welcome to the Sawtooth Star Quilt Calculator.\n"); // wellcome message 
	do
	{
		takeInput(); // call function to take input 
		calculate(); // cal function to calculate yard and measurement of fabric
		printResults(); // call function to print all results 

		printf("Would you like to calculate another quilt? (Y/N)\n");
		scanf(" %c", &choice); // take choice to coutinue or not 
	} while (choice == 'y' || choice == 'Y');
	printf("Thank you for using the quilt calculator.Exiting.\n"); // Good bye message 

	return 0;
}
// end main



int check(int input)
{
	if (input <= 0)
		return 1; // return 1 if input is invlaid 
	return 0; // if valid return 0
}



void takeInput(){
	printf("\nPlease enter the finished side length in inches of one quilt square.\n");
		scanf("%s", input); // take length of quilt of of one square 
		side = atof(input); // convert to float 
		while (check(side)) // validate it 
		{
			// if not valid input take input again
			printf("Invalid input");
			printf("\nPlease enter the finished side length in inches of one quilt square.\n");
			scanf("%s", input);
			side = atof(input); // convert to float 
		}

		printf("Please enter the finished dimensions in inches of one side of the quilt.\n");
		scanf("%d", &length);   // take length of one side of quilt  
		while (check(length)) // validate it 
		{
			// if not valid input take input again
			printf("Invalid input");
			printf("\nPlease enter the finished dimensions in inches of one side of the quilt.\n");
			scanf("%d", &length); // take input length untill not valid 
		}

		printf("Please enter the finished dimensions in inches of the other side of the quilt.\n");
		scanf("%d", &width);
		while (check(width)) // take input length untill not valid 
		{
			printf("Invalid input");
			printf("\nPlease enter the finished dimensions in inches of the other side of the quilt.\n");
			scanf("%d", &width); // take input length untill not valid 
		}

		printf("How many colors are you using? Enter 2 or 3\n");
		scanf("%d", &numColors); // input number of colors 
		while (numColors < 2 || numColors > 3) // take input length untill not valid 
		{
			printf("Invalid input.Enter 2 or 3.");
			printf("\nHow many colors are you using? Enter 2 or 3");
			scanf("%d", &numColors); // take input length untill not valid 
		}

		printf("Enter the name of the first color.\n");
		scanf("%s", color[0]); // Enter name of first color 
		printf("Enter the name of the second color.\n");
		scanf("%s", color[1]); // Enter name of second color 
		if (numColors == 3) // number of color enter is three
		{
			printf("Enter the name of the third color.\n");
			scanf("%s", color[2]);  // Enter name of third color 
		}
}
float gettingTotal()
{
	// return the total length of fabric 
	float total = (numSquare[0] * numSquare[1] * sqrA * sqrA);  // get area length of square 
	total += (numSquare[0] * numSquare[1] * triB * triB * 4); // get area length 
	total = total / 45;
	total = total / 36;
	return total; // return total 
}


void calculate(){
		numSquare[0] = length / side;
		numSquare[1] = width / side;

		sqrA = ((float)side / 2) + (seam * 2); // get length of side A 
		triB = ((float)side / 4) + (seam * 2)+ 0.354; // get length of side B
		Bhyp = sqrt(2 * pow(triB, 2))-0.01; // get length of hypothesis of B 
		triC = ((float)side / 4) + (seam * 2)+ (2 * 0.6)+ 0.394; // get length of side C
		Cbase = ((float)side / 4) + (seam * 2)+ (2 * 0.6)+ 0.394;// get length of base of C
		Chyp = sqrt(2 * pow(triC, 2)); // get length of hypothesis of C
		sqrD = ((float)side / 4) + (seam * 2); // get length of D 

		total = gettingTotal(); // get total length
		whole = (int)total; // get whole value to write in fraction 

		b = (length * width) - (side * side * numSquare[0] * numSquare[1]); // get length of border 
		b /= 45;
		b /= 36;
		b *= 8;
		b = ceil(b) + 1; // assign value if length of border in yard after ceiling 
}

void printResults(){
	// printing total squares quilt have 
	printf("Your quilt will be %d squares by %d squares.\n", numSquare[0], numSquare[1]);
	// printing border squares quilt have 
		printf("Your quilt will have a border of %.1f inches by %.1f inches.\n",
		(float)(length % side) / 2, (float)(width % side) / 2);
		// printing measurement of fabric 
		printf("Piece A will be %.2f inches by %.2f inches.\n", sqrA, sqrA); // printing length of sides of piece A which is square 
		printf("Piece B will be %.2f inches by %.2f inches by %.2f inches.\n", triB, triB, Bhyp); // printing length of sides of piece B which is in shape of triangle  
		printf("Piece C will be %.2f inches by %.2f inches by %.2f inches.\n", triC, Cbase, Chyp); // printing length of sides of piece C which is in shape of triangle
		printf("Piece D will be %.2f inches by %.2f inches.\n", sqrD, sqrD); // printing length of sides of piece D which is which is square

		if (numColors == 2) // check if number if colors is two
		{
			// printing required number of yard you need for each color
			printf("You will need %.0f %d/8 yards of %s.\n", total,whole, color[0]);
			printf("You will need %.0f %d/8 yards of %s.\n", total,whole,  color[1]);
		}
		else // if number of colors are three 
		{
			// printing required measurements in Yard you will need
			printf("You will need %d %.0f/8 yards of %s.\n", whole / 2, total / 2, color[0]);
			printf("You will need %d %.0f/8 yards of %s.\n", whole / 2, total / 2, color[1]);
			printf("You will need %d %.0f/8 yards of %s.\n", whole, total, color[2]);
		}
		// printing information of border fabric you will need
		printf("You will need %.0f/8 yards of Border Fabric.\n", b); 

}