# Class design sketches

```text
SavingsAccount
-------------------------------
- accountNumber : long long
- balance : double
- transactions : double[10]
- count : int
-------------------------------
+ deposit(amount)
+ withdraw(amount) : bool
+ miniStatement() const
- record(amount)
```

```text
BusTicket
-------------------------------
- issued : static int
- CAPACITY : static const int
- seat : int
- name : string
-------------------------------
+ BusTicket(name)
+ count() : static int
+ print() const
```

```text
Time
-------------------------------
- h : int
- m : int
-------------------------------
+ Time(hh, mm)
friend minutesBetween(a,b)
friend earlier(a,b)
```

Q7 circular history uses `data[capacity]`, `next`, and `count`; it is an internal fixed-capacity data structure rather than a domain entity.
