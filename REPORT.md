# ASSIGNMENT 2 – CO2
## C++ Functions and Object-Oriented Concepts

**Student name:** [Enter your full name]  
**Register number:** [Enter your register number]  
**GitHub repository:** https://github.com/[username]/DSA01-[RegisterNumber]-Assignment2  
**Compiler:** GNU g++ 14.2.0, C++17  
**Build flags:** `-std=c++17 -Wall -Wextra -Wconversion`

> Replace the identity and GitHub placeholders before submission. The recorded timings are machine- and compiler-dependent; rerun them on the submission computer and retain its evidence.

## Q1 – Call by Value, Reference and Pointer (6 marks)

### Concept and design
- **Value:** `a` is a local copy. Changes to it do not change the caller's variable.
- **Reference:** `int& b` aliases the caller's object, so `b += 10` changes the original.
- **Pointer:** `int* c` stores an address; `*c += 10` changes the pointed-to object. The pointer must be valid and non-null before dereferencing.
- **Return by reference:** `bigger(a,c)` returns an lvalue reference to the larger argument, so it can appear on the left side of assignment. Both arguments must outlive the returned reference.
- **Default arguments:** `show(1)` uses y=5 and z=10; `show(1,2)` uses z=10; `show(1,2,3)` supplies all arguments.
- Use `const T&` when a function needs to read a potentially large object without copying and must not modify it.

### Predicted output (manual trace)
```text
1 12 13
1 100
16 13 6
after call by value : 45000
after call by reference: 40500
```

### Implementation and observed output
`Task01/main.cpp` includes the given prediction program and the completed concession function. The caller fee remains 45000 after call-by-value; reference-based 10% concession reduces it to 40500. The actual run matches the prediction.
```text
1 12 13
1 100
16 13 6
after call by value : 45000
after call by reference: 40500
```

### Concession interface decision
For a single concession, returning a new fee is often easiest to test and avoids hidden mutation: `long long applyConcession(long long fee, int percent)`. For a sequence of concessions, either repeatedly assign returned values or deliberately mutate a `long long&`. This implementation uses a reference because the TODO explicitly asks to change the caller's fee. Calculate in integer paise/currency subunits to avoid floating-point money errors.

### Complexity
All three parameter passing forms and the concession arithmetic are O(1) time. For a `long long`, copying is constant-sized; passing a large `Student` by value copies O(size of Student) data, while reference/const-reference avoids that copy. Auxiliary space is O(1).

## Q2 – Return by Reference and Its Dangers (4 marks)

### Design and result
`highestMark(int[], int)` scans the array and returns a reference to its maximum element. The caller can write `highestMark(marks, 5) += 2;`, directly updating the original array. `highestMarkReadOnly` returns `const int&` to prevent modification; `highestMarkCopy` returns an independent value.

Observed output:
```text
Highest before moderation: 91
Highest after +2: 93
Returned copy: 93
Array: 78 93 85 88 90
```

### Dangling reference warning
`dangling_reference_warning.cpp` deliberately contains `int& dangling(){ int local=42; return local; }` and is compiled separately with `-Wreturn-local-addr`. The compiler diagnostic is saved in `diagnostic.txt`. A local automatic variable ceases to exist when the function returns; using its former reference is undefined behaviour. The unsafe function is never executed.

### Vector growth condition
A `std::vector` may reallocate when capacity is exceeded. Reallocation moves elements to a new allocation and invalidates references, pointers and iterators to its old elements. An index is often more robust across reallocation, provided it is revalidated after erase/insert operations. A pointer has similar invalidation risk to a reference.

### Alternative and complexity
Finding the maximum is O(n) time and O(1) extra space whether the result is an index, pointer or reference. Using an index: `int i=maxIndex(v); v[i]+=2;`; using a pointer: `int* p=maxAddress(a,n); *p+=2;`. Index avoids retaining a raw address across vector growth but still may identify a different logical item after insertion/erase. Reference is convenient for fixed arrays; copy is safest when only the value is needed.

## Q3 – Default Arguments and Function Overloading (6 marks)

### Why the original is ambiguous
The provided overloads `charge(double)`, `charge(double,bool)` and `charge(double,bool=false,bool=false)` can all accept a one-argument call. Default arguments make multiple candidates viable, so `charge(2.0)` is ambiguous. The original diagnostic source and compiler output are saved in `Task03/`.

### Redesigned overload set
- `charge(int grams)` handles integer grams.
- `charge(double kg, bool express=false, bool insured=false)` handles kilogram input and optional services. Defaults are trailing because a missing argument can only be supplied from the right.
- `charge(const Parcel&)` handles a parcel record.

The six call predictions and observed selections are:
| Call | Selected overload | Reason | Actual charge |
|---|---|---|---:|
| `charge(2)` | `int` | exact match | 30.04 |
| `charge(2.0f)` | `double` | float-to-double promotion | 90.00 |
| `charge(2.0)` | `double` | exact match | 90.00 |
| `charge(500)` | `int` | exact match | 40.00 |
| `charge(1.5,true)` | `double` | third argument defaults to false | 97.50 |
| `charge(parcel)` | `Parcel const&` | exact class match | 125.00 |

Observed output labels each chosen overload. Exact match is preferred over promotion, which is preferred over standard conversion. A function template or one `Parcel` structure with optional fields could consolidate options, but may make simple calls more verbose. Overload selection is compile-time; each charge calculation is O(1) time. Passing `Parcel` by const reference avoids a copy.

## Q4 – Specifying a Class with an Array Inside It (6 marks)

### Class design
`SavingsAccount` keeps account number, balance, transaction array and count private. Public methods provide deposit, withdraw and mini-statement. `miniStatement()` is declared inside the class and defined outside using `SavingsAccount::miniStatement()`. The helper `record()` is private. The array is private so external code cannot corrupt the transaction history or bypass balance rules.

### Observed test
The program performs deposits and withdrawals, then adds enough entries to exceed ten. The oldest entries are discarded by shifting the remaining nine values left. Output:
```text
Account: 20261001 | Balance: Rs 1290.00
Last 10 transactions: -10.00 +5.00 +10.00 +15.00 +20.00 +25.00 +30.00 +35.00 +40.00 +45.00
```

### Shift versus circular buffer
For k=10, shifting the array on every full-buffer insertion moves k-1 values, O(k); circular insertion writes one value and advances a modulo index, O(1). Both use O(k) memory. If the requirement grows to 50, only the capacity and associated indexing need to change, but a circular buffer scales better for frequent updates. A `std::deque` also supports push-back/pop-front efficiently, but the assignment asks that the underlying problem and design be understood rather than merely replacing it with a library container.

## Q5 – Static Members and Arrays of Objects (7 marks)

### Static token prediction
`Token::next` is initialized once to 100. Constructing `counter[3]` invokes three constructors, then `extra` invokes one more. IDs are 101, 102, 103 and 104; `issued()` returns next-100 = 4.

Predicted and observed first line:
```text
101 103 104 4
```

### Completed BusTicket code
TODO 1 checks `issued < CAPACITY`, increments the shared counter and assigns the seat. Otherwise seat remains zero and the object is on the waiting list. TODO 2 returns the static `issued` count. The static data member is defined once outside the class: `int BusTicket::issued = 0;`.

Observed output:
```text
101 103 104 4
Asha: Seat 1
Bala: Seat 2
Chitra: Seat 3
Dev: Waiting
Issued: 3
Esha: Waiting
Farhan: Waiting
Esha: Waiting
Farhan: Waiting
Issued after second function call: 3
```

Calling the function twice does not reset the static counter. The capacity is already full, so all later tickets wait and issued remains three. A static member function has no `this` pointer and cannot directly access non-static fields because it is not operating on one particular object.

### Alternative
A global counter has O(1) time and O(1) storage but weakens encapsulation and risks name collisions. A `TicketOffice` object passed into each ticket constructor also has O(1) operations/storage and allows two buses to maintain separate capacities and counters. Static state is suitable only when all tickets belong to one shared bus office.

## Q6 – Friend Functions and Inline Functions (8 marks)

### Design and correctness
`Time` stores hours and minutes privately. `minutesBetween` and `earlier` are friend functions because they compare two peer objects symmetrically and need direct access to both objects' private fields. They are called as ordinary functions, not through one object. `minutesBetween` converts both times to minutes after midnight and returns the absolute difference. `earlier` compares the converted values.

The required TODO output is:
```text
205 false
```
Additional tests output:
```text
15 true
0 false
```
These verify a pair across noon and equal times.

### Friend versus member/getters
A member alternative would read naturally as `departure.minutesTo(arrival)` and `departure.isEarlier(arrival)`. Public getters preserve private data but add accessor calls (normally optimised/inlined). Friend functions keep the comparison symmetric and do not expose all fields publicly, but grant the functions privileged access. Making fields public would weaken invariants and permit invalid hours/minutes.

### Inline timing experiment
`benchmark.cpp` runs 10,000,000 calls to an inline candidate and a noinline candidate. It is compiled separately with `-O0` and `-O2`; raw measurements are in `benchmark_O0_output.txt` and `benchmark_O2_output.txt`. On this run, `-O0` measured 20,905 µs for the inline candidate and 17,275 µs for the ordinary function; `-O2` measured 4,431 µs and 20,218 µs respectively. The slower inline result at `-O0` shows that the keyword alone does not guarantee a speedup. Timings vary by CPU, load and compiler. At `-O2`, the optimizer may inline or transform code even when the source is not marked inline; compare repeated runs before drawing a performance conclusion. `inline` is not a command that guarantees substitution. Both operations are O(1) time and O(1) extra space.

## Q7 – Diagnose, Redesign and Validate (13 marks)

### A. Diagnosis
The shift-on-full transaction history is simple and correct, but once capacity k is reached, every new transaction copies k-1 retained entries. With k=50 and n=2,000,000 insertions, expected element moves are `(n-k)*(k-1) = 97,997,550`. This repeated work is the design limitation.

### B. Measurable objective
For identical input, retain exactly the most recent 50 values in chronological order, while reducing the insertion work from O(k) moves per full-buffer insertion to one O(1) write per insertion.

### C. Revised design
The redesigned `CircularHistory` allocates 50 slots once and tracks `next` and `count`. Each insertion writes at `next`, advances `(next+1)%capacity`, and caps count at capacity. Chronological output starts at `next` once full. Extra memory remains O(k), with two indices; no per-insert allocation is required.

### D. Prediction before implementation
For two million inserts and capacity 50, predicted baseline moves: 97,997,550. Predicted circular writes: 2,000,000. Both should return identical final 50 values.

### E. Implementation and validation
The same increasing sequence from 0 to 1,999,999 was fed to both implementations. Observed operation counts were 97,997,550 shift moves and 2,000,000 circular writes. The final-value comparison returned `true`. On this run, the shift implementation took about 439,743 microseconds and the circular implementation about 14,671 microseconds; treat these as one environment's measurements, not universal guarantees.

### F. Defence
The objective was achieved: identical retained values with substantially fewer writes and lower observed elapsed time. The circular design requires careful wrap-around and chronological-order logic, so the simpler shift design can still be preferable for very small histories or rare updates. Both use O(k) memory; baseline insertion is O(k) after full, circular insertion O(1), and printing the retained history O(k).

## Overall conclusion
The assignment demonstrates how C++ parameter passing, references, overload resolution, encapsulation, arrays, static members, friend functions and inline functions affect correctness and maintainability. The final redesign is justified by equivalent output and measured reduction in data movement. Before submission, rerun all builds on the college environment, inspect warning files, replace personal placeholders, publish the repository and attach the live link.
