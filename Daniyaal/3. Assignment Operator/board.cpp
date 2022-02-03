#include <iostream>
using namespace std;

void print(char squares[][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << squares[i][j] << " ";
        }
        cout << endl;
    }
}
int getValue(char squares[][6]);
int main()
{
    char board[6][6] = {{
                            'O',
                            'X',
                            'X',
                            'X',
                            'O',
                            'X',
                        },
                        {
                            'X',
                            'O',
                            'X',
                            'X',
                            'X',
                            'O',
                        },
                        {
                            'O',
                            'O',
                            'O',
                            'X',
                            'O',
                            'X',
                        },
                        {
                            'X',
                            'X',
                            'X',
                            'O',
                            'O',
                            'O',
                        },
                        {
                            'X',
                            'X',
                            'X',
                            'O',
                            'O',
                            'O',
                        },
                        {
                            'X',
                            'X',
                            'X',
                            'O',
                            'X',
                            'X',
                        }};
    print(board);
    cout << getValue(board);

    return 0;
}
/* ************************** CODE TO SUBMIT *************************/
int getValue(char squares[][6])
{

    // any of the rows is same
    for (int i = 0; i <= 5; i++)
    {
        if (squares[i][0] == squares[i][1] && squares[i][1] == squares[i][2] && squares[i][2] == squares[i][3] && squares[i][3] == squares[i][4] && squares[i][4] == squares[i][5] && squares[i][5] == 'X')
        {

            return 1;
        }
        if (squares[i][0] == squares[i][1] && squares[i][1] == squares[i][2] && squares[i][2] == squares[i][3] && squares[i][3] == squares[i][4] && squares[i][4] == squares[i][5] && squares[i][5] == 'O')
        {

            return -1;
        }
    }

    // any of the columns is same
    for (int i = 0; i <= 5; i++)
    {
        if (squares[0][i] == squares[1][i] && squares[1][i] == squares[2][i] && squares[2][i] == squares[3][i] && squares[3][i] == squares[4][i] && squares[4][i] == squares[5][i] && squares[5][i] == 'X')
        {

            return 1;
        }
        if (squares[0][i] == squares[1][i] && squares[1][i] == squares[2][i] && squares[2][i] == squares[3][i] && squares[3][i] == squares[4][i] && squares[4][i] == squares[5][i] && squares[5][i] == 'O')
        {

            return -1;
        }
    }

    // 1st diagonal is same
    if (squares[0][0] == squares[1][1] && squares[1][1] == squares[2][2] && squares[2][2] == squares[3][3] && squares[3][3] == squares[4][4] && squares[4][4] == squares[5][5] && squares[5][5] == 'X')
    {

        return 1;
    }
    if (squares[0][0] == squares[1][1] && squares[1][1] == squares[2][2] && squares[2][2] == squares[3][3] && squares[3][3] == squares[4][4] && squares[4][4] == squares[5][5] && squares[5][5] == 'O')
    {

        return -1;
    }

    // 2nd diagonal is same
    if (squares[0][5] == squares[1][4] && squares[1][4] == squares[2][3] && squares[2][3] == squares[3][2] && squares[3][2] == squares[4][1] && squares[4][1] == squares[5][0] && squares[5][0] == 'X')
    {

        return 1;
    }
    if (squares[0][5] == squares[1][4] && squares[1][4] == squares[2][3] && squares[2][3] == squares[3][2] && squares[3][2] == squares[4][1] && squares[4][1] == squares[5][0] && squares[5][0] == 'O')
    {

        return -1;
    }

    return 0;
}
/**************** END CODE ********************************/