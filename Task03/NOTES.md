## Pseudocode
1. Define a grams overload accepting int.
2. Define a kilograms overload accepting double with trailing default flags.
3. Define a Parcel overload accepting a const reference.
4. Call each overload with six argument forms and label the selected overload.

**Complexity:** overload resolution is compile-time work, with no run-time dispatch cost for these non-virtual functions. Each calculation is O(1) time. Parcel by const reference avoids copying its fields.
