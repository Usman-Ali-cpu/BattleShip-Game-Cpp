#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

struct Measure // structure in c
{
    bool go;             // boolean type value to check whether, batch is Go or NoGo
    float outerDiameter; // float type value to store outer Diameter
    float holeDiameter;  // float type value to store hole Diameter
    float thinkness;     // float type value to store thikness
};
int getCounts(char const *const fileName)
{
    int count = 0;                     // start counter to check number of batches in list
    FILE *file = fopen(fileName, "r"); // open file to read data
    char line[500];                    // char string to store line from file
    while (fgets(line, sizeof(line), file))
    {
        count++; // found line then increment the counter
    }
    fclose(file);     // close the file which was opened to read
    return count - 2; // return counter, -2 bacuase first two lines are name and date
}
const char *getMonName(int mon)
{
    switch (mon) // passing value to switch
    {
    case 1: // if mon is equal to 1 , then return month name as stirng January
        return "January";
        break;
    case 2: // if mon is equal to 1 , then return month name as stirng February
        return "February";
        break;
    case 3: // if mon is equal to 1 , then return month name as stirng March
        return "March";
        break;
    case 4: // if mon is equal to 1 , then return month name as stirng April
        return "April";
        break;
    case 5: // if mon is equal to 1 , then return month name as stirng May
        return "May";
        break;
    case 6: // if mon is equal to 1 , then return month name as stirng June
        return "June";
        break;
    case 7: // if mon is equal to 1 , then return month name as stirng July
        return "July";
        break;
    case 8: // if mon is equal to 1 , then return month name as stirng August
        return "August";
        break;
    case 9: // if mon is equal to 1 , then return month name as stirng September
        return "September";
        break;
    case 10: // if mon is equal to 1 , then return month name as stirng October
        return "October";
        break;
    case 11: // if mon is equal to 1 , then return month name as stirng November
        return "November";
        break;
    case 12: // if mon is equal to 1 , then return month name as stirng December
        return "December";
        break;
    default:
        return "invalid Month number. Please try again ....";
        break;
    }
}
float getMeanWholeDia(struct Measure *measure, int size)
{                  // passing pointer to struct of type Measure
    float sum = 0; // initialize sum to zero
    for (int i = 0; i < size; i++)
    {
        sum += measure[i].holeDiameter; // add hole diameter to sum
    }
    return sum / size; // to get mean divide it by size and then return
}
float getGo(struct Measure *measure, int size)
{               // passing pointer to struct of type Measure
    int go = 0; // to check which are in cat go
    for (int i = 0; i < size; i++)
    {                              // iterate over array of struct
        if (measure[i].go == true) // if go boolean is true for measure is true
        {
            go++; // increment counter of go
        }
    }
    return (go * 100) / size; // return percentage of go
}
float getMaxOuterDia(struct Measure *measure, int size)
{                                  // passing pointer to struct of type Measure
    float max = -2333.0;           // initialize with very small value
    for (int i = 0; i < size; i++) // iterate over array of struct
    {
        if (measure[i].outerDiameter > max) // if outer diameter is greater than maximum of diamters , then assign it to max
        {
            max = measure[i].outerDiameter;
        }
    }
    return max; // return maximum from outer diameter
}

float getMinOuterDia(struct Measure *measure, int size)
{                                  // passing pointer to struct of type Measure
    float min = 233333;            // initialize with very large value
    for (int i = 0; i < size; i++) // iterate over array of struct
    {
        if (measure[i].outerDiameter < min) // if outer diameter is greater than minimum of diamters , then assign it to min
        {
            min = measure[i].outerDiameter;
        }
    }
    return min; // return minimum from outer diameter
}

// If any single part in the batch fails in any
bool isGO(struct Measure *measure, int size)
{                                  // passing pointer to struct of type Measure
    for (int i = 0; i < size; i++) // iterate over array of struct
    {
        if (measure[i].go == false) // if any boolean value is false , the return false
        {
            return false;
        }
    }
    return true; // if no false , then return true
}

int main(int argc, char *argv[])
{
    //read any text file from currect directory
    printf("Welcome to the Sprocket Quality Control Analysis Tool.\n\n");    // wellcome message on console
    printf("Please enter the name of the file which contains the data: \n"); // ask the user to enter name of file
    char fileName[30] = " ";                                                 // declare char array to store name of file
    scanf("%s", &fileName);

    const int size = getCounts(fileName);                            // get number of batches in the file
    struct Measure *measure = malloc(sizeof(struct Measure) * size); // dynamic array of Measure Struct to store batches
    FILE *file = fopen(fileName, "r");                               // open file to read file

    if (!file) // if file not find
    {
        printf("\n Unable to open : %s ", fileName); // print message and then terminate program .
        return -1;                                   // return
    }
    printf("\nThank you. Opening the file.\n\n");
    char name[500];                  // store string name
    char date[500];                  // store string date
    fgets(name, sizeof(name), file); // get name from file
    fgets(date, sizeof(date), file); // get date from file
    char sub1[50], sub2[50], sub3[50];
    strncpy(sub1, date, 2);     // get first 2 char , months
    strncpy(sub2, date + 2, 2); // get next 2 char , days
    strncpy(sub3, date + 4, 4); // get fnext 4 char , year
    int mons = atoi(sub1);      // convert string to int for month
    int days = atoi(sub2);      // convert string to int for day
    int years = atoi(sub3);     // convert string to int for year
    char line[500];
    char val1[500];
    char val2[500];
    char val3[500];
    char val4[500];
    int a = 0;

    while (fgets(line, sizeof(line), file)) // lopp while there is any line in the file
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", &val1, &val2, &val3, &val4); // read comma separated values from line
        int i = atoi(val1);                                                        // convert to int
        float j = atof(val2);                                                      // convert to float
        float k = atof(val3);                                                      // convert to float
        float q = atof(val4);                                                      // convert to float
        measure[a].holeDiameter = k;                                               // assign value of k to hole diameter
        measure[a].outerDiameter = j;                                              // assign value of j to outer diameter
        measure[a].thinkness = q;                                                  // // assign value of q to thinkness diameter
        if (i == 1)                                                                // if first value from line i is equal to 1
        {
            measure[a].go = true; // go will be true
        }
        else // else if i is equal to zero
        {
            measure[a].go = false; // go will be false
        }
        a++;
    }
    float perGo = getGo(measure, size); // get Total batch for go
    float NoGo = 100 - perGo;           // calculate batch for no go
    fclose(file);                       // cloase reading file

    time_t t;                      // to get current date
    t = time(NULL);                // assign null value
    struct tm tm = *localtime(&t); // getting local time
    int day = tm.tm_mday;          // get day from struct
    int month = tm.tm_mon + 1;     // get month from struct
    int year = tm.tm_year + 1900;  // get year from year

    char rday[5];
    char rmon[5];
    char ryear[5];
    sprintf(rday, "%d", day);          // convert int day to string
    sprintf(rmon, "%d", month);        // convert int month to string
    sprintf(ryear, "%d", year - 2000); // convert int year  to string

    // I ran the program on June 27, 2021, the name of the  report would be report_062721.txt.
    char report[100] = "report_0";
    strcat(report, rmon);   // concatenate month number with name of file
    strcat(report, rday);   // concatenate day number with name of file
    strcat(report, ryear);  // concatenate year number with name of file
    strcat(report, ".txt"); // concatenate .txt with name of file

    FILE *fp = fopen(report, "w"); // open file to write

    /* Write content to file */
    char firstLine[200] = "Analysis of ";
    strcat(firstLine, name); // concatenate name with line string
    strcat(firstLine, " measured on ");

    strcat(firstLine, getMonName(month)); // get name of month and concatenate to line
    strcat(firstLine, " ");
    strcat(firstLine, rday); // concatenate day to line
    strcat(firstLine, " ");
    strcat(firstLine, ryear); // concatenate year to line

    printf("%s\n\n", firstLine); // print first line for output

    char second[100]; //

    sprintf(second, "%d", size); // get size of batch to second line
    strcat(second, " Sprockets are analysed");

    fprintf(fp, "%s\n\n", firstLine); // write first line to txt file
    fprintf(fp, "%s\n", second);      //  write second line to txt file

    printf("%s\n", second);  // print second line on console
    if (isGO(measure, size)) //
    {
        fprintf(fp, "%s\n\n", "The Batch is a Go"); // write line to the txt file
        printf("The Batch is a Go\n\n");            // print on console
    }
    else
    {
        fprintf(fp, "%s\n\n", "The Batch is a No Go"); // write line to txt file
        printf("The Batch is a No Go\n\n");            // print line on console
    }

    char ygo[50];
    sprintf(ygo, "%.0f", perGo);                // get int value to string
    strcat(ygo, "% of sprockets are Go");       // concatenate  a string
    fprintf(fp, "%s\n", ygo);                   // write line into txt file
    printf("%s\n", "50 % of sprockets are Go"); // print line on the console

    char ngo[50];
    sprintf(ngo, "%.0f", NoGo);              // get int value to string
    strcat(ngo, "% of sprockets are No Go"); // concatenate  a string
    fprintf(fp, "%s\n\n", ngo);              // write line into txt file
    printf("%s\n\n", "50 % of sprockets are No Go");

    char meanstr[100] = "Mean Hole Diameter: ";
    char w[10];
    sprintf(w, "%.3f", getMeanWholeDia(measure, size)); // get int value to string
    strcat(meanstr, w);                                 // concatenate  a string
    strcat(meanstr, " inches.");                        // concatenate  a string
    fprintf(fp, "%s\n", meanstr);                       // write line into txt file
    printf("%s\n", meanstr);                            // print line on the console

    char ranstr[100] = "Range of Outer Diameters: ";
    char z[10];
    sprintf(z, "%.3f", getMaxOuterDia(measure, size) - getMinOuterDia(measure, size)); // get int value to string get range
    strcat(ranstr, z);                                                                 // concatenate  a string
    strcat(ranstr, " inches.");                                                        // concatenate  a string
    fprintf(fp, "%s\n", ranstr);                                                       // write line into txt file
    printf("%s\n", ranstr);                                                            // print line on the console

    char maxstr[100] = "\tMaximum Outer Diameter: ";
    char x[10];
    sprintf(x, "%.3f", getMaxOuterDia(measure, size)); // get int value to string and get maximum outer diameter
    strcat(maxstr, x);                                 // concatenate  a string
    strcat(maxstr, " inches.");                        // concatenate  a string
    fprintf(fp, "%s\n", maxstr);                       // write line into txt file
    printf("%s\n", maxstr);                            // print line on the console

    char minstr[100] = "\tMinimum Outer Diameter: ";
    char y[10];
    sprintf(y, "%.3f", getMinOuterDia(measure, size)); // get int value to string and get miminum outer diameter
    strcat(minstr, y);                                 // concatenate  a string
    strcat(minstr, " inches.");                        // concatenate  a string
    fprintf(fp, "%s\n", minstr);                       // write line into txt file
    printf("%s\n", minstr);                            // print line on the console

    fclose(fp); // close writing file
    printf("\nThis data has been written to %s\n", report);
    return 0;
}