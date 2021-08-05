/* Type your code here */
#include <iostream>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string name, string date)
{
    customerName = name;
    currentDate = date;
}
string ShoppingCart::GetCustomerName()
{
    return this->customerName;
}
string ShoppingCart::GetDate()
{
    return this->currentDate;
}
void ShoppingCart::AddItem(ItemToPurchase item)
{
    cartitems.push_back(item);
}
void ShoppingCart::Removeitem(string name)
{
    vector<ItemToPurchase>::iterator r = cartitems.begin();
    for (unsigned i = 0; i < cartitems.size(); i++)
    {

        if (cartitems.at(i).GetName() == name)
        {
            vector<ItemToPurchase>::iterator remove = cartitems.begin() + i;
            cartitems.erase(r);
            // cout<< endl;
            return;
        }
        r++;
    }
    cout << "Item not found in cart. Nothing removed.\n";
}
void ShoppingCart::ModifyItem(ItemToPurchase item)
{
    if (item.GetName() != "none")
    {
        for (unsigned i = 0; i < cartitems.size(); i++)
        {
            if (cartitems.at(i).GetName() == item.GetName())
            {
                cartitems.at(i).SetQuantity(item.GetQuantity());
                cout << "Get Qauntity : " << cartitems.at(i).GetQuantity();
                return;
            }
        }
        cout << "Item not found in cart. Nothing modified.\n"
             << endl;
    }
}
int ShoppingCart::GetNumItemsInCart()
{

    int quant = 0;
    for (unsigned i = 0; i < cartitems.size(); i++)
    {
        quant += cartitems.at(i).GetQuantity();
    }
    return quant;
}
int ShoppingCart::GetCostOfCart()
{
    int cost = 0;
    for (unsigned i = 0; i < cartitems.size(); i++)
    {
        cost += cartitems.at(i).GetQuantity() * cartitems.at(i).GetPrice();
    }
    return cost;
}
void ShoppingCart::PrintDescriptions()
{
    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl
         << endl;
    cout << "Item Descriptions" << endl;

    for (unsigned i = 0; i < cartitems.size(); i++)
    {
        cout << cartitems.at(i).GetName() << ": " << cartitems.at(i).GetDescription() << endl;
    }
    cout << endl;
}
void ShoppingCart::PrintTotal()
{
    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl
         << endl;

    int total = 0;
    for (unsigned i = 0; i < cartitems.size(); i++)
    {
        cartitems.at(i).PrintitemCost();

        total += cartitems.at(i).GetQuantity() * cartitems.at(i).GetPrice();
    }
    if (cartitems.size() == 0)
    {

        cout << "SHOPPING CART IS EMPTY\n";
    }
    cout << "\nTotal: $" << total << endl;
}