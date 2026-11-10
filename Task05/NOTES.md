## Pseudocode
1. Store next token ID and number of issued bus seats as static class data.
2. Each Token constructor increments the shared token ID.
3. Each BusTicket constructor checks capacity; issue the next seat or mark the object waiting.
4. Use a static count function to report seats issued without an object.
5. Construct an array larger than capacity and print every ticket.

**Complexity:** construction, seat assignment and count query are O(1) each. An array of m ticket objects occupies O(m) object storage; the shared counter occupies O(1) storage per class, not per object.
