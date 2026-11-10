## Pseudocode
1. Initialize three integer variables a, b, c.
2. Call change(a, b, address of c): modify local copy a, caller b, and pointed-to c.
3. Assign 100 through the reference returned by bigger(a,c).
4. Call show with one, two, then three arguments to exercise defaults.
5. Compare fee passed by value with fee passed by reference.

**Complexity:** each call performs a fixed number of arithmetic operations: O(1) time and O(1) auxiliary space. A large object passed by value copies its full object size; reference and const-reference parameters pass an alias without copying the object.
