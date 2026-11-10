## Pseudocode
1. Choose the fixed-size transaction history as the target design.
2. Baseline: once full, shift all retained entries left for each new value.
3. Redesign: write the new value at the next circular index, advance modulo capacity, and track count.
4. Feed both designs the same two million sequential values at capacity 50.
5. Compare retained values, element moves/writes and elapsed time.
6. Accept the redesign only if output equivalence is preserved and the work reduction is demonstrated.

**Complexity:** shift design has O(k) insertion after full and O(k) retained storage. Circular design has O(1) insertion and O(k) storage; producing chronological output costs O(k). For n insertions after filling, shifting performs (n-k)(k-1) moves, while the circular design performs n writes.
