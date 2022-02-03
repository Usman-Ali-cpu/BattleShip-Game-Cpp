#include <iostream>
#include <iomanip>
using namespace std;

// function will takes choice integer and return specific name of
// item on that choice

string item_map(int choice)
{
    switch (choice) // check the choice
    {
    case 1:
        return "Bread"; // if choice is equal to 1 return Bread
        break;
    case 2:
        return "Milk"; // if choice is equal to 2 return Milk
        break;
    case 3:
        return "Soap"; // if choice is equal to 3 return Soap
        break;
    case 4:
        return "Eggs"; // if choice is equal to 4 return Eggs
        break;
    case 5:
        return "Deordorant"; // if choice is equal to 5 return Deordorant
        break;
    case 6:
        return "Juice"; // if choice is equal to 6 return Juice
        break;
    case 7:
        return "Chips"; // if choice is equal to 7 return Chips
        break;
    case 8:
        return "Fork"; // if choice is equal to 8 return Fork
        break;
    case 9:
        return "Spoons"; // if choice is equal to 9 return spoons
        break;
    case 10:
        return "Cups"; // if choice is equal to 10 return chups
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
    return "Invalid"; // if choice is invalid
}

// get choice input the choice and validate it with while loop
int get_choice()
{
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > 10) // if choice is invalid
    {
        cout << "Sorry " << choice << " wasn't a valid choice " << endl;
        cout << "Please enter the choice: ";
        cin >> choice; // again input choice
    }
    return choice;
}
// get price will input price from user
double get_price()
{
    double price;
    cout << "Please enter the price: ";
    cin >> price; // input from console
    return price; // return price value
}

// to check whether the item is taxable or not
bool is_taxable(int choice)
{
    // if it is grocerry return false
    // else return true
    switch (choice)
    {
    case 1:
        return false;
        break;
    case 2:
        return false;
        break;
    case 3:
        return false;
        break;
    case 4:
        return false;
        break;
    case 5:
        return true;
        break;
    case 6:
        return false;
        break;
    case 7:
        return false;
        break;
    case 8:
        return true;
        break;
    case 9:
        return true;
        break;
    case 10:
        return true;
        break;

    default:
        break;
    }
    return false;
}

// computer tax will  calculate and return tax
double compute_tax(double price, int choice)
{
    if (!is_taxable(choice)) // it will check whether the item is taxable or not
    {
        return 0; // if not return 0 tax
    }
    double tax = 0.08 * price; // calculate tax
    return tax;
}

// it will calculate discounts
double computer_discount(double price, int age)
{
    if (age < 60) // if age is less than 60 no discount will be capaable
    {
        return 0; // return zero
    }
    double discount = 0.05 * price; // compute discount
    return discount;
}
void printInvoice(double price, int age, int choice)
{

    string name = item_map(choice);                   // get name
    double discounts = computer_discount(price, age); // compute discounts
    double tax = compute_tax(price, choice);          // caculate taxes
    double total = price + tax - discounts;           // compute totals

    cout << "\n\t   Invoice" << endl;
    cout << name << ":\t       $" << fixed << setprecision(2) << price << endl; // print price
    cout << "Tax:\t       $" << fixed << setprecision(2) << tax << endl;        // print tax
    if (discounts > 0)
    {
        cout << "Discount:\t$-" << fixed << setprecision(2) << discounts << endl; // print discount
    }
    cout << "Total\t       $" << fixed << setprecision(2) << total << endl; // print total price
    cout << "------------------------------\n"
         << endl;
}
int main()
{
    // this program will be run four time
    for (int i = 0; i < 4; i++)
    {
        int choice;
        // options for the users
        cout << "What whould you like to buy?" << endl;
        cout << "1. Bread:" << endl;
        cout << "2. Milk:" << endl;
        cout << "3. Soap:" << endl;
        cout << "4. Eggs:" << endl;
        cout << "5. Deodorant:" << endl;
        cout << "6. Juice:" << endl;
        cout << "7. Chips:" << endl;
        cout << "8. Fork:" << endl;
        cout << "9. Spoons:" << endl;
        cout << "10. Cups:" << endl;
        cout << "Please enter the choice: ";
        choice = get_choice(); // input choice
        double price;
        price = get_price(); // input price
        int age;
        cout << "Please enter the age: ";
        cin >> age;                       // input age
        printInvoice(price, age, choice); // print invoice on screen
    }

    return 0;
}