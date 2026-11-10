#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using Clock = chrono::steady_clock;

class ShiftHistory {
    vector<int> data; size_t cap; long long moves = 0;
public:
    explicit ShiftHistory(size_t c) : cap(c) { data.reserve(c); }
    void add(int value) {
        if (data.size() < cap) data.push_back(value);
        else { for (size_t i=1; i<cap; ++i) { data[i-1]=data[i]; ++moves; } data[cap-1]=value; }
    }
    const vector<int>& values() const { return data; }
    long long operations() const { return moves; }
};
class CircularHistory {
    vector<int> data; size_t cap, next=0, count=0; long long writes=0;
public:
    explicit CircularHistory(size_t c) : data(c), cap(c) {}
    void add(int value) { data[next]=value; next=(next+1)%cap; if(count<cap) ++count; ++writes; }
    vector<int> ordered() const {
        vector<int> out; out.reserve(count);
        size_t start = (count==cap ? next : 0);
        for(size_t i=0;i<count;++i) out.push_back(data[(start+i)%cap]);
        return out;
    }
    long long operations() const { return writes; }
};
int main() {
    const size_t capacity=50; const int n=2000000;
    ShiftHistory oldDesign(capacity); CircularHistory newDesign(capacity);
    auto a=Clock::now(); for(int i=0;i<n;++i) oldDesign.add(i); auto b=Clock::now();
    for(int i=0;i<n;++i) newDesign.add(i); auto c=Clock::now();
    auto oldUs=chrono::duration_cast<chrono::microseconds>(b-a).count();
    auto newUs=chrono::duration_cast<chrono::microseconds>(c-b).count();
    auto oldValues=oldDesign.values(); auto newValues=newDesign.ordered();
    bool same=oldValues==newValues;
    cout << "Entries processed: " << n << "\nCapacity: " << capacity << '\n';
    cout << "Shift design element moves: " << oldDesign.operations() << '\n';
    cout << "Circular design writes: " << newDesign.operations() << '\n';
    cout << "Last-value sequence identical: " << boolalpha << same << '\n';
    cout << "Shift elapsed microseconds: " << oldUs << '\n';
    cout << "Circular elapsed microseconds: " << newUs << '\n';
    cout << "Expected shift moves after full: (n-capacity)*(capacity-1) = "
         << (long long)(n-capacity)*(capacity-1) << '\n';
}
