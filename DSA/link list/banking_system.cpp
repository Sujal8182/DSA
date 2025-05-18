#include<iostream>
using namespace std;

class bankAccount{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;
    
public:
    void detail(int accountNumber, string accountHolderName, double balance){
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;

        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Balance : " << balance << endl;
        cout << "-------------------------" << endl;
    }

    void deposit(int amount){
        if(amount >= 0){
            balance = balance + amount;
            cout << "Deposited : " << amount << endl;
            cout << "Current balance : " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
        cout << "-------------------------" << endl;
    }

    void withdraw(double amount){
        if(amount <= balance){
            balance = balance - amount;
            cout << "Withdrawn : " << amount << endl;
            cout << "Current balance : " << balance << endl;
        } else {
            cout << "Invalid withdraw amount." << endl;
        }
        cout << "-------------------------" << endl;
    }

    double getbalance(){
        return balance;
    }

    void displayAccountDetails(){
        cout << "Account Number : " << this->accountNumber << endl;
        cout << "Account Holder Name : " << this->accountHolderName << endl;
        cout << "Balance : " << this->balance << endl;
    }
};

class Savingaccount : public bankAccount{
public:
    double interestRate;

    void calculateInterest(double interestRate){
        double interest = (getbalance() * interestRate) / 100; 
        balance = interest + balance;
        cout << "Interest Rate is = " << interestRate << endl;
        cout << "Interest is : " << interest << endl;
        cout << "Current Balance = " << balance << endl;
        cout << "-------------------------" << endl;
    }
};

class Checkingaccount : public bankAccount{
public:
    int overdraftLimit;

    void checkOverdraft(int od , int overdraftLimit){
        this->overdraftLimit = overdraftLimit;
        if (od >= getbalance()) {
            if (od <= overdraftLimit + getbalance()){
                double calculate = od - getbalance();
                cout << "Your OD Amount from OverdraftLimit = " << calculate << endl;
            } else {
                cout << "Enfluence balance !!" << endl;
            }   
        } else {
            cout << "Already Balance.." << endl;
        }

        cout << "-------------------------" << endl;
    }
};

class FixedDepositAccount : public bankAccount{
public:
    double term;

    void calculateInterest(int amount , double interestRate){
        if (amount <= getbalance()){
            cout << "Enter FixDeposite Duration in month = ";
            cin >> term;
            double interest = (getbalance() * interestRate * term) / (100*12); 
            double cal = interest + amount;
            cout << "Interest Rate is = " << interestRate << endl;
            cout << "Fix-Deposite Interest = " << interest << endl;
            cout << "Total Amount = " << amount << " + " << interest << " = "  << cal << endl;
        } else {
            cout << "Enfluence Balance !" << endl;
        }

        cout << "-------------------------" << endl;
    }
};

int main(){
    int accountNumber;
    string accountHolderName;
    double balance, overdraft;
    int amount, withdrawAmount, choice;

    cout << "Enter account number : ";
    cin >> accountNumber;
    cout << "Enter account holder name : ";
    cin >> accountHolderName;
    cout << "Enter balance : ";
    cin >> balance;

    cout << "-------------------------" << endl;

    Savingaccount bacc;
    Checkingaccount cass;
    FixedDepositAccount fass;

    bacc.detail(accountNumber, accountHolderName, balance);

    do {
        cout << "\n========== Menu ==========\n";
        cout << "1. Show Account Details\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Calculate Saving Interest\n";
        cout << "5. Check Overdraft\n";
        cout << "6. Fixed Deposit\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-------------------------" << endl;

        switch (choice) {
            case 1:
                bacc.displayAccountDetails();
                break;

            case 2:
                cout << "Enter amount to deposit : ";
                cin >> amount;
                bacc.deposit(amount);
                break;

            case 3:
                cout << "Enter amount to withdraw : ";
                cin >> withdrawAmount;
                bacc.withdraw(withdrawAmount);
                break;

            case 4:
                bacc.calculateInterest(5);
                break;

            case 5:
                cass.detail(accountNumber, accountHolderName, bacc.getbalance());
                cout << "Your OverdraftLimit (0 to 50000)" << endl;
                cout << "Enter Withdrawal Amount to Overdraft from " << bacc.getbalance() + 50000 << " = ";
                cin >> overdraft;
                cass.checkOverdraft(overdraft , 50000);
                break;

            case 6:
                fass.detail(accountNumber, accountHolderName, bacc.getbalance());
                cout << "Enter Amount for FixDeposit = ";
                cin >> amount;
                fass.calculateInterest(amount , 7);
                break;

            case 0:
                cout << "Exiting... Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while(choice != 0);

    return 0;
}