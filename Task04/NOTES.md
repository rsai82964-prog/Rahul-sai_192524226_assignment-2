## Pseudocode
1. Keep account number, balance, ten transaction values and count private.
2. On deposit, reject non-positive values, update balance and record the transaction.
3. On withdrawal, reject non-positive or unaffordable values; otherwise update balance and record a negative transaction.
4. If fewer than ten entries exist, append. Otherwise shift entries left and place the newest at the end.
5. Print balance and the retained transactions.

**Complexity:** deposit/withdraw record is O(1) until full and O(k) when shifting k=10 entries; mini-statement is O(k). Space is O(k), here k=10. A circular buffer makes insertion O(1) but requires start/count index management.
