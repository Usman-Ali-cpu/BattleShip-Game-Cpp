#include <iostream>
using namespace std;

template <class T>
void bubbleSort(T values[], int numValues)
{
    int i, j;
    for (i = 0; i < numValues - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < numValues - i - 1; j++)
            if (values[j] > values[j + 1])
            {
                T temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
}

template <class T>
int binarySearch(T values[], int left, int right, T findX)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (values[mid] == findX)
        {
            return mid;
        }
        if (values[mid] > findX)
            return binarySearch(values, left, mid - 1, findX);
        if (values[mid] < findX)
            return binarySearch(values, mid + 1, right, findX);
    }
    return -1;
}
template <class T>
void printArray(T values[], int numValues)
{
    for (int i = 0; i < numValues; i++)
    {
        cout << values[i] << "  ";
    }
    cout << endl;
}
int main()
{
    int intArray[] = {55, 2, 11, 21, 42, 3, 15, 73, 22, 17};
    float floatArray[] = {33.2, 9.1, 20.5, 1.9, 18.2, 0.2, 75.3, 25.7, 77.8, 45.4};
    string strArray[] = {"Gloin", "Dori", "Oin", "Fili", "Kili", "Balin", "Bofur", "Bombur", "Nori", "Ori", "Dwalin", "Bifur", "Thorin", "Gandalf", "Bilbo"};
    

    cout << "Int Array Before Bubble Sorting : ";
    printArray(intArray, 10);
    cout << "intArray After Bubble Sorting: ";
    bubbleSort(intArray, 10);
    printArray(intArray, 10);
    // floatArray
    cout << "floatArray Before Bubble Sorting : ";
    printArray(floatArray, 10);
    cout << "floatArray After Bubble Sorting: ";
    bubbleSort(floatArray, 10);
    printArray(floatArray, 10);
    // StrArray
    cout << "strArray Before Bubble Sorting : ";
    printArray(floatArray, 10);
    cout << "strArray After Bubble Sorting: ";
    bubbleSort(strArray, 15);
    printArray(floatArray, 10);

    int index;
    //intArray
    int i = 11;
    index = binarySearch(intArray, 0, 9, i);
    if (index == -1)
    {
        cout << "In int Array " << i << " Not found" << endl;
    }
    else
    {
        cout << "In int Array "
             << "Index of " << i << " is : " << index << endl;
    }
    i = 50;
    index = binarySearch(intArray, 0, 9, i);
    if (index == -1)
    {
        cout << "In int Array " << i << " Not found" << endl;
    }
    else
    {
        cout << "In int Array "
             << "Index of " << i << " is : " << index << endl;
    }

    // FloatArray
    float f = 25.7;
    index = binarySearch(floatArray, 0, 9, f);
    if (index == -1)
    {
        cout << "In float Array " << f << " Not found" << endl;
    }
    else
    {
        cout << "In float Array "
             << "Index of " << f << " is : " << index << endl;
    }
    f = 50.9;
    index = binarySearch(floatArray, 0, 9, f);
    if (index == -1)
    {
        cout << "In float Array " << f << " Not found" << endl;
    }
    else
    {
        cout << "In float Array "
             << "Index of " << f << " is : " << index << endl;
    }
    // stringArray
    string str = "Kili";
    index = binarySearch(strArray, 0, 14, str);
    if (index == -1)
    {
        cout << "In Str Array " << str << " Not found" << endl;
    }
    else
    {
        cout << "In str Array "
             << "Index of " << str << " is : " << index << endl;
    }
    str = "Dalin";
    index = binarySearch(strArray, 0, 14, str);
    if (index == -1)
    {
        cout << "In str Array " << str << " Not found" << endl;
    }
    else
    {
        cout << "In str Array "
             << "Index of " << str << " is : " << index << endl;
    }

    return 0;
}