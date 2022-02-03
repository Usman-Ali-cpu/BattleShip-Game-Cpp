#include <stdio.h>
#include "ft_rush.h"
#include "lib/lib_ft.h"

#define BUF 8 * 1024 * 1024

char *g_out_buf; // pointer to char to make array to give output to user
char g_prev_res;

void get_dimensions(char *c, int *cols, int *lines) // passing char pointer, pointing to array of char and number of column and lines
{
	int cur_line_cols; // declaring variable of type int for count number of lines

	cur_line_cols = 0; // initializing it with 0
	*lines = 0;		   // number of lines will be 0 at start
	*cols = 0;		   // number of column  will be 0 at start
	while (*c)		   // loop will be continue while
	{
		if (*c == '\n') // if find new line
		{
			if (cur_line_cols > *cols) // check if column has been read is greater than we get in argument
				*cols = cur_line_cols; // assign  read column values to argument cols
			cur_line_cols = 0;		   // start read cur_line_cols again with 0
			*lines = *lines + 1;	   // increment in the lines that has been read
		}
		else				 // otherwise
			++cur_line_cols; // increment number columns of that line
		++c;				 //go to next character
	}
}

void print_num(int num) // passing a number as an argument
{
	while (num) // loop will be continue while number is greater than 0
	{
		ft_putchar((num % 10) + '0'); // printing a reminder of  number
		num /= 10;					  // divide number by ten to remove last digit
	}
}

void print_result(const char *type, int cols, int lines) // print result of output, have 3 arguments, one pointer array,  number of columm and number of lines
{
	if (g_prev_res)		   // g_prev_res is not null or zero
		ft_putstr(" || "); // put string for printing
	ft_putchar('[');	   //put character for printing
	ft_putstr(type);	   // put passing string for output
	ft_putstr("] [");	   //put character for printing
	print_num(cols);	   // print number of columns
	ft_putstr("] [");	   //put string for printing
	print_num(lines);	   // print number of lines
	ft_putchar(']');	   //put character for printing
	g_prev_res = 1;		   // assing 1 to g_prev_res to reset
}

void check_options(char *in_buf, int cols, int lines)
{
	rush00(cols, lines);					  // calling rush00 passing two int for point dimension
	if (!(ft_strcmp(in_buf, g_out_buf)))	  // check if value gt from rush00 and g_out_buf is not same
		print_result("rush-00", cols, lines); // print result by calling function print result, passing number of lines and columns
	rush01(cols, lines);					  // calling rush01 passing two int for point dimension
	if (!(ft_strcmp(in_buf, g_out_buf)))	  // check if value gt from rush00 and g_out_buf is not same
		print_result("rush-01", cols, lines);
	rush02(cols, lines);					  // calling rush02 passing two int for point dimension
	if (!(ft_strcmp(in_buf, g_out_buf)))	  // check if value gt from rush00 and g_out_buf is not same
		print_result("rush-02", cols, lines); // print result by calling function print result, passing number of lines and columns
	rush03(cols, lines);					  // calling rush03 passing two int for point dimension
	if (!(ft_strcmp(in_buf, g_out_buf)))	  // check if value gt from rush00 and g_out_buf is not same
		print_result("rush-03", cols, lines); // print result by calling function print result, passing number of lines and columns
	rush04(cols, lines);					  // calling rush04 passing two int for point dimension
	if (!(ft_strcmp(in_buf, g_out_buf)))
		print_result("rush-04", cols, lines); // print result by calling function print result, passing number of lines and columns
}

int main(void)
{
	char *in_buf;	   // char pointer to point array of char, for taking input
	size_t bytes;	   // declaring size for string / char array
	size_t bytes_read; // for count of character has been read
	int lines;
	int cols;

	bytes = 0;		// initializing size of char array from 0
	bytes_read = 0; // counting of char that has been read starts with zero, because reading does not start yet
	g_prev_res = 0;
	in_buf = malloc(BUF);								 // memory allocation to pointer of size of BUF, it will be use for input
	g_out_buf = malloc(BUF);							 // memory allocation to pointer of size of BUF, it will be use for output purpose
	while ((bytes_read = read(0, in_buf + bytes, 1024))) // read input for user command
		bytes += bytes_read;							 // increment size of char pointer array by the char that has been read each time in a loop
	in_buf[bytes] = '\0';								 // for termination of char array by placing null character at the end
	if (bytes)											 // if have read something
	{
		get_dimensions(in_buf, &cols, &lines); // calling function to get dimensions
		check_options(in_buf, cols, lines);	   // calling function to check options
	}
	if (!g_prev_res)
		ft_putstr("aucune"); // put string at the end
	ft_putchar('\n');		 // put a new line char
	return (0);
}