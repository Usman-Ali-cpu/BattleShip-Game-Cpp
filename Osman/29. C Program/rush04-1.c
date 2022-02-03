#include "ft_putbuf.h"

static void ft_printline(char beg, char end, char middle, int slot)
{
	ft_putbuf(beg);	 // putting begining char to a line
	while (slot > 2) // loop will be run while vlue of slot is greater than 2
	{
		ft_putbuf(middle); // keep putting middle character in string to printing
		slot = slot - 1;   // decrement value of slot
	}
	if (slot == 2) // check if value of slot is 2, check if it is end of line
	{
		ft_putbuf(end); // put ending character
	}
	ft_putbuf('\n'); // newline at the end of line
}

void rush04(int x, int y) // function to print rush according to given position
{
	int slot;

	ft_resetbuf();		  // resetting value of char string
	if (x <= 0 || y <= 0) // if value of x and y is negative or zero
		return;			  // returning from function,
	slot = y;			  // assign value of slot is equal to y
	while (slot >= 1)	  // loop will be run while value of slot is greater than eqaul to one
	{
		if (slot == y) // check if value of slot is y mean start
		{
			ft_printline('A', 'C', 'B', x); // print line starting with A and having B in middle and ends with C
		}
		else if (slot == 1) // check if value of slot is 1 which mean End of line
		{
			ft_printline('C', 'A', 'B', x); // print line starting with C and having B in middle and ends with A
		}
		else // otherwise
		{
			ft_printline('B', 'B', ' ', x); // print line starting with B and having space in middle and ends with B
		}
		slot -= 1; // decrement value of slot
	}
	ft_putbuf('\0'); // adding terminating character of string
}