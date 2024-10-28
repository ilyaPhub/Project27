#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    int id;               
    int totalAmount;      
    int minWithdrawal;   
    int maxWithdrawal;     

public:
    ATM(int atmId, int initialAmount, int minW, int maxW) {
        id = atmId;
        totalAmount = initialAmount;
        minWithdrawal = minW;
        maxWithdrawal = maxW;
    }

    void loadMoney(int amount) {
        if (amount >= 100 && amount <= 1000) {
            totalAmount += amount;
            cout << "Loaded " << amount << " units.\n";
        }
        else {
            cout << "Error: Amount must be between 100 and 1000.\n";
        }
    }

    bool withdrawMoney(int amount) {
        if (amount < minWithdrawal) {
            cout << "Error: Amount is less than the minimum allowed.\n";
            return false;
        }
        if (amount > maxWithdrawal) {
            cout << "Error: Amount exceeds the maximum allowed.\n";
            return false;
        }
        if (amount > totalAmount) {
            cout << "Error: Not enough money in the ATM.\n";
            return false;
        }
        totalAmount -= amount;
        cout << "Withdrawn " << amount << " units.\n";
        return true;
    }

    string toString() const {
        return "Remaining balance in ATM: " + to_string(totalAmount) + " units.";
    }
};

int main() {
    ATM atm(1, 5000, 100, 1000);  

    cout << atm.toString() << endl;

    atm.loadMoney(500);  
    cout << atm.toString() << endl;

    atm.withdrawMoney(300); 
    cout << atm.toString() << endl;

    atm.withdrawMoney(2000);  
    cout << atm.toString() << endl;

    return 0;
}
