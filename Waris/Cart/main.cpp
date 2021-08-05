#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "ShoppingCart.cpp"
#include "ItemToPurchase.cpp"

void PrintMenu()
{

    /* Type your code here */
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit\n"
         << endl;
}

void ExecuteMenu(char option, ShoppingCart &cart)
{
    /* Type your code here */
    switch (option)
    {
    case 'a':
    {
        cout << "ADD ITEM TO CART\n";
        int price,
            quantity;
        string name, des;
        cout << "Enter the item name:\n";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the item description:\n";
        // cin.ignore();
        getline(cin, des);
        cout << "Enter the item price:\n";
        cin >> price;
        cout << "Enter the item quantity:\n";
        cin >> quantity;
        cout << endl;
        ItemToPurchase p(name, des, price, quantity);
        cart.AddItem(p);
    }
    /* code */
    break;
    case 'd':
    {
        string name;
        cout << "REMOVE ITEM FROM CART\n";
        cout << "Enter name of item to remove:\n";
        cin.ignore();
        getline(cin, name);
        cart.Removeitem(name);
        cout << endl;
    }
    break;
    case 'c':
    {

        string name;
        cout << "CHANGE ITEM QUANTITY\n";
        cout << "Enter the item name:\n";
        cin.ignore();
        getline(cin, name);
        int quantity;
        cout << "Enter the new quantity:\n";
        cin >> quantity;
        ItemToPurchase p(name, "none", 0, quantity);
        cart.ModifyItem(p);
    }
    break;
    case 'i':
        cout << "OUTPUT ITEMS' DESCRIPTIONS\n";
        cart.PrintDescriptions();
        break;
    case 'o':
    {
        cout << "OUTPUT SHOPPING CART\n";
        cart.PrintTotal();
        cout << endl;
    }
    break;
    case 'q':
        exit(0);
        break;

    default:
        break;
    }
}

int main()
{
    /* Type your code here */
    string name, date;
    cout << "Enter customer's name:\n";
    getline(cin, name);
    cout << "Enter today's date:\n";
    getline(cin, date);
    ShoppingCart cart(name, date);

    cout << "\nCustomer name: " << cart.GetCustomerName() << endl;
    cout << "Today's date: " << cart.GetDate() << endl
         << endl;

    PrintMenu();
    char ch;
    cout << "Choose an option:\n";
    cin >> ch;
    bool check;
    if (ch == 'a' || ch == 'd' || ch == 'c' || ch == 'i' || ch == 'o' || ch == 'q')
    {
        check = true;
    }
    else
    {
        check = false;
    }
    while (!check)
    {
        cout << "Choose an option:\n";
        cin >> ch;
        if (ch == 'a' || ch == 'd' || ch == 'c' || ch == 'i' || ch == 'o' || ch == 'q')
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }
    ExecuteMenu(ch, cart);
    while (true)
    {
        PrintMenu();
        cout << "Choose an option:\n";
        // cin.ignore();
        cin >> ch;
        bool check;
        if (ch == 'a' || ch == 'd' || ch == 'c' || ch == 'i' || ch == 'o' || ch == 'q')
        {
            check = true;
        }
        else
        {
            check = false;
        }
        while (!check)
        {
            cout << "Choose an option:\n";
            cin >> ch;
            if (ch == 'a' || ch == 'd' || ch == 'c' || ch == 'i' || ch == 'o' || ch == 'q')
            {
                check = true;
            }
            else
            {
                check = false;
            }
        }
        ExecuteMenu(ch, cart);
    }

    return 0;
}