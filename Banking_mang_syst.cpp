
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    long long accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(long long accNo, string name, double amount) {
        accountNumber = accNo;
        holderName = name;
        balance = amount;
    }

    void displayDetails() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Balance: Rs. " << fixed
             << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
            cout << "Updated balance: Rs. "
                 << balance << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Enter a valid amount!\n";
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
            cout << "Remaining balance: Rs. "
                 << balance << endl;
        }
    }

    void checkBalance() {
        cout << "Current balance: Rs. "
             << fixed << setprecision(2)
             << balance << endl;
    }
};

int main() {
    long long accountNumber;
    string name;
    double initialBalance;
    int choice;
    double amount;

    cout << "===== CREATE BANK ACCOUNT =====\n";

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter account holder name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Enter initial deposit: Rs. ";
    cin >> initialBalance;

    if (initialBalance < 0) {
        cout << "Initial balance cannot be negative!\n";
        return 1;
    }

    BankAccount account(
        accountNumber, name, initialBalance
    );

    do {
        cout << "\n===== BANKING MENU =====\n";
        cout << "1. Display Account Details\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.displayDetails();
                break;

            case 2:
                cout << "Enter deposit amount: Rs. ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 3:
                cout << "Enter withdrawal amount: Rs. ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 4:
                account.checkBalance();
                break;

            case 5:
                cout << "Thank you for using our system!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
