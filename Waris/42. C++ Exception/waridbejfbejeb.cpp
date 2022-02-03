#include <iostream>
#include <stdexcept>
#include <cmath> // sqrt()
#include <string>

using namespace std;

double calcDiscriminant(double a, double b, double c)
{ // user defined function for discriminant
    return (b * b) + (-4 * a * c);
}

double quadratic()
{ //user defined function for quadratic
    double a = 0, b = 0, c = 0;
    double solution1, solution2, oneSolution;
    cout << "Please enter the values of a, b, and c: " << endl;

    while (!(std::cin >> a >> b >> c)) // it will take input while input is not correct
    {
        if (!cin) // if input is not taken
        {
            throw "Malform user input"; // throw exception
        }
        throw "Malform user input";        // if input got taken, but input is invalid
        std::cin.clear();                  // clear input
        std::cin.ignore(2147483647, '\n'); // ignore buffer in input
    }

    if (!(a < 0 || a >= 0)) // check if value in input is not a number
    {
        if (!isnan(a)) // if it is not a number
        {
            cin.clear();                          // clean input
            throw "error occur: a must be digit"; // throw exception. with message
        }
    }
    if (a == 0)
    {
        throw "error occur: a must not be zero"; // if value of a is zero, throw exception
    }

    double discriminant = calcDiscriminant(a, b, c);

    if (discriminant < 0)
    {
        cout << "There is no solution." << endl;
        return 0;
    }
    else if (discriminant == 0)
    {
        cout << "There is 1 solution." << endl;
        oneSolution = -b / (2 * a);
        cout << "The solution is: " << oneSolution << endl;
        return 0;
    }
    else
    {
        cout << "There are 2 solutions." << endl;
        solution1 = (-b + sqrt(discriminant)) / (2 * a);
        solution2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "The solutions are:" << solution1 << " and " << solution2 << endl;
        return 0;
    }
}

int main()
{
    // try catch block
    try
    {
        quadratic(); // if this function throw exception
    }
    catch (const char *e) // catched by this
    {
        cerr << e << '\n'; // print that message here
    }
}
