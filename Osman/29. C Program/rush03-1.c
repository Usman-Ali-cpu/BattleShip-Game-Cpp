#include "rush00.h"

void print_char(int xi, int yi, int x, int y) //  function prints a character at specific position, having four parameters
{
	if (yi == y) // in verticle mode, check if value is same, points poiting to same area
	{
		ft_putchar('\n'); // goto next new line
		return;			  // terminate function
	}
	--x;												   // decrement value of x
	--y;												   // decrement  value of y
	if ((xi == 0 && yi == 0) || (xi == x && yi == 0))	   //  check if it is start of line
		ft_putchar('A');								   // put char 'A' to print
	else if ((xi == 0 && yi == y) || (xi == x && yi == y)) // to check if middle of line
		ft_putchar('C');								   // put char 'C' to print
	else if (xi == 0 || yi == 0 || xi == x || yi == y)	   // to check if it is ending or starting char
		ft_putchar('B');								   // put char 'B' to print
	else												   // otherwise
		ft_putchar(' ');								   // put char space  to print
}

void rush(int y, int x) // function to print rush accord t given position
{
	int xi; //  declare xi for keeping point
	int yi; // declare yi

	xi = 0;		   // initializing point of x will be start from zero
	while (xi < x) // while vlaue of xi is less then x
	{
		yi = 0;			// initializing point of y will be start from zero, in each iteration
		while (yi <= y) // while value of yi is less then y
		{
			print_char(xi, yi, x, y); // print char according gievn points
			++yi;					  // increment value of yi
		}
		++xi; // increment value of xi
	}
}