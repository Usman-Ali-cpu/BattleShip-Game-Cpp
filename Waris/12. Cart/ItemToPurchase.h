/* Type your code here */
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

/* Type your code here */
class  ItemToPurchase{
private:
   string itemName; //- Initialized in default constructor to "none"
   int itemPrice; // - Initialized in default constructor to 0
   int itemQuantity;
   string description;
public:
   ItemToPurchase();
   ItemToPurchase(string ame, string description, int price =0,int  quantity =0);
   ItemToPurchase(string ame);
    void SetName(string name);
    string GetName();
    void SetPrice(int price);
    int GetPrice();
    void SetQuantity(int quantity);
    int GetQuantity();
    void PrintitemCost();
    void PrintitemDescription();
    void SetDescription(string des);
    string GetDescription();
};


#endif