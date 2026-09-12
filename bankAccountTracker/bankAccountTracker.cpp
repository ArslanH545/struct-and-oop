#include <iostream>
using namespace std;

struct BankAccount{
    int accountNumber;
    string onwerName;
    double* const balance;
    int* const transactionCount;

    BankAccount(int accountNumber, string name, double *b, int* count): 
        accountNumber(accountNumber), onwerName(name), balance(b), transactionCount(count){}

    void deposit(double amount){
        *balance += amount; 
        *transactionCount += 1;
    }
    void withdraw(double amount){
        if (amount <= *balance){
            *balance -= amount;
            *transactionCount += 1;
        } else {
            cout << "Not Enough Balance" << endl;
        }
    }

    void displayAccount() const{
        cout << "Account #: " << accountNumber << "\n" 
            << "Onwer: " << onwerName << "\n"
            << "Balance: " << *balance << "\n"
            << "Transactions: " << *transactionCount << endl;
    }

    void transfer(BankAccount& receiver, double amount){
        if (*balance >= amount){
            *receiver.balance += amount;
            *receiver.transactionCount += 1;
            *balance -= amount;
            *transactionCount += 1;
        } else {
            cout << "Not Enough Balance" << endl;
        }
    }

    static void bankMessage(){
        cout << "Welcome to the Bank Account System" << endl;
    }
};


int main(){
    BankAccount::bankMessage();
    double johnBalance = 1000;
    int johnTransactions = 0;

    BankAccount john(1001, "john", &johnBalance, &johnTransactions);
    cout << "=== John ===" << endl; 
    cout << "Deposit: 200" << endl;
    john.deposit(200);
    john.displayAccount();
    cout << endl;
    cout << "Widthdraw: 600" << endl;
    john.withdraw(600);
    john.displayAccount();
    
    cout << endl;

    double sarahBalance = 500;
    int sarahTransactions = 0;
    BankAccount sarah(1002, "sarah", &sarahBalance, &sarahTransactions);
    cout << "=== Sarah ===" << endl;
    cout << "Deposit: 300" << endl;
    sarah.deposit(300);
    sarah.displayAccount();
    cout << endl;
    cout << "Widthdraw: 400" << endl;
    sarah.withdraw(400);
    sarah.displayAccount();
    cout << endl;

    // John tranfer $200 to sarah. 
    cout << "Transfer Money: 200" << endl;
    john.transfer(sarah, 200);
    john.displayAccount();
    cout << endl;
    sarah.displayAccount();
    return 0;
}