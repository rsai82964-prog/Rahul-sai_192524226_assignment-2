#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend inline int minutesBetween(const Time& a, const Time& b);
    friend inline bool earlier(const Time& a, const Time& b);
};
inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    return abs(first - second); // TODO 1 completed
}
inline bool earlier(const Time& a, const Time& b) {
    return (a.h * 60 + a.m) < (b.h * 60 + b.m); // TODO 2 completed
}
int main() {
    Time departure(9,45), arrival(13,10);
    cout << minutesBetween(departure, arrival) << ' ' << boolalpha << earlier(arrival, departure) << '\n';
    Time noonBefore(11,55), noonAfter(12,10), same(12,10);
    cout << minutesBetween(noonBefore, noonAfter) << ' ' << earlier(noonBefore, noonAfter) << '\n';
    cout << minutesBetween(same, noonAfter) << ' ' << earlier(same, noonAfter) << '\n';
}
