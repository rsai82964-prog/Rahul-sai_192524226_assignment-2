#include <iostream>
#include <algorithm>
using namespace std;

int& highestMark(int marks[], int n) {
    int index = 0;
    for (int i = 1; i < n; ++i) if (marks[i] > marks[index]) index = i;
    return marks[index];
}
const int& highestMarkReadOnly(const int marks[], int n) {
    int index = 0;
    for (int i = 1; i < n; ++i) if (marks[i] > marks[index]) index = i;
    return marks[index];
}
int highestMarkCopy(const int marks[], int n) {
    int best = marks[0];
    for (int i = 1; i < n; ++i) best = max(best, marks[i]);
    return best;
}
// Deliberately unsafe example (DO NOT call): returning a reference to a local is UB.
// int& dangling() { int local = 42; return local; }

int main() {
    int marks[] = {78, 91, 85, 88, 90};
    cout << "Highest before moderation: " << highestMark(marks, 5) << '\n';
    highestMark(marks, 5) += 2;
    cout << "Highest after +2: " << highestMarkReadOnly(marks, 5) << '\n';
    cout << "Returned copy: " << highestMarkCopy(marks, 5) << '\n';
    cout << "Array: "; for (int m : marks) cout << m << ' '; cout << '\n';
}
