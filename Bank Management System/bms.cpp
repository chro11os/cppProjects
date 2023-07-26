#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
    private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNumber, string accHoldName, double initialBalance) {
        accountNumber = accNumber;
        accountHolderName = accHoldName;
        balance = initialBalance;

    }

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAcountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout<<"Deposit: $" <<amount <<" into account: " <<accountNumber<<endl;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout<<"Withdrawn: $"<<amount<<" from account: "<<accountNumber<<endl;
            return true;
        }
        cout<<"Insufficient balance in account: "<<accountNumber <<endl;
        return false;
    }

};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void createAccount(string accNumber, string accHolderName, double initialBalance) {
        BankAccount newAccount(accNumber, accHolderName, initialBalance);
        accounts.push_back(newAccount);
        cout<<"Account created successfully for: "<<accHolderName <<endl;

    }

    BankAccount* findAccount(string accNumber) {
        for (size_t i = 0; i< accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accNumber){
                return &accounts[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;

    bank.createAccount("6292","Neil Brags", 1000.0);
    bank.createAccount("2004","John Nexus", 5000.0);

    BankAccount* account1 = bank.findAccount("12345");
    if (account1 != nullptr){
        account1->deposit(500.0);
        account1->withdraw(200.0);
    }

    BankAccount* account2 = bank.findAccount("67890");
    if (account2 != nullptr) {
        account2->deposit(1000.0);
        account2->withdraw(7000.0);
    }
    return 0;
}