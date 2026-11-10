# DSA01-RegisterNumber-Assignment2

**Student name:** [Enter your full name]  
**Register number:** [Enter your register number]  
**Course:** CO2 – C++ Functions and Object-Oriented Concepts  
**Assignment:** 2 (50 marks)  
**Submission date in PDF:** 31/10/2026

## Compiler and build information
- Compiler used in this environment: GNU g++ 14.2.0
- Language standard: C++17
- Build flags: `-std=c++17 -Wall -Wextra -Wconversion`
- Example: `g++ -std=c++17 -Wall -Wextra -Wconversion Task01/main.cpp -o Task01/program`
- Run: `./Task01/program` (Windows MinGW: `Task01\program.exe`)

## Repository structure
- `Task01/` – call by value/reference/pointer, return by reference, defaults and concession TODO
- `Task02/` – highest-mark reference, const reference, copy and dangling-reference diagnostic
- `Task03/` – courier overload design, six calls and ambiguous-original diagnostic
- `Task04/` – SavingsAccount with private ten-entry transaction array
- `Task05/` – static token counter, BusTicket array and completed TODOs
- `Task06/` – friend/inline Time functions, correctness tests and -O0/-O2 benchmark
- `Task07/` – shift-history baseline versus circular-buffer redesign and measurements
- `REPORT.md` – full assignment report for Q1–Q7
- `UML.md` – class design sketches

Each task folder contains source code, `compile.txt`, `output.txt`, and a terminal-style PNG output capture where applicable. Diagnostic files intentionally demonstrate the invalid original designs; they are not part of the successful build.

## How to build and run all main programs
From the repository root on Linux/macOS:
```bash
for d in Task{01..07}; do
  g++ -std=c++17 -Wall -Wextra -Wconversion "$d/main.cpp" -o "$d/program" || exit 1
  "$d/program"
done
```
For one task, replace `Task01` with the required folder.

## Task summaries
| Task | Result |
|---|---|
| Q1 | Value leaves caller unchanged; reference and pointer modify caller. Reference-return assignment modifies selected variable. |
| Q2 | Highest array element is modified through `int&`; unsafe local reference is documented and warning captured. |
| Q3 | Ambiguous overload set is diagnosed; redesigned overloads select deterministically for all six calls. |
| Q4 | Encapsulated account retains latest ten transactions using shift-on-full policy. |
| Q5 | Static counters are shared; three seats issued and additional tickets wait. |
| Q6 | Friend functions correctly compare times; same-time and noon-boundary tests included. |
| Q7 | Circular history preserves the same last 50 values with O(1) insertion versus O(k) shifting. |

## Git workflow
The intended history is progressive: one commit for each Q1–Q7, plus initial documentation. To publish this local repository, create a GitHub repository named `DSA01-<RegisterNumber>-Assignment2`, then run:
```bash
git remote add origin https://github.com/<username>/DSA01-<RegisterNumber>-Assignment2.git
git branch -M main
git push -u origin main
```
Add faculty as collaborator if private. Put the working GitHub URL on the report cover and submit the URL plus report through Google Classroom.

## Before submission
Replace the name/register placeholders, verify all output screenshots on your own machine, publish the repository, add the real URL to the report cover, and upload the report and link to Google Classroom.
