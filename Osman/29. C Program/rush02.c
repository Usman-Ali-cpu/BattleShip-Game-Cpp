#include "ft_putbuf.h"

void print_char(int xi, int yi, int x, int y) //  function prints a character at specific position, having four parameters
{
	if (yi == y) // in verticle mode, check if value is same, points poiting to same area
	{
		ft_putbuf('\n'); // go to next line
		return;			 // terminate function by returning , rest of prgram would not run
	}
	--x;												   // whithout any condition, value of x would be decrement
	--y;												   //  value of x would be decrement
	if ((xi == 0 && yi == 0) || (xi == 0 && yi == y))	   //  check if it is start of line
		ft_putbuf('A');									   // put char 'A' to print
	else if ((xi == x && yi == 0) || (xi == x && yi == y)) // to check it is end of line
		ft_putbuf('C');									   // put char 'C' to print
	else if ((xi == 0 || xi == x || yi == 0 || yi == y))   // to check if it is ending or starting char
		ft_putbuf('B');									   // put char 'B' to print
	else												   // otherwise
		ft_putbuf(' ');									   // put char space  to print
}

void rush02(int y, int x) // function to print rush accord t given position
{
	int xi; //  declare xi for keeping point
	int yi; // declare yi

	ft_resetbuf(); // resetting value of char string
	xi = 0;		   // initializing point of x will be start from zero
	while (xi < x) // while vlaue of xi is less then x
	{
		yi = 0;			// initializing point of y will be start from zero, in each iteration
		while (yi <= y) // while value of yi is less then y
		{
			print_char(xi, yi, x, y); // print char according gievn points
			++yi;					  // increment value of yi
		}
		++xi; // increment vlaue of xi
	}
}