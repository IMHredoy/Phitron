#include <bits/stdc++.h>

using namespace std;

class shop
{
public:
    string *productName;
    int *productPrice;
    int *productQuantity;
private:
    int totalIncome;
public:
    shop(int numberOfProducts)
    {
        this->productName = new string[numberOfProducts];
        this->productPrice = new int[numberOfProducts];
        this->productQuantity = new int[numberOfProducts];
        this->totalIncome = 0;
    }
    void selling(int productCode, int productQuantity)
    {
        cout << this->productName[productCode-1] << " bought " << productQuantity << " pcs successfully." << endl;
        this->productQuantity[productCode-1] -= productQuantity;
        this->totalIncome += (this->productPrice[productCode-1] * productQuantity);
    }
    void showTotalIncome()
    {
        cout << "Your total income: " << this->totalIncome << endl << endl;
    }
};

void productListing(int numberOfProducts, shop *products)
{
    for(int i = 0; i < numberOfProducts; i++)
    {
        cout << "Product " << i+1 << " name: ";
        cin >> products->productName[i];
        cout << "Product " << i+1 << " price: ";
        cin >> products->productPrice[i];
        cout << "Product " << i+1 << " quantity: ";
        cin >> products->productQuantity[i];
    }
}

void displayProducts(int numberOfProducts, shop products)
{
    cout << "\t\t\t    BUY PRODUCTS" << endl;
    cout << "\t\t\t___________________" << endl;

    string text[4] = {"Product Code", "Product Name", "Product Price", "Product Quantity"};

    int i, j;
    for(i = 0; i < 4; i++)
    {
        cout << text[i] << "\t\t\t";
        if(i == 3) cout << "\b\b\b\b\b\b\b\b";
        for(j = 0; j < numberOfProducts; j++)
        {
            if(i == 0)  cout << j + 1 << "\t";
            else if(i == 1) cout << products.productName[j] << "\t";
            else if(i == 2) cout << products.productPrice[j] << "\t";
            else cout << products.productQuantity[j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int numberOfProducts;
    cout << "Number of Products: ";
    cin >> numberOfProducts;

    shop products(numberOfProducts);

    //this function will list the products.
    productListing(numberOfProducts, &products);

    display:
    //this function will display products to customer.
    displayProducts(numberOfProducts, products);

    int productCode, orderQuantity;
    char ch;
    cout << "Which Product do you want? From 1 to " << numberOfProducts << ": ";
    cin >> productCode;
    cout << "What is the quantity that you want of " << products.productName[productCode-1] << ": ";
    cin >> orderQuantity;
    cout << endl;
    if(products.productQuantity[productCode-1] >= orderQuantity && orderQuantity > 0)
    {
        products.selling(productCode, orderQuantity);
        products.showTotalIncome();
        cout << "Do you want to purchase more products ? If yes press 'y' or press 'any key other then \'y\'': ";
        cin >> ch;
        cout << endl;
        if(ch == 'y') goto display;
        else cout << "Thanks for Purchasing from us." << endl;
    }
    else if(orderQuantity == 0) 
    {
        cout << "Please order atleast one product" << endl << endl;
        goto display;
    }
    else 
    {
        cout << "This quantity is not available." << endl;
        cout << "Please Order less then or equal to our stocks quantity." << endl;
        cout << "Do you want to order again? If yes press 'y' or press 'any key other then \'y\'': ";
        cin >> ch;
        cout << endl;
        if(ch == 'y') goto display;
        else cout << "Thanks for visiting our shop" << endl;
    }
    return 0;
}