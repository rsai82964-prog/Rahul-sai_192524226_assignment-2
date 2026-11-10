## Pseudocode
1. Start with an array of marks.
2. Scan once to locate the index of the maximum.
3. Return a reference to that array element.
4. Add two through the returned reference.
5. Display the modified array and compare reference, const-reference and copy interfaces.

**Complexity:** finding the maximum is O(n) time and O(1) extra space. Returning an index, pointer or reference after the scan is O(1). A local-variable reference is dangling and using it is undefined behaviour. A vector growth operation may invalidate references if reallocation occurs.
