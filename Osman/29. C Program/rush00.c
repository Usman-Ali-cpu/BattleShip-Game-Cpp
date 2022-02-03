#include "ft_putbuf.h" // including file to use ft_putbuf(char c) and ft_resetbuf(void);

static void ft_printline(char end, char middle, int slot) // function prints line, having three arguments char end will be at the start and end of line ,
														  //  while middle char will be in between two end char by keeping count of slot
{
	ft_putbuf(end);	 // adding end character at start for printing
	while (slot > 2) // lopp will be iterate while value of slot is greater than 2
	{
		ft_putbuf(middle); // keep adding middle char in loop,
		slot -= 1;		   // decrementing value of slot
	}
	if (slot == 2)		// to check if it is end of line
		ft_putbuf(end); // again at the End of line add End char
	ft_putbuf('\n');	// add endline to go to next line
}

void rush00(int x, int y) // function header having two parameters
{
	int slot;

	ft_resetbuf();		  // resetting, size of g_out_buf would be zero after this
	if (x <= 0 || y <= 0) // for negative values of x and y function would not be proceeds
		return;			  // terminate rush00
	slot = y;			  // take value of y in slot
	while (slot >= 1)	  // at start value of slot is y, this loop will run while value of slot is greater than or equal to 1
	{
		if (slot == y || slot == 1) // to check if this is start and End of slot
		{
			ft_printline('o', '-', x); // print value of x after two character 'o' and '-'
		}
		else
		{
			ft_printline('|', ' ', x); // otherwise if this not start and End then print veritcal line and space before x, to print pattern
		}
		slot -= 1; // decrement value of slot in each iteration
	}
	ft_putbuf('\0'); // add terminating char of string of char array
}