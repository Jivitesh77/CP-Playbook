# Prefix Sums & Difference Arrays — Problem Set

Eight original problems. Same rules: 45 minutes each, spoilers at the bottom.

## The one idea

These are two halves of one trick, and seeing them as a pair is worth more than any
individual problem here:

> **Prefix sums** turn a *property of a range* into a *relation between two points*.
> **Difference arrays** turn an *update to a range* into an *update to two points*.

Range query becomes `p[r] - p[l-1]`. Range update becomes `d[l] += v; d[r+1] -= v`.
They are inverses of each other — a prefix sum of a difference array gives you the original
array back. Once that clicks, the whole topic is just recognising which side you're on:
many queries and no updates → prefix sums. Many updates and one final read → difference array.
(Many of both, interleaved → you need a Fenwick or segment tree, which is the next topic up.)

The second thing to internalise: prefix sums work for **any invertible associative
operation**, not just addition. XOR works. Multiplication mod a prime works. Min does *not*
— you can't undo a min, which is exactly why sparse tables and segment trees exist.

---

## 1. Repeated Neighbours — ~1200

You are given a string `s` of length `n` and `q` queries. Query `(l, r)` asks: how many
indices `i` with `l ≤ i < r` satisfy `s_i = s_{i+1}`?

**Constraints:** `1 ≤ n, q ≤ 2·10^5`, `1 ≤ l < r ≤ n`, lowercase letters.

**Sample input**
```
6 2
aabbaa
1 6
2 4
```

**Sample output**
```
3
1
```

---

## 2. Balanced Stretch — ~1500

An array of `n` values, each `0` or `1`. Find the length of the longest contiguous subarray
containing exactly as many `0`s as `1`s. Print `0` if none exists.

**Constraints:** `1 ≤ n ≤ 2·10^5`.

**Sample input**
```
6
0 1 0 0 1 1
```

**Sample output**
```
6
```

---

## 3. Divisible Subarrays — ~1600

Given an array of `n` integers (which may be negative) and an integer `m`, count the number
of non-empty contiguous subarrays whose sum is divisible by `m`.

**Constraints:** `1 ≤ n ≤ 2·10^5`, `1 ≤ m ≤ 10^5`, `-10^9 ≤ a_i ≤ 10^9`.

**Sample input**
```
3 3
1 2 3
```

**Sample output**
```
3
```

The subarrays are `[1,2]`, `[3]`, and `[1,2,3]`.

---

## 4. Clear Ground — ~1500

An `n × m` grid where `1` marks an obstacle and `0` marks clear ground. Count the number of
`k × k` axis-aligned square subgrids containing at most `t` obstacles.

**Constraints:** `1 ≤ k ≤ n, m ≤ 1000`, `0 ≤ t ≤ 10^6`.

**Input**
```
n m k t
n lines of m characters
```

**Sample input**
```
3 3 2 1
100
010
001
```

**Sample output**
```
2
```

---

## 5. Booking Ledger — ~1400

A hall is tracked over `n` days, all starting at load `0`. You process `q` bookings; booking
`j` adds `v_j` to the load of every day in `[l_j, r_j]`.

Print the final load of each day.

**Constraints:** `1 ≤ n, q ≤ 2·10^5`, `1 ≤ v_j ≤ 10^9`.

**Sample input**
```
5 2
1 3 2
2 5 3
```

**Sample output**
```
2 5 5 3 3
```

---

## 6. Peak Coverage — ~1600

You are given `n` closed intervals `[l_i, r_i]` on the integer line. Find the maximum number
of intervals that contain a single common point.

**Constraints:** `1 ≤ n ≤ 2·10^5`, `1 ≤ l_i ≤ r_i ≤ 10^9`.

**Sample input**
```
5
1 5
2 3
4 8
3 4
10 12
```

**Sample output**
```
3
```

---

## 7. Stamps — ~1700

An `n × m` grid, all cells starting at `0`. You apply `q` stamps; stamp `j` adds `1` to every
cell in the rectangle with corners `(r1_j, c1_j)` and `(r2_j, c2_j)` inclusive.

Print how many cells end with a value of at least `k`.

**Constraints:** `1 ≤ n, m ≤ 2000`, `1 ≤ q ≤ 2·10^5`, `1 ≤ k ≤ q`.

**Input**
```
n m q k
r1 c1 r2 c2      (q lines)
```

**Sample input**
```
3 3 2 2
1 1 2 2
2 2 3 3
```

**Sample output**
```
1
```

---

## 8. Enough Supply — ~1800

There are `n` stores. Store `i` must end up with at least `d_i` units of stock; all start at `0`.

There are `q` supply operations, and they are applied **in the given order**. Operation `j` is
`(l_j, r_j, v_j)` and adds `v_j` units to every store in `[l_j, r_j]`.

Find the smallest `k` such that after applying only the first `k` operations, every store
meets its demand. Print `k`, or `-1` if even all `q` operations are not enough.

**Constraints:** `1 ≤ n, q ≤ 2·10^5`, `1 ≤ d_i, v_j ≤ 10^9`.

**Sample input**
```
3 3
2 2 2
1 2 1
2 3 2
1 3 1
```

**Sample output**
```
3
```

---
---

# SPOILERS

**1. Repeated Neighbours.** Prefix sum over an **indicator array**, not over the values. Build
`b_i = 1` if `s_i = s_{i+1}` else `0`, for `i` in `1..n-1`, then prefix-sum `b`. The answer is
`p[r-1] - p[l-1]`. The entire difficulty is the off-by-one: a query about `r` *characters*
is a query about `r-1` *adjacent pairs*. Write down explicitly what index `i` of your derived
array means before you touch the prefix formula. Most WAs on this whole topic are this bug.

**2. Balanced Stretch.** The transform is the trick: map `0 → -1` and `1 → +1`. Now "equal
counts" becomes "sum is zero", which becomes `p[j] = p[i]`. Walk the prefix array keeping a
hashmap of the **first** index at which each prefix value occurred; for each `j`, if `p[j]`
was seen before at `i`, candidate length is `j - i`. Store first occurrence only — you want
the longest, so never overwrite. Seed the map with `p = 0` at index `0`, which is the case
people forget and which is exactly what makes the sample answer 6 rather than 4.

**3. Divisible Subarrays.** Sum of `a[i+1..j]` divisible by `m` means `p[j] ≡ p[i] (mod m)`.
Count occurrences of each residue among `p[0..n]`, then add `C(c, 2)` for each residue class.
Two traps: include `p[0] = 0` in the counting, and handle negatives with
`((p % m) + m) % m` — C++'s `%` returns a negative remainder for negative operands and this
silently produces wrong residues. Answer needs 64-bit.

**4. Clear Ground.** Standard 2D prefix sum. Build `P[i][j]` = obstacles in the rectangle
`(1,1)..(i,j)` via `P[i][j] = a[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]`, then a
submatrix `(r1,c1)..(r2,c2)` costs `P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1]`.
Inclusion–exclusion in both directions. Use 1-indexed arrays with a zero row and column —
almost every 2D-prefix bug is a 0-indexed boundary check that should have been unnecessary.

**5. Booking Ledger.** The canonical difference array. `d[l] += v`, `d[r+1] -= v`, then
prefix-sum `d` at the end. Allocate `n+2` so `d[r+1]` is always safe when `r = n`. `O(n + q)`
instead of `O(nq)`.

**6. Peak Coverage.** A difference array where the coordinates are too large to index. Two
equivalent routes: **coordinate-compress** the endpoints and run a normal difference array
over the compressed axis, or **sweep the events** — emit `(l, +1)` and `(r+1, -1)`, sort by
coordinate, and take a running maximum. The `r+1` matters because intervals are closed;
with `(r, -1)` you'd break ties wrongly and undercount at the right endpoint. Sorting with
`+1` before `-1` at equal coordinates is the equivalent fix if you use `r`. Pick one
convention and write it in your template.

**7. Stamps.** 2D difference array (sometimes called the imos method). Each stamp is four
point updates:
```
d[r1][c1] += 1;  d[r1][c2+1] -= 1;  d[r2+1][c1] -= 1;  d[r2+1][c2+1] += 1;
```
Then take a 2D prefix sum of `d` to materialise the grid and count. `O(nm + q)`. The four
corners are the exact dual of the four-term inclusion–exclusion query in problem 4 — that
symmetry is the point of putting these two problems in the same set. Allocate `(n+2) × (m+2)`.

**8. Enough Supply.** Two techniques stacked, and this pairing is extremely common in Div. 2 D:
the predicate "the first `k` operations suffice" is **monotone** in `k` (more operations only
ever add stock, since all `v_j > 0`), so binary search `k`, and check a candidate in `O(n + k)`
by replaying the first `k` operations into a fresh difference array and comparing against `d_i`.
Total `O((n + q) log q)`. Note the monotonicity argument is load-bearing — if `v_j` could be
negative, binary search would be invalid and the problem would be genuinely harder. Whenever
you binary search an answer, say out loud why the predicate is monotone before you code it.

## Recognising these in the wild

The tell for a difference array is a problem with **many range updates and a single read at
the end**, or one that can be reordered into that shape. The tell for prefix sums is **many
range queries with no updates**. If updates and queries interleave, neither works and you
need a Fenwick tree — that's your next topic, and it will feel easy because it is exactly
these two ideas made online.

The tell for the *transform* trick (problem 2) is any problem asking for a range where two
things are **equal**, or where a count **balances**. Turn the condition into "a sum equals
zero" and you've turned an `O(n^2)` scan into an `O(n)` hashmap walk.
