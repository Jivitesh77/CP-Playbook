# Brute Force & Complete Search — Problem Set

Eight original problems. Same rules as the simulation set: 45 minutes per problem,
spoilers at the bottom, don't scroll early.

Simulation had three failure modes. Brute force has essentially **one**, asked over and over:
*what exactly are you enumerating, and how do you know it's small enough?* Every problem here
is a different answer to that question.

---

## The constraint table

Read this once. It is most of the topic. In a contest, the constraint is the setter telling
you the intended complexity — if you can't name the enumeration a constraint permits, you
haven't finished reading the problem.

| Constraint | What fits | What you're enumerating |
|---|---|---|
| `n ≤ 10` | `n!` ≈ 3.6M | orderings / permutations |
| `n ≤ 20` | `2^n` ≈ 1M | subsets, bitmasks |
| `n ≤ 24` | `2^n` ≈ 17M | subsets, tight |
| `n ≤ 40` | `2^(n/2)` | meet in the middle |
| `n ≤ 100` | `n^4` | 4 nested loops / all quadruples |
| `n ≤ 500` | `n^3` | all triples |
| `n ≤ 5000` | `n^2` | all pairs |
| `a_i ≤ 10^6` | `V log V` | the *value* space, not the index space |
| `n ≤ 10^12` | `√n` or `n^(1/3)` | divisors |

The last two rows are where most people lose problems, because the enumerable set isn't the
input array at all.

---

## 1. Hiring Panel — ~1300

You are hiring from `n` candidates to cover `m` required skills. Candidate `i` costs `c_i`
and knows a given subset of the skills.

Choose a set of candidates such that every one of the `m` skills is known by at least one
chosen candidate. Print the minimum total cost, or `-1` if it's impossible.

**Constraints:** `1 ≤ n ≤ 20`, `1 ≤ m ≤ 60`, `1 ≤ c_i ≤ 10^9`.

**Input**
```
n m
c_i followed by a string of m characters ('1' = knows that skill)   (n lines)
```

**Sample input**
```
3 3
5 110
4 011
6 111
```

**Sample output**
```
6
```

Candidates 1 and 2 together cover everything for `9`; candidate 3 alone covers everything
for `6`.

---

## 2. Round Table — ~1400

`n` people sit around a circular table. You are given a matrix where `d[i][j]` is the
discomfort caused when person `i` sits **immediately to the left of** person `j`.

The total discomfort of a seating is the sum of `d[i][j]` over every adjacent ordered pair
going clockwise around the full circle. Find the minimum possible total discomfort.

**Constraints:** `3 ≤ n ≤ 10`, `0 ≤ d[i][j] ≤ 10^6`, `d[i][i] = 0`.

**Sample input**
```
3
0 1 5
5 0 1
1 5 0
```

**Sample output**
```
3
```

Seating `1 → 2 → 3 → 1` costs `1 + 1 + 1`.

---

## 3. Exactly Three — ~1500

You have `n` items; item `i` costs `c_i` and has value `v_i`. You must buy **exactly three
distinct items** with total cost at most `B`. Maximise the total value, or print `-1` if no
valid choice exists.

**Constraints:** `3 ≤ n ≤ 2000`, `1 ≤ B ≤ 10^9`, `1 ≤ c_i, v_i ≤ 10^9`.

**Sample input**
```
4 10
1 1
2 5
3 4
8 10
```
(each line after the first is `c_i v_i`)

**Sample output**
```
10
```

---

## 4. Three Factors — ~1500

Given `n`, find positive integers `a ≤ b ≤ c` with `a · b · c = n` minimising `a + b + c`.
Print that minimum sum.

**Constraints:** `1 ≤ n ≤ 10^12`.

**Sample input**
```
12
```

**Sample output**
```
7
```

`2 · 2 · 3 = 12`.

---

## 5. Two Bags — ~1800

You have `n` items with weights `w_1 ... w_n`. Split **all** of them into two groups (either
may be empty) so that the absolute difference of the two group sums is as small as possible.
Print that difference.

**Constraints:** `1 ≤ n ≤ 40`, `1 ≤ w_i ≤ 10^9`.

**Sample input**
```
4
3 1 4 2
```

**Sample output**
```
0
```

---

## 6. Equal Piles — ~1700

You have `n` sticks with integer lengths. Partition **all** of them into exactly `k`
non-empty groups such that every group has the same total length. Print `YES` or `NO`.

**Constraints:** `1 ≤ k ≤ n ≤ 20`, `1 ≤ length_i ≤ 10^8`.

**Sample input**
```
5 4
1 1 2 2 2
```

**Sample output**
```
YES
```

Groups: `{2}`, `{2}`, `{2}`, `{1,1}`.

---

## 7. Two Tiers — ~1700

You are selling a premium item and a basic item. You choose two integer prices
`P1 > P2 ≥ 1`.

There are `n` customers; customer `i` has budget `a_i`. Each customer, independently:
buys the premium item at price `P1` if `a_i ≥ P1`; otherwise buys the basic item at price
`P2` if `a_i ≥ P2`; otherwise buys nothing.

Choose `P1` and `P2` to maximise total revenue. Print the maximum revenue.

**Constraints:** `2 ≤ n ≤ 2000`, `1 ≤ a_i ≤ 10^9`.

**Sample input**
```
4
1 3 5 7
```

**Sample output**
```
13
```

---

## 8. Three by N — ~1600

Count the number of ways to tile a `3 × n` rectangle completely with `1 × 2` dominoes
(each domino placed horizontally or vertically, no overlaps, no gaps). Print the count
modulo `10^9 + 7`.

**Constraints:** `1 ≤ n ≤ 10^18`.

**Sample input**
```
4
```

**Sample output**
```
11
```

This one has an intended *workflow*, not just an intended solution. See the spoiler.

---
---

# SPOILERS — what each problem is actually testing

**1. Hiring Panel.** The trap is choosing the wrong dimension. `m ≤ 60` is far too large to
enumerate skill subsets; `n ≤ 20` is exactly the invitation to enumerate all `2^20` candidate
subsets, OR the skill sets together, and check against the full mask. `m ≤ 60` also forces a
64-bit mask — a deliberate detail, and a classic source of silent WA. Note that a subset-DP
over skill masks, the "smarter" solution, is impossible here. The setter chose `m = 60`
specifically to close that door.

**2. Round Table.** `n ≤ 10` says permutations. The two things people miss: the table is
circular, so you must **fix person 1's seat** and permute only the other `n-1` (otherwise
you do `n` times redundant work, and `10!` vs `9!` is the difference between comfortable and
tight), and the cost is **directed** — `d[i][j] ≠ d[j][i]`, so a seating and its mirror are
different. `next_permutation` on the tail of the array is the clean implementation.

**3. Exactly Three.** `n = 2000` rules out `n^3`. The lesson is that brute force is often
**partial**: enumerate all `O(n^2)` pairs, then find the best third item with cost
`≤ B - c_i - c_j` in `O(log n)`. Sort items by cost, build a prefix maximum of value, binary
search the cost bound. Handle "the best third item is one of the two already chosen" —
the standard fix is to take a prefix maximum of the top *three* values, or enumerate in
sorted order so indices can't collide.

**4. Three Factors.** The enumerable set is the divisors, not the integers. Since `a ≤ b ≤ c`
and `abc = n`, you get `a ≤ n^(1/3) ≈ 10^4` and then `b ≤ √(n/a)`. Loop `a` from 1 to
`n^(1/3)`, skip if `a ∤ n`, let `n' = n/a`, loop `b` from `a` to `√n'`, skip if `b ∤ n'`,
take `c = n'/b`. Watch the overflow and the `n = 1` case. The general habit: when `n` is
huge but multiplicative structure is involved, the search space is `√n` or `n^(1/3)`, never `n`.

**5. Two Bags.** `n ≤ 40` is the signature of meet in the middle, and essentially nothing
else. `2^40` is hopeless; `2^20` is a million. Split into halves, enumerate all subset sums
of each half (`~10^6` each), sort one list, and for each sum `s` in the other list binary
search for the value closest to `(total - 2s) / 2`... more simply, you want to find `s1 + s2`
closest to `total / 2`, so for each `s1` binary search `total/2 - s1` in the sorted second
list and check the neighbours on both sides. `O(2^(n/2) · n/2)`.

**6. Equal Piles.** Naive backtracking is exponential and will TLE. The pruning **is** the
solution, and each of these matters:
- If `total % k ≠ 0`, or any stick exceeds `total / k`, answer `NO` immediately.
- **Sort descending.** Placing large sticks first fails fast; ascending order explores an
  enormous useless subtree before failing.
- Skip duplicate siblings: if placing stick `i` into an empty group fails, no later group
  will work either — return false, don't try the next empty group.
- If a stick fails in every group, fail the whole branch rather than backtracking one level.

This is the problem that teaches you that "brute force with pruning" is a real technique with
real theory, not just a naive loop with a `break` bolted on.

**7. Two Tiers.** Prices are up to `10^9`, so you cannot enumerate prices — but the optimum
is always attained at a customer's budget. If `P` is not equal to any `a_i`, you can raise it
to the next `a_i` without losing any buyer, strictly increasing revenue. So the candidate set
is `{a_1, ..., a_n}`, and you enumerate `O(n^2)` pairs, computing each revenue in `O(log n)`
by sorting and counting with binary search. The general lesson: when the answer lives in a
continuous or huge space, prove the optimum is attained at a small set of candidates
extracted from the input, then brute force *that*.

**8. Three by N.** The intended workflow is the actual content:

1. Write a genuinely slow brute force (bitmask over column profiles, or plain recursive
   filling) that works for `n ≤ 12`.
2. Print `f(1) ... f(12)`. You get `0, 3, 0, 11, 0, 41, 0, 153, ...`
3. Notice odd `n` gives zero (parity: `3n` must be even), and look for a linear recurrence
   in the even terms. `f(n) = 4·f(n-2) − f(n-4)` fits.
4. Verify it against more brute-force terms. *Then* implement matrix exponentiation for
   `n ≤ 10^18`.

Deriving that recurrence from scratch is real work. Getting it from twelve brute-forced terms
takes ten minutes. Strong contestants do this constantly and it is almost never taught: the
brute force is not the submission, it is the instrument you use to see the pattern.

---

# Appendix: brute force as an oracle

The highest-value use of brute force is not solving problems — it's **checking** your clever
solution. If you're getting WA on a big test and can't see why, stop staring at the code and
build this instead:

```
gen.py     -> prints a small random test to stdout
brute.cpp  -> obviously-correct O(2^n) or O(n^3) solution
fast.cpp   -> your real solution
```

```bash
for i in $(seq 1 10000); do
  python3 gen.py $i > in.txt
  ./brute < in.txt > b.txt
  ./fast  < in.txt > f.txt
  if ! diff -q b.txt f.txt > /dev/null; then echo "FOUND"; cat in.txt; break; fi
done
```

Keep the generator's `n` tiny — 5 to 8 — and values in a small range like 1 to 5. Bugs almost
always reproduce on tiny inputs, and a 6-element counterexample is one you can trace by hand,
which is the entire point. A 200-element counterexample tells you nothing.

Build this once, keep it in your template folder, and it will cost you fifteen minutes now
and save you hours per month. It is also entirely legal in a rated contest — it's your own
code, not outside assistance.
