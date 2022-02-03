#include <iostream>
using namespace std;
int totalnumber(int row, int column)
{
    return row * column;
}

void print_figure(int row, int column, int n)
{

    {
        int total = totalnumber(row, column);
        int count = 0;

        int start;
        int end = n / 2;
        if (n % 2 == 0)
        {
            start = n / 2;
        }
        else if (n % 2 == 1)
        {
            start = n - end;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (start > 0 || total - count == end)
                {
                    if (start > 0)
                    {
                        start--;
                    }
                    else
                    {
                        end--;
                    }
                    if (n != 0)
                        cout << ".";
                }
                else
                {
                    if (!totalnumber(row, column) <= n)
                        cout << "*";
                }
                count++;
            }
            cout << endl;
        }
    }
}
int main()
{
    int rows, columns;
    int stars_to_convert;
    cout << "Enter dimensions: ";
    cin >> rows >> columns;

    print_figure(rows, columns, 0);

    cout << "Enter number of stars to convert: ";
    cin >> stars_to_convert;

    print_figure(rows, columns, stars_to_convert);

    cout << "End of program.";
    return 0;
}