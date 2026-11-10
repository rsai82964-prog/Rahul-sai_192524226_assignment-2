double charge(double weight) { return weight * 10; }
double charge(double weight, bool express) { return weight * 10 + (express ? 20 : 0); }
double charge(double weight, bool express = false, bool insured = false) { return weight * 10 + (express ? 20 : 0) + (insured ? 15 : 0); }
int main() { return static_cast<int>(charge(2.0)); }
