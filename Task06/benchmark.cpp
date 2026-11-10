#include <iostream>
#include <chrono>
using namespace std;
inline int inlineWork(int x) { return x * 3 + 1; }
#if defined(__GNUC__)
__attribute__((noinline))
#endif
int ordinaryWork(int x) { return x * 3 + 1; }
int main(){ constexpr int N=10000000; volatile long long sum=0; auto a=chrono::steady_clock::now(); for(int i=0;i<N;++i) sum+=inlineWork(i); auto b=chrono::steady_clock::now(); for(int i=0;i<N;++i) sum+=ordinaryWork(i); auto c=chrono::steady_clock::now(); cout<<"Calls per version: "<<N<<"\nInline microseconds: "<<chrono::duration_cast<chrono::microseconds>(b-a).count()<<"\nOrdinary microseconds: "<<chrono::duration_cast<chrono::microseconds>(c-b).count()<<"\nChecksum: "<<sum<<"\n";}
