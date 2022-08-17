 /*
COURSE 3
Module 8
Theory Exam 01
AUTHOR: IFTEKHAR MAHMUD HREDOY
EMAIL: imhredoy@gmail.com
----please give suggestion about how can I make this source code more efficient.----
*/
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

//TASK 01
class Restaurant
{
public:
    int *foodItemCodes;
    string *foodItemNames;
    int *foodItemPrices;
    int numberOfFoodItems; 
private:
    double totalTax;
public:
    Restaurant(int numberOfFoodItems)
    {
        this->foodItemCodes = new int[numberOfFoodItems];
        this->foodItemNames = new string[numberOfFoodItems];
        this->foodItemPrices = new int[numberOfFoodItems];
        this->numberOfFoodItems = numberOfFoodItems;
        this->totalTax = 0.0;
    }
    //task 2
    void foodItemListing()
    {
        for(int i = 0; i < numberOfFoodItems; i++)
        {
            cin >> this->foodItemCodes[i];
            getchar();
            getline(cin, this->foodItemNames[i]);
            cin >> this->foodItemPrices[i];
        }
    }
    //task 3
    void showMenuItems()
    {
        cout << setw(50) << right << "MAKE BILL" << endl;
        cout << setw(57) << right << "_________________________" <<endl;
        cout << setw(32) << left << "Item Code" << setw(48) << left << "Item Name" << "Item Price" << endl;

        for(int i = 0; i < numberOfFoodItems; i++)
        {
            cout << setw(32) << left << this->foodItemCodes[i] << setw(48) << left << this->foodItemNames[i] << this->foodItemPrices[i] << endl;
        }
        cout << endl;
    }

    //task 4 and 8
    int** takingOrder(int* tableNumber, int* itemQuantity)
    {
        cout << "Enter Table No: ";
        cin >> *tableNumber;
        cout << "Enter Number of Items: ";
        cin >> *itemQuantity;

        int** customerOrder = new int*[*itemQuantity];
        for(int i = 0; i < *itemQuantity; i++)
        {
            customerOrder[i] = new int[2];
            cout << "Enter Item " << i+1 << " code: ";
            enterCode:
            int itemCode;
            cin >> itemCode;
            if(this->findFoodByCode(itemCode) == -1) // task 8
            {
                cout << "Invalid Code. Please Enter Item Code Again: ";
                goto enterCode;
            }
            customerOrder[i][0] = itemCode;
            cout << "Enter Item " << i+1 << " Quantity: ";
            cin >> customerOrder[i][1];
        }
        return customerOrder;
    }
    
    int findFoodByCode(int code)
    {
        int i;
        for(i = 0; i < this->numberOfFoodItems; i++)
        {
            if(this->foodItemCodes[i] == code) return i;
        }
        return -1;
    }
    void setTax(double taxAmount)
    {
        this->totalTax += taxAmount;
    }
    double getTax()
    {
        return this->totalTax;
    }
};

//Task 5, 6, 7

void billSummary(int* tableNumber, int* itemQuantity, int** customerOrder, Restaurant* KFC)
{
    cout << setw(50) << right << "BILL SUMMARY" << endl;
    cout << setw(57) << right << "_________________________" <<endl;
    cout << "Table No. : " << *tableNumber << endl;
    int colSize = 25;
    cout << setw(colSize) << left << "Item Code";
    cout << setw(colSize) << left << "Item Name";
    cout << setw(colSize) << left << "Item Price";
    cout << setw(colSize) << left << "Item Quantity";
    cout << "Total Price" << endl;

    int totalPrice = 0;
    
    for(int i = 0; i < *itemQuantity; i++)
    {
        int itemCode = customerOrder[i][0];
        int index = KFC->findFoodByCode(itemCode);
        string itemName = KFC->foodItemNames[index];
        int itemPrice = KFC->foodItemPrices[index];
        int orderQuantity = customerOrder[i][1];
        int totalPerItem = itemPrice * orderQuantity;
        cout << setw(colSize) << left << itemCode;
        cout << setw(colSize) << left << itemName;
        cout << setw(colSize) << left << itemPrice;
        cout << setw(colSize) << left << orderQuantity;
        cout << totalPerItem << endl;
        totalPrice += totalPerItem;
    }
    double taxAmount = double((totalPrice * 5)) / double(100);
    KFC->setTax(taxAmount);
    cout << setw(colSize*4) << left << "TAX" << fixed << setprecision(2) << taxAmount << endl;
    for(int i = 0; i < (colSize*4) + 10; i++) cout << "_";
    cout << endl;
    cout << setw(colSize*4) << left << "NET TOTAL" << fixed << setprecision(2) << double(totalPrice + taxAmount) << " Taka" << endl;
}
int main()
{
    int numberOfFoodItems;
    cin >> numberOfFoodItems;

    Restaurant KFC(numberOfFoodItems); //task 1

    KFC.foodItemListing(); //task 2

    takingOrderMakingBill:
    KFC.showMenuItems(); //task 3

    int tableNumber, itemQuantity;
    
    int** customerOrder = KFC.takingOrder(&tableNumber, &itemQuantity); //task 4 and 8

    billSummary(&tableNumber, &itemQuantity, customerOrder, &KFC); //task 5, 6, 7;

    cout << "Next Please ? IF No one press 'x' Else press any key: ";
    char x;
    cin >> x;
    if(x != 'x') goto takingOrderMakingBill;

    cout << "Total Tax --> " << KFC.getTax() << endl;
    
    return 0;
}



