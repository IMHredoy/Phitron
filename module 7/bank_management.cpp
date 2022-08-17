#include <bits/stdc++.h>

using namespace std;

class BankAccount
{
public:
    string accountHolder;
    string address;
    int age;
    int accountNumber;

protected:
    int balance;

private:
    string password;

public:
    BankAccount(string accountHolder, string address, int age, string password)
    {
        this->accountHolder = accountHolder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->accountNumber = rand()%1000000000;
        this->balance = 0;
        cout << "Your account no : " << this->accountNumber << endl;
    }
    int showBalance()
    {
        return this->balance;
    }
    void addMoney(int amount)
    {
        this->balance += amount;
        cout << "Add money successful" << endl;
    }
    void withDrawMoney(int amount)
    {
        this->balance -= amount;
    }

    friend class myCash;

};

class myCash
{
protected:
    int balance;
public:
    myCash()
    {
        this->balance = 0;
    }
    void addMoneyFromBank(BankAccount *account, string password, int amount)
    {
        if(account->password == password)
        {
            this->balance += amount;
            account->balance -= amount;
            cout << "Add money from Bank is Successful" << endl;
        }
        else
        {
            cout << "Wrong Password" << endl;
        }
    }

};

BankAccount* createAccount()
{
    string accountHolder, password, address;
    int age;
    cout << "CREATE ACCOUNT" << endl;
    cout << "Name: ";
    cin >> accountHolder;
    cout << "Address: ";
    cin >> address;
    cout << "Age: ";
    cin >> age;
    cout << "Password: ";
    cin >> password;
    BankAccount *newAccount = new BankAccount(accountHolder, address, age, password);

    return newAccount;
}

void addMoney(BankAccount *account)
{
    int amount;
    cout << "ADD MONEY " << endl;
    cout << "AMOUNT : ";
    cin >> amount;
    account->addMoney(amount);
    cout << endl;
    cout << "Your Current Balance is " << account->showBalance() << endl;
}

void withdrawMoney(BankAccount *account)
{
    int amount;
    cout << "Please Give Your Withdraw amount: ";
    cin >> amount;
    account->withDrawMoney(amount);
    cout << "You successfully withdraw " << amount << endl;
    cout << "Your Current balance is " << account->showBalance() << endl;
}
int main()
{
    BankAccount *newAccount = createAccount();

    addMoney(newAccount);
    withdrawMoney(newAccount);
    myCash user21;
    user21.addMoneyFromBank(newAccount, "hello", 4000);
    cout << "Your Current Balance : " << newAccount->showBalance() << endl;

    return 0;
}
