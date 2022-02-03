#include <iostream>
using namespace std;
#ifndef ASCIIART_H
#define ASCIIART_H
using namespace std;

class AsciiArt
{
    friend ostream &operator<<(ostream &out, const AsciiArt &a); // Call a.draw(). T
private:
    int numRows, numCols;
    char **grid; // A 2D array to hold the characters
    // optional helper functions
    static char **makeGrid(int numRows, int numCols);                           // dynamically allocate a 2D array
    static void deleteGrid(char **g, int numRows);                              // delete g[0] etc. and delete g.
    static void copyGrid(char **dest, char **source, int numRows, int numCols); // copy data
public:
    AsciiArt(int numR, int numC); // Set numRows to max(1,numR), numCols to max(1,numC)
    AsciiArt(const AsciiArt &other);
    AsciiArt &operator=(const AsciiArt &other); // copy constructor
    AsciiArt &operator*=(int mult);             // enlarge, e.g. mult=2 --> "double" each row & column (See output)
    AsciiArt &operator/=(int div);              // reduce e.g. div=2 --> keep every other row & columm. (See output)
    AsciiArt operator*(int mult);               // Call *=
    AsciiArt operator/(int div);                // Call /=
    ~AsciiArt();                                // destructor (Call deleteGrid if you implemented it.)
    // return true if the *this and other have the same dimensions and the same characters
    // return false otherwise
    bool operator==(const AsciiArt &other);
    bool operator!=(const AsciiArt &other); // call operator==
    // Set grid[row][col] to c or do nothing if row or col is out of bounds.
    void setChar(int row, int col, char c);
    // return grid[row][col] or return '\0' if row or col is out of bounds.
    char getChar(int row, int col) const;
    // draw the picture to out. See sample output as a guide.
    void draw(std::ostream &out) const;
    // If row or startCol is out-of-bounds then return without copying anything.
    // Otherwise, copy s[0] into grid[row][startCol], s[1] into grid[row][startCol+1] etc.
    // If s is "too long to fit", stop copying beyond grid[row][numCols-1].
    void setRow(int row, int startCol, const char s[]);
    // return numRows
    int getNumRows() const;
    // return numCols
    int getNumCols() const;

    AsciiArt &flip();
};
#endif

AsciiArt AsciiArt::operator/(int mult)
{
    return *this /= mult;
}
AsciiArt AsciiArt::operator*(int mult)
{

    return *this *= mult;
}
AsciiArt &AsciiArt::operator/=(int div)
{
    return *this;
}
AsciiArt &AsciiArt::operator*=(int mult)
{
    int newrow = numRows * mult;
    int newcol = numCols * mult;
    char **a = new char *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        a[i] = new char[newcol];
    }

    for (int i = 0; i < this->numRows; i++)
    {
        //  k = 0;
        for (int j = 0; j < newcol; j++)
        {
            a[i][j] = '8';
        }
        cout << endl;
    }

    int k = 0;

    for (int i = 0; i < this->numRows; i++)
    {
        //  k = 0;
        for (int j = 0; j < numCols; j++)
        {
            for (int b = 0; b < mult; b++)
            {
                a[i][k] = grid[i][j];
                k++;
            }
        }
        k = 0;
    }

    // char **b = new char *[ne];
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < newcol; j++)
        {

            cout << a[i][j];
        }
        cout << endl;
    }

    return *this;
}

ostream &operator<<(ostream &out, const AsciiArt &a)
{
    a.draw(out);
    return out;
}

void AsciiArt::draw(std::ostream &out) const
{

    for (int i = 0; i < this->numRows; i++)
    {
        for (int j = 0; j < this->numCols; j++)
        {
            out << this->grid[i][j];
        }
        out << endl;
    }
}

void AsciiArt::setChar(int row, int col, char c)
{
    if (row < this->numRows && col < this->numCols)
    {
        this->grid[row][col] = c;
    }
}
char AsciiArt::getChar(int row, int col) const
{
    if (row < this->numRows && col < this->numCols)
    {
        return this->grid[row][col];
    }
    return '\0';
}
void AsciiArt::setRow(int row, int startCol, const char s[])
{

    if (row > this->numRows || row < 0 || startCol > this->numCols || startCol < 0)
    {
        return;
    }
    else
    {
        int j = 0;
        for (int i = startCol; i < numCols; i++)
        {
            if (s[j] == '\0')
            {
                if (grid[row][i] == '*')
                {
                    this->grid[row][i] = ' ';
                }
                j--;
            }
            else
            {
                this->grid[row][i] = s[j];
            }
            j++;
        }
    }
}

int AsciiArt::getNumRows() const
{
    return this->numRows;
}
// return numCols
int AsciiArt::getNumCols() const
{
    return this->numCols;
}
AsciiArt &AsciiArt::flip()
{
    int tr = numRows;
    int tc = numCols;
    int i, j;
    char **a = new char *[numCols];
    for (int i = 0; i < numCols; i++)
    {
        a[i] = new char[numRows];
    }
    for (i = 0; i < this->numCols; i++)
        for (j = 0; j < this->numRows; j++)
            a[i][j] = grid[j][i];

    deleteGrid(this->grid, tr);
    this->numRows = tc;
    this->numCols = tr;
    this->grid = new char *[tc];
    for (int i = 0; i < tc; i++)
    {
        grid[i] = new char[tr];
    }
    for (int i = 0; i < this->numRows; i++)
    {
        for (int j = 0; j < this->numCols; j++)
        {
            this->grid[i][j] = a[i][j];
        }
    }
    deleteGrid(a, tc);
    return *this;
}

char **AsciiArt::makeGrid(int numRows, int numCols)
{
    char **a = new char *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        a[i] = new char[numCols];
    }
    return a;
}

void AsciiArt::deleteGrid(char **g, int numRows)
{

    for (int i = 0; i < numRows; i++)
    {
        delete[] g[i];
    }
    delete[] g;
}

void AsciiArt::copyGrid(char **dest, char **source, int numRows, int numCols)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}
AsciiArt::AsciiArt(int numR, int numC)
{
    this->numCols = numC;
    this->numRows = numR;
    this->grid = new char *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        this->grid[i] = new char[numCols];
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            this->grid[i][j] = ' ';
        }
    }
}
AsciiArt &AsciiArt::operator=(const AsciiArt &other)
{
    this->numCols = other.numCols;
    this->numRows = other.numRows;
    this->grid = new char *[numRows];
    for (int i = 0; i < numRows; i++)
    {

        this->grid[i] = new char[this->numCols];
        for (int j = 0; j < numCols; j++)
        {

            this->grid[i][j] = other.grid[i][j];
        }
    }

    return *this;
}

AsciiArt::~AsciiArt()
{
    for (int i = 0; i < this->numRows; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
    this->numCols = 0;
    this->numRows = 0;
}

bool AsciiArt::operator==(const AsciiArt &other)
{
    if (this->numCols != other.numCols)
    {
        return false;
    }
    else if (this->numRows != other.numRows)
    {
        return false;
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (this->grid[i][j] != other.grid[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

AsciiArt::AsciiArt(const AsciiArt &other)
{
    this->numCols = other.numCols;
    this->numRows = other.numRows;
    this->grid = new char *[numRows];
    for (int i = 0; i < numRows; i++)
    {

        this->grid[i] = new char[this->numCols];
        for (int j = 0; j < numCols; j++)
        {

            this->grid[i][j] = other.grid[i][j];
        }
    }
}
bool AsciiArt::operator!=(const AsciiArt &other)
{
    if (*this == other)
    {
        return false;
    }
    return true;
}

int main()
{
    AsciiArt pic(14, 24);
    pic.setRow(0, 1, "HERE IS A PICTURE!");
    char s[] = "************";

    for (int i = 1; i < pic.getNumRows() - 1; i++)
        pic.setRow(i, pic.getNumCols() - i, s);

    pic.setRow(pic.getNumRows() - 5, 0, "ZZZZZZZZZZZZZZZZZZZZZZZZ");
    pic.setRow(pic.getNumRows() - 4, 0, " ZZZZZZZZZZZZZZZZZZZZ ");
    pic.setRow(pic.getNumRows() - 3, 0, "  ZZZZZZZZZZZZZZ ");
    pic.setRow(pic.getNumRows() - 2, 0, "    ZZZZZZ ");
    pic.setRow(pic.getNumRows() - 1, 0, "     ZZ ");
    pic.draw(cout);
    AsciiArt pic2 = pic;
    cout << pic2.flip() << endl
         << endl;
    pic2.draw(cout);
    cout << (pic2 *= 2) << endl;
    cout << pic2.flip() << endl
         << endl;
    cout << (pic2 /= 2) << endl;
    cout << ((pic2 *= 3).flip() *= 2) << endl;
    cout << pic2.flip() << endl;
    cout << (pic2 /= 3) << endl;
    cout << (pic2 /= 2) << endl;
    cout << (pic2 /= 2) << endl;
    cout << (pic2 *= 2) << endl;
    return 0;
}
