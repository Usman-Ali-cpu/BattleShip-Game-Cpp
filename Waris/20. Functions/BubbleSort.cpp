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
void printArray(T values[], int numValues)
{
    for (int i = 0; i < numValues; i++)
    {
        cout << values[i] << "  ";
    }
}

int main()
{
    int intArray[] = {55, 2, 11, 21, 42, 3, 15, 73, 22, 17};
    float floatArray[] = {33.2, 9.1, 20.5, 1.9, 18.2, 0.2, 75.3, 25.7, 77.8, 45.4};
    string strArray[] = {"Gloin", "Dori", "Oin", "Fili", "Kili", "Balin", "Bofur", "Bombur", "Nori", "Ori", "Dwalin", "Bifur", "Thorin", "Gandalf", "Bilbo"};

    // IntArray
    cout << "Int Array Before Bubble Sorting : ";
    printArray(intArray, 10);
    cout << "\nintArray After Bubble Sorting: ";
    bubbleSort(intArray, 10);
    printArray(intArray, 10);
    // floatArray
    cout << "\nFloatArray Before Bubble Sorting : ";
    printArray(floatArray, 10);
    cout << "\nfloatArray After Bubble Sorting: ";
    bubbleSort(floatArray, 10);
    printArray(floatArray, 10);
    // StrArray
    cout << "\nstrArray Before Bubble Sorting : ";
    printArray(floatArray, 10);
    cout << "\nstrArray After Bubble Sorting: ";
    bubbleSort(strArray, 15);
    printArray(floatArray, 10);
    return 0;
    // bubbleSort(intArray, 10);
    // cout << "Int Array : ";
    // printArray(intArray, 10);
    // bubbleSort(floatArray, 10);
    // cout << "Float Array : ";
    // printArray(floatArray, 10);
    // bubbleSort(strArray, 15);
    // cout << "Float Array : ";
    // printArray(strArray, 15);
    // cout << endl;
}