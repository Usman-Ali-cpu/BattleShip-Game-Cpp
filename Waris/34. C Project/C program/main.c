#include <stdio.h>
#include <stdlib.h>

#define ROWS 31        // for number of rows
#define COLUMNS 4      // for number of column
#define SUMMARY_ROWS 4 // for the output, number of rows

void GETFILENAME(char[]);                                 // take name of file input while file not found
void READFILE(char[], char[][10], double[][COLUMNS]);     // read data from file and store in arrays, header and data in separate arrays
double MAXIMUM(double[][COLUMNS], int);                   //take array containing data and return maximum from that column
int COUNT(double[][COLUMNS], int, double);                // return count of number from given coloumn
int SUM(double[][COLUMNS], int, double);                  //  return sum of numbers ina given column
void SUMMARY(double[][COLUMNS], double[][COLUMNS]);       // store result of summary in arrays
void PRINTROW(double[][COLUMNS], int);                    // print each row for summary
void PRINTSUMMARY(char[], char[][10], double[][COLUMNS]); // print all summries

int main()
{
    char fileName[50];                                   // to store name of file
    char headers[COLUMNS][10];                           // to store from the file
    double dataTable[ROWS][COLUMNS];                     // to store data from the fill
    double summaryInformation[SUMMARY_ROWS][COLUMNS];    // to store result data
    GETFILENAME(fileName);                               // open the file
    READFILE(fileName, headers, dataTable);              // get data in array
    SUMMARY(dataTable, summaryInformation);              // get summary in array
    PRINTSUMMARY(fileName, headers, summaryInformation); // print summary on screen
    return 0;
}
// first of all you should try to find, where .exe file of your program is created. Then we will place out txt file there. then we can run your program.
// function to get the filename
void GETFILENAME(char file[])
{

    printf("Type the filename to process > "); // prompt the user to enter a filename
    scanf("%s", file);                         // input a name of file
    printf("file : %s\n", file);
    FILE *fptr = fopen(file, "r"); // check if the file exists by opening it
    while (fptr == NULL)           // it will be null if file not found
    {
        printf("error: file not found\n");         // give error message of file not found
        printf("Type the filename to process > "); // prompt the user to enter a filename again
        scanf("%s", file);                         // input a name of file
        fptr = fopen(file, "r");                   // try opening the file again
    }
    fclose(fptr); // close the file, if it was found and opened successfully
}
// function to read the file
void READFILE(char filename[], char head[][10], double dataTable[][COLUMNS])
{

    FILE *fptr = fopen(filename, "r"); // open the file for reading
    if (fptr != NULL)
    {
        fscanf(fptr, "%[^,],%[^,],%[^,],%s", head[0], head[1], head[2], head[3]); // read the headers
        // read the data
        int i = 0;
        while (fscanf(fptr, "%lf,%lf,%lf,%lf", &dataTable[i][0], &dataTable[i][1], &dataTable[i][2], &dataTable[i][3]) == 4)
        {
            i++;
        }
        fclose(fptr); // close the file
    }
}
// get the maximum value of a specific column
double MAXIMUM(double dataTable[][COLUMNS], int column)
{
    double max = 0; // intialize the max with 0
    for (int i = 1; i < ROWS; i++)
    {
        if (dataTable[i][column] > max) // check if data in column is greate than max, make it max
            max = dataTable[i][column]; // given value to max
    }
    return max; // return max value
}
// function to count the number of values in a specific column
// that are above a boundary value
int COUNT(double dataTable[][COLUMNS], int column, double boundary)
{
    double count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (dataTable[i][column] > boundary)
            count++;
    }
    return count;
}
// function to sum values in a column that are above a boundary value
int SUM(double dataTable[][COLUMNS], int column, double boundary)
{
    double sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (dataTable[i][column] > boundary)
            sum += dataTable[i][column];
    }
    return sum;
}
// function to generate a summary from dataTable
void SUMMARY(double dataTable[][COLUMNS], double data[][COLUMNS])
{
    for (int column = 0; column < COLUMNS; column++) // loop through all coloumn
    {
        data[0][column] = MAXIMUM(dataTable, column); // get maximum of that column
        int N = COUNT(dataTable, column, 0);          // get total number averages count
        data[1][column] = N;
        if (N > 0)
        {
            double A = SUM(dataTable, column, 0) / N; // get sum of given column
            data[2][column] = A;
            data[3][column] = COUNT(dataTable, column, A); // store count of that column
        }
        else
        {
            data[2][column] = 0.0;
            data[3][column] = 0.0;
        }
    }
}
// function to print a row of doubles
void PRINTROW(double dataRow[][COLUMNS], int row)
{
    for (int i = 0; i < 4; i++)
        printf(" %-7.2lf", dataRow[row][i]);
    printf("\n");
}
// function to print the summary
void PRINTSUMMARY(char filename[], char head[][10], double data[][COLUMNS])
{
    printf(" Summary information for \"%s\"\n", filename); // print message with filename
    printf("%40s ", "DUID");
    for (int i = 0; i < 4; i++)
        printf(" %-7s", head[i]); // prints heading
    printf("\n");
    printf("%40s", "Maximum Daily Average ");         // print title of row
    PRINTROW(data, 0);                                // print a row of  maximum of each column
    printf("%40s", "Daily Average above 0 ");         // print title of row
    PRINTROW(data, 1);                                // print a row of daily averages greater than 0  of each column
    printf("%40s", "Average of Daily Averages > 0 "); // print title of row
    PRINTROW(data, 2);                                // print a row of average of each column
    printf("%40s", "Daily Averages > Average ");      // print title of row
    PRINTROW(data, 3);                                // print a row of daily averges greater than average
}