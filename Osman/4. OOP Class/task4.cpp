//4.	File processing								  

// 	Below you will see a class LOTTERY with a string-array numbers[6] and a string superNumber:
// 	With the member function generateRandomNumbers(), 6 random numbers are being stored in the array number, which can store 6 values/strings
// 	and a number between 0-9 is being assigned to the string superNumber.
// 	With the member function printNumbers, the values of the array and also the superNumber is being printed.
// 	You don't have to edit those two member functions.
//
// 	Implement/Change the following three member functions, which are already declared in the class:
// 4.1) sortNumbers/swap:   The member function "sortNumbers" is sorting the values of the array "numbers" ascending, meaning from lowest to highest.
//                          Unfortunately, the function swap is not swapping the passed values of the array/not sorting the array. Why?
//                          ANSWER: A copy was sent to the function, meaning there was no reference to the original values of the variables. We have to declare it as call-by-reference function.
//                          Fix the error by correcting the member function sortNumbers and the function swap so that the values are actually being swapped and sorted.
//                          YOU STILL HAVE TO USE THE FUNCTION swap! YOU'RE NOT ALLOWED TO COPY THE CONTENT OF SWAP AND PASTE IT INTO THE MEMBER FUNCTION sortNumbers!
//
// 4.2) writeFile:          This member function will write the values of the array and then the superNumber into a file named "lottery.txt".
//                          Each value has to be written into a new line. This member function will always overwrite the content of the file.
//
// 4.3) readFile:           This member function is reading the file lottery.txt. The first 6 lines are read and printed out.
//                          The last line is the superNumber. Therefore it will say "SUPER: " and then the read value (= super number/last line of the txt-file).
//                          You also have to check whether the file already exists or not. If the file does not exist, display a message saying that the file couldn't be found.
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;


const int arraySize = 6;

class LOTTERY
{
private:
    int numbers[arraySize];
    int superNumber;
public:
    LOTTERY()
    {
        for(int i = 0; i < arraySize; i++)
            numbers[i] = 0;
        superNumber = 0;
    }

    void generateRandomNumbers() // Generates random numbers for the array numbers[6] between 0 and 49 and sets the superNumber, which is a number between 0 and 9
    {
        unsigned seed = time(0);
        srand(seed);

        for(int i=0; i<6; i++)
        {
            bool unique;
            int newitem;
            do
            {
                unique=true;
                newitem = rand() % 50;
                for(int i1=0; i1<i; i1++)
                {
                    if(numbers[i1]==newitem)
                    {
                        unique=false;
                        break;
                    }
                }
            }
            while(!unique);

            numbers[i] = newitem;
        }

        superNumber = rand() % 9 + 1;
    }

    void printNumbers()
    {
        for(int i = 0; i < arraySize; i++)
            cout << numbers[i] << " ";
        cout << "SUPER: " << superNumber;
        cout << endl << endl;
    }

    void sortNumbers();
    void writeFile();
    void readFile();
};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void LOTTERY::sortNumbers()
{
    int i, j;
    for (i = 0; i < arraySize-1; i++)
        // Last i elements are already in place
        for (j = 0; j < arraySize-i-1; j++)
            if (numbers[j] > numbers[j+1])
                swap(numbers[j], numbers[j+1]);

}

void LOTTERY::writeFile()
{
    ofstream writeFile("lottery.txt", ios::in);   //Write file, it will overwirte file each run
    for(int i=0; i< 6; i++){
        writeFile <<numbers[i]<<"\n"; // writing values into file
    }
    writeFile <<superNumber<< " \n"; // write superNumber in file
}

void LOTTERY::readFile()
{

ifstream readFile("lottery.txt",ios::out); // open file tp read data from file
  if(readFile.good()) // if the file is available
  {
      string tp, super;
      int i =0;

      while(getline(readFile, tp)) // getting data while there is any data 
      {
        super = tp;
        if(i<=5){
            cout<< "Numbers["<< i<<"]: "<< tp << endl; // printing numbers
        }
        i++;
      }
      cout<< "Super Number is : "<< super<< endl; // print super Number 
  }
  else {
      cout<< "File could not be found "<< endl; // error in opening file 
  }
  readFile.close();
}


int main()
{
    LOTTERY lottery = LOTTERY();
    lottery.generateRandomNumbers();
    int choice = 1;
    do
    {
        system("cls");
        cout << "[1] Sort numbers ascending" << endl;
        cout << "[2] Write numbers into file" << endl;
        cout << "[3] Read numbers from file" << endl;
        cout << "[0] Exit" << endl;

        cin >> choice;
        switch(choice)
        {
        case 1:
            lottery.sortNumbers();
            lottery.printNumbers();
            system("pause");
            break;
        case 2:
            lottery.generateRandomNumbers();
            lottery.sortNumbers();
            lottery.writeFile();
            system("pause");
            break;
        case 3:
            lottery.readFile();
            system("pause");
            break;
        case 0:
            return 0;
        default:
            cout << "Wrong input!" << endl;
            system("pause");
        }
    }
    while(choice != 0);

    cout << endl;
    system("pause");
    return 0;
}
