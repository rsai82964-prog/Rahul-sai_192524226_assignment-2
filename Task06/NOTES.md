## Pseudocode
1. Convert each Time to minutes after midnight.
2. minutesBetween returns the absolute difference of the two minute values.
3. earlier compares the minute values and returns true only when the first is smaller.
4. Test before/after noon and equal times.
5. Benchmark ten million calls at -O0 and -O2, comparing inline and non-inline candidates.

**Complexity:** both friend operations are O(1) time and O(1) extra space. `inline` permits multiple definitions and suggests inlining; it does not force machine-code substitution. Optimisation level and compiler decisions dominate measured timings.
