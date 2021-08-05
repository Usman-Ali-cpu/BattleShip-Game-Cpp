#include <string>
#include <iostream>
#include <vector>
using namespace std;

/* Type your code here */
class ItemToPurchase
{
private:
    string itemName; //- Initialized in default constructor to "none"
    int itemPrice;   // - Initialized in default constructor to 0
    int itemQuantity;
    string description;

public:
    ItemToPurchase()
    {
        itemName = "none";
        itemPrice = 0;
        itemQuantity = 0;
        description = "none";
    }
    ItemToPurchase(string name, string description, int price = 0, int quantity = 0)
    {
        this->itemName = name;
        this->description = description;
        this->itemPrice = price;
        this->itemQuantity = quantity;
    }
    void SetName(string name)
    {
        this->itemName = name;
    }
    string GetName()
    {
        return itemName;
    }
    void SetDescription(string des)
    {
        description = des;
    }
    string GetDescription()
    {
        return this->description;
    }
    void SetPrice(int price)
    {
        this->itemPrice = price;
    }
    int GetPrice()
    {
        return itemPrice;
    }
    void SetQuantity(int quantity)
    {
        this->itemQuantity = quantity;
    }
    int GetQuantity()
    {
        return this->itemQuantity;
    }
    void PrintitemCost()
    {
        cout << this->GetName() << " " << this->GetQuantity() << " @ $" << this->GetPrice() << " = $" << GetPrice() * this->GetQuantity() << endl;
    }
    void PrintitemDescription()
    {
        cout << this->GetName() << ": " << this->GetDescription() << endl;
    }
};

class ShoppingCart : public ItemToPurchase
{
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartitems;

public:
    ShoppingCart()
    {
        customerName = "none";
        currentDate = "January 1, 2016";
    }
    ShoppingCart(string name, string date)
    {
        customerName = name;
        currentDate = date;
    }
    string GetCustomerName()
    {
        return this->customerName;
    }
    string GetDate()
    {
        return this->currentDate;
    }
    void AddItem(ItemToPurchase item)
    {
        cartitems.push_back(item);
    }
    void Removeitem(string name)
    {
        for (int i = 0; i < cartitems.size(); i++)
        {
            if (cartitems.at(i).GetName() == name)
            {
                cartitems.erase(cartitems.begin() + i);
            }
        }
    }
    void ModifyItem(ItemToPurchase item)
    {
        if (item.GetName() != "none")
        {
            for (int i = 0; i < cartitems.size(); i++)
            {
                if (cartitems.at(i).GetName() == item.GetName())
                {
                    cartitems.at(i).SetDescription(item.GetDescription());
                    cartitems.at(i).SetQuantity(item.GetQuantity());
                    return;
                }
            }
            cout << "Item not found in cart. Nothing modified." << endl;
        }
    }
    int GetNumItemsInCart()
    {
        int quant = 0;
        for (unsigned i = 0; i < cartitems.size(); i++)
        {
            quant += cartitems.at(i).GetQuantity();
        }
        return quant;
    }
    int GetCostOfCart()
    {
        int cost = 0;
        for (int i = 0; i < cartitems.size(); i++)
        {
            cost += cartitems.at(i).GetQuantity() * cartitems.at(i).GetPrice();
        }
        return cost;
    }
    void PrintDescriptions()
    {
        cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
        for (int i = 0; i < cartitems.size(); i++)
        {
            cout << cartitems.at(i).GetDescription() << endl;
        }
    }
    void PrintTotal()
    {
        cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
        cout << "Number of Items: " << GetNumItemsInCart() << endl;

        int total = 0;
        for (int i = 0; i < cartitems.size(); i++)
        {
            cartitems.at(i).PrintitemCost();
            total += cartitems.at(i).GetQuantity() * cartitems.at(i).GetPrice();
        }
        cout << "Total: $" << total << endl;
    }
};

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
        cin.ignore();
        getline(cin, des);
        cout << "Enter the item price:\n";
        cin >> price;
        cout << "Enter the item quantity\n";
        cin >> quantity;
        ItemToPurchase p(name, "none", price, quantity);
        cart.AddItem(p);
    }
    /* code */
    break;
    case 'd':
    {
        string name;
        cout << "REMOVE ITEM FROM CART\n";
        cout << "Enter the item name to remove:\n";
        cin.ignore();
        getline(cin, name);
        cart.Removeitem(name);
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
        ItemToPurchase p(name, "none", quantity);
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
    //cin.ignore();
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
        cin.ignore();
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