/* Type your code here */
#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    description = "none";
}
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)
{
    this->itemName = name;
    this->description = description;
    this->itemPrice = price;
    this->itemQuantity = quantity;
}
ItemToPurchase::ItemToPurchase(string ame)
{
    this->itemName = ame;
}

void ItemToPurchase::SetName(string name)
{
    this->itemName = name;
}
string ItemToPurchase::GetName()
{
    return itemName;
}

void ItemToPurchase::SetPrice(int price)
{
    this->itemPrice = price;
}
int ItemToPurchase::GetPrice()
{
    return itemPrice;
}
void ItemToPurchase::SetQuantity(int quantity)
{
    this->itemQuantity = quantity;
}
int ItemToPurchase::GetQuantity()
{
    return this->itemQuantity;
}
void ItemToPurchase::PrintitemCost()
{
    cout << this->GetName() << " " << this->GetQuantity() << " @ $" << this->GetPrice() << " = $" << GetPrice() * this->GetQuantity() << endl;
}
void ItemToPurchase::PrintitemDescription()
{
    cout << this->GetName() << ": " << this->GetDescription() << endl;
}
void ItemToPurchase::SetDescription(string des)
{
    description = des;
}
string ItemToPurchase::GetDescription()
{
    return this->description;
}