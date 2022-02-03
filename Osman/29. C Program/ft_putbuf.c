#include <unistd.h>

extern char *g_out_buf; // defining extern of char,
// which means that char * has been created with declaration, no memory allocation occurs.
size_t g_buf_pos; // size of char pointer, for array or string

void ft_putbuf(char c) // passing charactor to function to add in pointer array
{
	g_out_buf[g_buf_pos++] = c; // first assign or store, passing character to current size and then increament for next.
}

void ft_resetbuf(void) // a function passing argument void
{
	g_buf_pos = 0; // it reset the size of char array g_out_buf
}