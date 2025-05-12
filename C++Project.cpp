#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string name;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, string accName, double initialBalance = 0.0)
        : accountNumber(accNum), name(accName), balance(initialBalance) {}

    // Getter methods
    string getAccountNumber()  {
        return accountNumber;
    }

    string getName()  {
        return name;
    }

    double getBalance()  {
        return balance;
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
            } else {
                cout << "Insufficient balance. Current balance: $" << balance << endl;
            }
        } else {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }

    // Display account information
    void displayAccountInfo()  {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    // Create an array to hold 10 BankAccount objects
    BankAccount accounts[10] = {
        BankAccount("1234567890", "Alice Smith", 1000.50),
        BankAccount("9876543210", "Bob Johnson", 500.75),
        BankAccount("1122334455", "Charlie Brown", 200.00),
        BankAccount("5544332211", "Diana Lee", 1500.25),
        BankAccount("6789012345", "Eve Williams", 75.50),
        BankAccount("0987654321", "Frank Miller", 3000.00),
        BankAccount("2233445566", "Grace Davis", 1200.80),
        BankAccount("6655443322", "Henry Wilson", 50.00),
        BankAccount("3456789012", "Ivy Moore", 800.90),
        BankAccount("2109876543", "Jack Taylor", 250.60)
    };

    // Interact with the bank accounts (example operations)
    cout << "\n--- Account Operations ---" << endl;

    // Deposit into Alice's account
    accounts[0].deposit(500.00);

    // Withdraw from Bob's account
    accounts[1].withdraw(100.00);

    // Display Charlie's account information
    cout << "\n--- Charlie's Account Info ---" << endl;
    accounts[2].displayAccountInfo();

    // Attempt to withdraw more than the balance from Eve's account
    accounts[4].withdraw(100.00);

    // Deposit a negative amount into Frank's account
    accounts[5].deposit(-50.00);

    cout << "\n--- All Accounts Information ---" << endl;
    for (int i = 0; i < 10; ++i) {
        accounts[i].displayAccountInfo();
        cout << "-------------------------" << endl;
    }

    return 0;
}