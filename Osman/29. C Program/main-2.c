#include "rush00.h"

int main(int argc, char **argv) // passing argument to run a program, these arguments would be pass from console
{
	if (argc != 3)							  // to check, if arguments are more that 2,
		return (-1);						  // returb -1
	rush(argv[1][0] - '0', argv[2][0] - '0'); // passing first and second values, after converting check to integer
	return (0);								  // return 0 to end execution
}