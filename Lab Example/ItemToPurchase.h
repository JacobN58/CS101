#ifndef _ItemToPurchase_h
#define _ItemToPurchase_h
#include <string>
using namespace std;

class ItemToPurchase {
public:
         ItemToPurchase();
         void SetName(string name);
         string GetName() const;

         void SetPrice(int price);
         int GetPrice() const;

         void SetQuantity(int quantity);
         int GetQuantity() const;

         void Print() const;
private:
         string itemName;
         int itemPrice;
         int itemQuantity;
};
#endif              
