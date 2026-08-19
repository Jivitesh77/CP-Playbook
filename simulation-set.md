# Simulation & Implementation — Problem Set

Eight original problems, ordered so the *lesson* escalates, not just the difficulty.
Ratings are my estimate of the CF equivalent.

**Rules for yourself:** 45 minutes per problem before you look at anything.
Solutions/ideas are in the last section — don't scroll until you've either solved it or burned the clock.

---

## 1. Vending Machine — ~1300

A machine accepts and dispenses coins of denominations **1, 2, 5, 10**.
It starts holding `c1, c2, c5, c10` coins of each denomination.

You process `n` transactions in order. Transaction `j` has a price `p` and the customer
inserts some coins (`d1, d2, d5, d10` of each denomination) with total value `S ≥ p`.

The machine's procedure is fixed:

1. The inserted coins are added to the machine's stock.
2. The machine must dispense change of exactly `S - p`. It does this **greedily**:
   repeatedly take the largest denomination that is currently in stock and does not
   exceed the remaining change owed, until the change is paid or no such coin exists.
3. If the greedy procedure cannot pay the change exactly, the transaction is **rejected**:
   the inserted coins are removed from stock and returned, and the item is not sold.

Print the final stock `c1 c2 c5 c10` and the number of rejected transactions.

**Constraints:** `1 ≤ n ≤ 2·10^5`, `1 ≤ p ≤ 10^9`, initial counts and inserted counts up to `10^9`.

**Input**
```
c1 c2 c5 c10
n
p d1 d2 d5 d10      (n lines)
```

**Sample input**
```
0 3 1 0
1
4 0 0 2 0
```

**Sample output**
```
0 3 1 0
1
```

Stock before: three 2s and one 5. The customer inserts two 5s, so `S = 10` and the change
owed is `6`. Stock is now three 2s and three 5s. Greedy takes a 5 (owed `1`), then looks for
the largest coin `≤ 1` — there are no 1s in stock, so it is stuck. The transaction is
rejected and the two inserted 5s are returned, restoring the original stock.

Note that `2 + 2 + 2 = 6` would have worked. The machine does not find it, and neither
should your program.

---

## 2. Traffic Lights — ~1300

A straight road from position `0` to position `L`. There are `m` traffic lights at strictly
increasing positions `x_1 < x_2 < ... < x_m`, all in `(0, L)`.

Light `i` is **green during `[0, g_i)`**, **red during `[g_i, g_i + r_i)`**, and repeats with
period `g_i + r_i` forever.

A car starts at position `0` at time `0` and drives forward at exactly 1 unit per second.
It never slows down except at a red light, where it stops instantly and waits until that
light turns green, then resumes instantly.

Output the time at which the car reaches position `L`.

**Constraints:** `1 ≤ m ≤ 2·10^5`, `1 ≤ L ≤ 10^9`, `1 ≤ g_i, r_i ≤ 10^9`.

**Sample input**
```
10 1
5 3 4
```

**Sample output**
```
12
```

The car reaches the light at `t = 5`. Period is `7`, phase is `5`, which is `≥ 3`, so it's red.
It waits until `t = 7`, then drives the remaining `5` units.

Note the boundary: arriving at exactly `t = g_i` means **red**, not green.

---

## 3. Falling Bricks — ~1500

A well `m` columns wide, columns numbered `1..m`, infinitely tall, initially empty.

You drop `n` bricks in order. Each brick is **1 tall and 2 wide** and is dropped so that it
occupies columns `c` and `c+1`. It falls straight down and comes to rest on the lowest row
where both of its cells are free and it is supported (i.e. it rests one row above the highest
occupied cell in either column `c` or `c+1`, or on the floor if both are empty).

Note this can leave a **hole** underneath the shorter side.

After each brick lands, repeatedly: if some row has all `m` cells occupied, that row is
deleted and every cell above it shifts down by one. (Deleting a row may cause another row
to become full.)

After all `n` bricks, print the height of each column, where the height of a column is the
row index of its highest occupied cell (`0` if the column is empty).

**Constraints:** `2 ≤ m ≤ 10`, `1 ≤ n ≤ 10^5`, `1 ≤ c ≤ m-1`.

**Sample input**
```
2 3
1
1
1
```

**Sample output**
```
0 0
```

Each brick fills row 1, row 2, row 3 completely, and each is cleared as it lands.

---

## 4. Robot on a Torus — ~1500

An `R × C` grid. Every cell contains one of `U`, `D`, `L`, `R`. A robot starts at cell
`(1, 1)`. Each second, it reads the arrow in its current cell and moves one step in that
direction. The grid **wraps around** in both directions (moving up from row 1 lands on row `R`).

Where is the robot after exactly `K` seconds?

**Constraints:** `R · C ≤ 2·10^5`, `1 ≤ K ≤ 10^18`.

**Input**
```
R C K
R lines of C characters
```

**Sample input**
```
2 2 1000000000000000000
RD
UL
```

**Sample output**
```
1 1
```

---

## 5. Bit Colony — ~1600

A circular strip of `n` cells, each holding `0` or `1`. Every second, all cells update
**simultaneously**:

```
new[i] = old[i-1] XOR old[i+1]
```

with indices wrapping around (`old[0]` means `old[n]`, `old[n+1]` means `old[1]`).

Print the state after exactly `K` seconds.

**Constraints:** `3 ≤ n ≤ 20`, `1 ≤ K ≤ 10^18`.

**Sample input**
```
5 1000000000000
10000
```

**Sample output**
```
01001
```

---

## 6. Sandpile — ~1600

`n` piles in a row, pile `i` starts with `a_i` grains.

While some pile has `≥ 2` grains: pick any such pile `i`, remove 2 grains from it, and add
1 grain to pile `i-1` and 1 grain to pile `i+1`. Grains added outside the range `[1, n]`
fall off the table and are lost.

The final configuration does not depend on the order of choices. Print it.

**Constraints:** `1 ≤ n ≤ 1000`, `0 ≤ a_i ≤ 10^6`. It is guaranteed the process performs at
most `10^7` topplings in total.

**Sample input**
```
3
0 5 0
```

**Sample output**
```
1 1 1
```

---

## 7. Shuffling Machine — ~1700

`n` cards in a row, card at position `i` is `a_i`. Each second the machine does two things,
in this order:

1. Applies a fixed permutation `p`: the card at position `i` moves to position `p_i`.
2. Rotates the whole row right by one: the card at position `j` moves to position `j+1`,
   and the card at position `n` moves to position `1`.

Print the arrangement after exactly `K` seconds.

**Constraints:** `1 ≤ n ≤ 2·10^5`, `1 ≤ K ≤ 10^18`, `p` is a permutation of `1..n`.

**Sample input**
```
3 5
2 3 1
7 8 9
```

**Sample output**
```
9 7 8
```

---

## 8. Conveyor — ~1700

An array `a_1 ... a_n`. Process `q` operations:

- `R k` — rotate the array **left** by `k` positions.
- `S i v` — set `a_i = v`.
- `Q i` — output the current value of `a_i`.

**Constraints:** `1 ≤ n, q ≤ 2·10^5`, `0 ≤ k ≤ 10^9`, values up to `10^9`.

**Sample input**
```
5 4
1 2 3 4 5
R 2
Q 1
S 4 99
Q 4
```

**Sample output**
```
3
99
```

After `R 2` the array reads `3 4 5 1 2`, so `Q 1` gives `3`. `S 4 99` overwrites the `1`,
and `Q 4` reads it back.

---
---

# SPOILERS — what each problem is actually testing

**Do not read until you have solved or spent the full time-box.**

**1. Vending Machine.** Testing whether you simulate *the stated rule* or silently upgrade it
to the *correct* rule. Change-making with limited coins is a knapsack; the machine does greedy
and greedy fails here. Half of all WA verdicts on implementation problems are you solving a
better problem than the one asked. Also: inserted coins join the stock *before* change is
computed, and a rejected transaction must roll the stock back exactly.

**2. Traffic Lights.** State advance by modular arithmetic. `phase = t % (g+r)`; if
`phase < g` pass, else `t += (g + r) - phase`. The trap is the half-open interval —
`t % period == g` is red. Write the interval down explicitly before coding.

**3. Falling Bricks.** Careful bookkeeping with no shortcut available. Because bricks are
2 wide, holes form, so per-column heights are *not* sufficient state — you need an actual
grid. Contrast with 1-wide bricks, where stacks stay contiguous, full rows are exactly the
bottom `min(h)` rows, and the whole problem collapses to subtracting a number. Recognising
when the invariant lets you skip the grid, and when it doesn't, is the skill.

**4. Robot on a Torus.** This is a functional graph: each cell has exactly one outgoing edge,
so the trajectory is a "rho" — a tail then a cycle. Walk until you revisit a cell, recording
the step index of each visit. That gives tail length `t` and cycle length `c`. If `K < t`
answer directly, else answer is position at `t + (K - t) % c`. Binary lifting also works
(`O(V log K)`) and generalises better; know both.

**5. Bit Colony.** Same idea as 4, one level up: now the *whole configuration* is the node.
With `n ≤ 20` there are at most `2^20` states, so pack the strip into an integer and run
cycle detection over states. The constraint `n ≤ 20` is the setter telling you the state
space is small enough to enumerate — read constraints as hints about the intended state.
(This particular rule is also linear over GF(2), so matrix exponentiation works; that's the
harder, more general solution.)

**6. Sandpile.** Naive "scan all piles, topple, repeat" is `O(n × rounds)` and dies. Keep a
queue of piles known to have `≥ 2` grains; pop one, topple it as many times as possible at
once (`a_i / 2` topplings in one step, not one at a time), push any neighbour that crosses
the threshold. This is *amortised* simulation: the total work is bounded by the number of
topplings, not by rounds × n. Toppling in bulk rather than one grain at a time is the whole
speedup.

**7. Shuffling Machine.** Do not simulate seconds. One second is itself a permutation:
composing "apply `p`" with "rotate right by 1" gives a single permutation `q` where
`q_i = (p_i mod n) + 1`. Now you need `q^K`, which is cycle decomposition — for each cycle of
length `L`, every element shifts by `K mod L` along that cycle. `O(n)` total. The lesson:
when a process repeats a fixed transformation, find the transformation's structure instead
of running the process.

**8. Conveyor.** Don't move the data, move the *view*. Keep an integer `off`; a rotate-left
by `k` is just `off = (off + k) % n`. Logical index `i` maps to physical index
`(off + i - 1) % n`. Both `S` and `Q` go through that mapping. `O(1)` per operation. Same
family as 7: represent the transformation, not the transformed thing.

## The arc

Problems 1–3 are "can you translate a spec into correct code without editorialising it."
Problems 4–6 are "naive simulation is too slow — find the repetition or the amortisation."
Problems 7–8 are "don't simulate the process at all; simulate the object that describes it."

When you get stuck on a real contest simulation problem, the diagnostic question is almost
always one of these three: *Am I solving the stated rule? Does the state repeat? Am I
simulating the wrong object?*
