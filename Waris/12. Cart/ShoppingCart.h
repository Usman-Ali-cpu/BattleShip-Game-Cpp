/* Type your code here */
#pragma once
#ifndef SHPPINGCART_H
#define SHPPINGCART_H
#include "ItemToPurchase.h"
#include <vector>

class ShoppingCart : public ItemToPurchase
{
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartitems;

public:
    ShoppingCart();
    ShoppingCart(string name, string date);
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase item);
    void Removeitem(string name);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintDescriptions();
    void PrintTotal();
};
#endif