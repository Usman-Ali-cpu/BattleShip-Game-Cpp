#include <stdio.h>

typedef struct
{
    int d; // to store days
    int m; // to store months
    int y; // to store years

} date_t; // struct of date having year month day

/*
In this program i made a struct for date, where it has year, months and days counts. I made a function time interval to 
find date interval in choronological order. Function accepts array of dates and length of date array as arguments. 
From array of date first find date having minimum values of year, months and days. Then find date having maximum values of
year, months and days. Now we have maximum date values and minimum values. Then by takiing difference we will get interval. Then that time
interval date object will be returned.  

*/
int countLeapYears(date_t d)
{
    int years = d.y; // get year

    // or not
    if (d.m <= 2) // if month is january or feburary
        years--;

    return years / 4 - years / 100 + years / 400;
}

date_t timeInterval(date_t dates[], int n)
{
    date_t mindate = dates[0]; // initializing minmum date
    date_t maxdate = dates[0]; // initializing maximum date
    int minyear = 2021;
    int maxyear = 0;
    for (int i = 0; i < n; i++) // looping through all dates
    {
        if (dates[i].y < mindate.y) // if year number of looping date is less than minimum date's year
        {
            mindate = dates[i]; // change the value of minimum date
        }
        if (dates[i].y == mindate.y) // if year number of looping date is equal minimum date's year
        {
            if (dates[i].m < mindate.m) // if month number of date is less than minimum date's month
            {
                mindate = dates[i]; // change the value of minimum date
            }
            else if (dates[i].m == mindate.m && dates[i].d <= mindate.d) // if month is same and date's day is less than minimum date then
            {
                mindate = dates[i]; // change the value of minimum date
            }
        }

        if (dates[i].y > mindate.y) // if year number of looping date is greater  than maximum date's year
        {
            maxdate = dates[i]; // change the value of maximum date
        }
        if (dates[i].y == mindate.y) // if year number of looping date is equal maximum date's year
        {
            if (dates[i].m > mindate.m) // if month number of date is greater than maximum date's month
            {
                mindate = dates[i]; // change the value of maximum date
            }
            else if (dates[i].m == mindate.m && dates[i].d >= mindate.d) // if month is same and date's day is greater than maximum date then
            {
                mindate = dates[i]; // change the value of maximum date
            }
        }
    }
    date_t interval;                    // initialize date struct variable
    interval.y = maxdate.y - mindate.y; // get difference of year
    interval.m = maxdate.m - mindate.m; // get difference of month
    interval.d = maxdate.d - mindate.d; // get difference of day
    return interval;
}

int main()
{

    date_t d[3];               // array of struct
    date_t t1 = {3, 5, 2012};  // intializing by giving value
    date_t t2 = {23, 8, 2020}; // intializing by giving value
    date_t t3 = {4, 3, 2006};  // intializing by giving value
    d[0] = t1;
    d[1] = t2;
    d[2] = t3;
    date_t t = timeInterval(d, 3);          // callling function
    printf("{%d ,%d, %d }", t.d, t.m, t.y); // printing value

    return 0;
}
