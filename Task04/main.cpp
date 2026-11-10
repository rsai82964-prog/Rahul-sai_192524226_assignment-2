#include <iostream>
#include <iomanip>
using namespace std;

class SavingsAccount {
    long long accountNumber;
    double balance;
    double transactions[10]{};
    int count = 0;
public:
    explicit SavingsAccount(long long number, double opening) : accountNumber(number), balance(opening) {}
    void deposit(double amount) {
        if (amount <= 0) return;
        balance += amount; record(amount);
    }
    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount; record(-amount); return true;
    }
    void miniStatement() const;
private:
    void record(double amount) {
        if (count < 10) transactions[count++] = amount;
        else {
            for (int i = 1; i < 10; ++i) transactions[i-1] = transactions[i];
            transactions[9] = amount; // shift-based policy: discard oldest
        }
    }
};
void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << " | Balance: Rs " << fixed << setprecision(2) << balance << '\n';
    cout << "Last " << count << " transactions: ";
    for (int i=0; i<count; ++i) cout << (transactions[i] >= 0 ? "+" : "") << transactions[i] << ' ';
    cout << '\n';
}
int main() {
    SavingsAccount account(20261001, 1000.0);
    account.deposit(100); account.withdraw(50); account.deposit(25); account.withdraw(10);
    for (int i=1; i<=9; ++i) account.deposit(i * 5.0);
    account.miniStatement();
}
