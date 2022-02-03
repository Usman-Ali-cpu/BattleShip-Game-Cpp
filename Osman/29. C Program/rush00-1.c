#include "rush00.h" // including header file to use ft_putchar(char c);

void print_char(int xi, int yi, int x, int y) //  function prints a character at specific position, having four parameters
{
	if (yi == y) // in verticle mode, check if value is same, points poiting to same area
	{
		ft_putchar('\n'); // go to next line
		return;			  // terminate function by returning , rest of prgram would not run
	}
	--x;												// whithout any condition, value of x would be decrement
	--y;												//  value of x would be decrement
	if ((xi == 0 && yi == 0) || (xi == 0 && yi == y) || // codition for checking which character to print
		(xi == x && yi == 0) || (xi == x && yi == y))	// it is check if point is at very start or very end of line then,
		ft_putchar('o');								// printing character 'o;
	else if (xi == 0 || xi == x)						// otherwise if point is at middle of start and End line them
		ft_putchar('-');								// prints '-'
	else if (yi == 0 || yi == y)						// to check if point is at middle lines then,
		ft_putchar('|');								// prints '|'
	else
		ft_putchar(' '); // otherwise print space
}

void rush(int y, int x) // accpet 2 arguments as parameter , both parameters are integer
{
	int xi; // define variable of type integer
	int yi; // define variable of type integer

	xi = 0;		   // assign vlaue zero as start
	while (xi < x) // while value of xi, which is zero at start, is less than passing vlaue x!
	{
		yi = 0;			// assign value zero as start tp yi on start of every inner loop
		while (yi <= y) // while value of yi, which is zero at start, is less than passing value y!
		{
			print_char(xi, yi, x, y); // calling function, to print pattern from specific postions and length
			++yi;					  //intrement vlaue yi by one
		}
		++xi; // prefix intrement vlaue yi by one
	}
}