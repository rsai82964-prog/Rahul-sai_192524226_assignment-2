#include <iostream>
#include <string>
using namespace std;

class Token {
    static int next;
    int id;
public:
    Token() : id(++next) {}
    int get() const { return id; }
    static int issued() { return next - 100; }
};
int Token::next = 100;

class BusTicket {
    static int issued;
    static const int CAPACITY = 3;
    int seat;
    string name;
public:
    explicit BusTicket(const string& n) : seat(0), name(n) {
        if (issued < CAPACITY) seat = ++issued; // TODO 1 completed
    }
    static int count() { return issued; } // TODO 2 completed
    void print() const {
        cout << name << ": " << (seat ? "Seat " + to_string(seat) : string("Waiting")) << '\n';
    }
};
int BusTicket::issued = 0;

void createMoreTickets() {
    BusTicket local[2] = {BusTicket("Esha"), BusTicket("Farhan")};
    for (const BusTicket& t : local) t.print();
}
int main() {
    Token counter[3]; Token extra;
    cout << counter[0].get() << ' ' << counter[2].get() << ' ' << extra.get() << ' ' << Token::issued() << '\n';
    BusTicket trip[4] = {BusTicket("Asha"), BusTicket("Bala"), BusTicket("Chitra"), BusTicket("Dev")};
    for (const BusTicket& t : trip) t.print();
    cout << "Issued: " << BusTicket::count() << '\n';
    createMoreTickets();
    createMoreTickets();
    cout << "Issued after second function call: " << BusTicket::count() << '\n';
}
