#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Displayable
{
public:
    // 1 - 2 Marks
    // Create a pure virtual function for displaying Displayable Objects
    virtual void display() = 0;
};
// 2 - 3 marks
// Overload operator<< to be able to display all Displayable objects
// using ostream and operator<<

ostream &operator<<(ostream &out, const Displayable &dis)
{
    out << dis;
    return out;
}
class Array : public Displayable
{
    int *m_elements{};
    unsigned int m_size{};

private:
    void allocateMemory(int arr[], int size)
    {
        if (arr == nullptr)
        {
            delete[] m_elements;
            m_size = 0;
        }
        else
        {
            m_size = size;
            m_elements = new int[m_size];
            for (int i = 0; i < m_size; i++)
            {
                m_elements[i] = arr[i];
            }
        }
    }
    /*
     * 3 - 7 Marks
     *  create a private function to allocate memory in m_elements and
     *  copy an array of values into the newly allocated memory. This
     *  function should also receive the size of the incoming array.
     *  If the incoming array is nullptr, this function just deletes
     *  the m_elements and sets it to null (safe empty state)
     *  reuse this function in future DMA logics
     */

public:
    unsigned int size() const
    {
        return m_size;
    }
    /* 4 - 1 Mark
     * Create a default constructor so an empty Array can be created.
     */
    Array()
    {
        m_size = 0;
        m_elements = new int[m_size];
    }

    /* 5 - 2 marks
     * Create a two-argument constructor that receives the same arguments
     * as the function created in question 3 and saves the array in the
     * m_elements dynamically. If the array argument is nullptr the Array will
     * be in a safe empty state.
     */
    Array(int arr[], int size)
    {
        if (arr == nullptr)
        {
            delete[] m_elements;
            m_size = 0;
        }
        else
        {
            m_size = size;
            m_elements = new int[m_size];
            for (int i = 0; i < m_size; i++)
            {
                m_elements[i] = arr[i];
            }
        }
    }

    /*
     * 6 - 8 Marks
     * Implement the Rule of three
     */

    /* 7 - 4 Marks
     * Implement the index operator to return the reference of the element
     * at the incoming index. Use modulus operator to loop back to the
     * beginning of the index if larger than the size of the Array. Overload
     * the index operator in why that it will be available in both constant
     * and not constant Arrays. (hint: two overloads)
     */
    int &operator[](int i)
    {
        if (i >= m_size)
        {
            m_elements[0];
        }
        return m_elements[i];
    }
    int &operator[](int i) const
    {
        if (i >= m_size)
        {
            m_elements[0];
        }
        return m_elements[i];
    }

    /* 8 - 5 Marks
     * Override the pure virtual display function to display the values of
     * the Array in separate lines with row numbers that are five digits
     * padded at left with zeros as follows:
     * 00000 - 10
     * 00001 - 20
     * 00002 - 30
     */
    void display()
    {
        for (int i = 0; i < m_size; i++)
        {
            cout << "0000" << i << " - " << m_elements[i] << endl;
        }
    }
};
/* 9 - 14 marks
 * Create a class called List that is an Array with a dynamic title.
 * Array can be created empty by default or with three arguments:
 * title, an array of values and size of the array.
 * List complies with rules of three for safe copying and
 * assignment.
 * It is printed using its Displayable capabilities as follows:
 * Title goes here
 * --------------------
 * 00000 - 10
 * 00001 - 20
 * 00002 - 30
 * 00003 - 40
 * If empty, nothing is printed.
 *
 * Also if casted to a "const char *" it will return the title.
 */

class List : public Array
{
private:
    string title;

public:
    List(string title, int arr[], int size) : Array(arr, size)
    {
        this->title = title;
    }
    List()
    {
        this->title = "default";
        Array();
    }
    string getTitle()
    {
        return title;
    }
};

ostream &operator<<(ostream &out, const List &dis)
{
    out << ;
    return out;
}
List getFiveTens()
{
    int arr[] = {10, 20, 30, 40, 50};
    List tens("Five Tens", arr, 5);
    return tens;
}

void prnCSV(const List &tm)
{
    if (!tm.size() == 0)
    {
        out << (const char *)(tm) << ": ";
        for (unsigned int i = 0; i < tm.size(); i++)
        {
            cout << "0000" << i << " - " << tm[i] << endl;
        }
        cout << endl;
    }
}

int main()
{
    List theMarks;
    theMarks = getFiveTens();
    theMarks.display();
    cout << theMarks << endl;
    ofstream("data.txt") << theMarks << endl;
    prnCSV(theMarks);
    return 0;
}