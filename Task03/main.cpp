#include <iostream>
#include <string>
using namespace std;
struct Parcel { double kg; bool express; bool insured; };

// Grams overload: exact int match.
double charge(int grams) { return 30.0 + grams * 0.02; }
// Kilograms overload: defaults are supplied from right to left.
double charge(double kg, bool express = false, bool insured = false) {
    double total = 40.0 + kg * 25.0;
    if (express) total += 20.0;
    if (insured) total += 15.0;
    return total;
}
double charge(const Parcel& p) { return charge(p.kg, p.express, p.insured); }

int main() {
    Parcel p{2.0, true, true};
    cout << "charge(2) = " << charge(2) << " [int grams overload]\n";
    cout << "charge(2.0f) = " << charge(2.0f) << " [float promotes to double]\n";
    cout << "charge(2.0) = " << charge(2.0) << " [double kilograms overload]\n";
    cout << "charge(500) = " << charge(500) << " [int grams overload]\n";
    cout << "charge(1.5, true) = " << charge(1.5, true) << " [default insured=false]\n";
    cout << "charge(parcel) = " << charge(p) << " [Parcel overload]\n";
}
