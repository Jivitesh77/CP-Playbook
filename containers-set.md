# Stacks, Queues & Deques — Problem Set

Seven original problems. Same rules: 45 minutes each, spoilers at the bottom.

## What this topic actually is

Knowing that `std::vector` has `push_back` is not a competitive programming topic. The real
content is a small number of patterns where a container **is** the algorithm:

- **Monotonic stack** — for every element, find the nearest element on one side satisfying a
  comparison. Turns `O(n^2)` into `O(n)`. This is the single most valuable pattern in the set.
- **Monotonic deque** — the same idea over a sliding window.
- **Stack as a matcher** — nesting, bracket structure, expression parsing, collapse processes.
- **Deque as a process** — problems where the object genuinely is a two-ended queue.
- **Amortised structure** — two stacks simulating a queue, which buys you `O(1)` minimum.

The unifying insight for the monotonic patterns: when you pop an element, you are asserting
*it will never be the answer for anything later*. If you can prove that, the total number of
pops is `n`, and the whole scan is linear even though the inner loop looks quadratic. Being
able to state that proof for a given problem is what separates "I memorised monotonic stack"
from being able to derive it under contest pressure.

Also worth knowing about `vector`: `erase` from the middle is `O(n)`. Doing it inside a loop
is the most common accidental `O(n^2)` in beginner code, and problem 6 exists to make you
feel it.

---

## 1. Longest Valid Bracket Run — ~1600

Given a string of `(` and `)` characters, find the length of the longest contiguous substring
that is a valid bracket sequence.

**Constraints:** `1 ≤ n ≤ 10^6`.

**Sample input**
```
)()())
```

**Sample output**
```
4
```

---

## 2. Next Taller — ~1500

Given `n` building heights, for each building `i` print the index of the nearest building to
its right that is **strictly taller**, or `0` if there is none.

**Constraints:** `1 ≤ n ≤ 10^6`, `1 ≤ h_i ≤ 10^9`.

**Sample input**
```
5
3 1 4 1 5
```

**Sample output**
```
3 3 5 5 0
```

---

## 3. Largest Rectangle — ~1700

A histogram of `n` bars, bar `i` having width `1` and height `h_i`. Find the area of the
largest axis-aligned rectangle that fits entirely inside the histogram.

**Constraints:** `1 ≤ n ≤ 10^6`, `0 ≤ h_i ≤ 10^9`.

**Sample input**
```
6
2 1 5 6 2 3
```

**Sample output**
```
10
```

---

## 4. Sliding Window Maximum — ~1600

Given an array of `n` integers and an integer `k`, print the maximum of every contiguous
window of length `k`, in order.

**Constraints:** `1 ≤ k ≤ n ≤ 10^6`.

**Sample input**
```
8 3
1 3 -1 -3 5 3 6 7
```

**Sample output**
```
3 3 5 5 6 7
```

---

## 5. Minimum Queue — ~1700

Maintain a queue supporting three operations, each in **amortised `O(1)`**:

- `push x` — add `x` to the back
- `pop` — remove the element at the front
- `min` — print the minimum element currently in the queue

`pop` and `min` are never called on an empty queue.

**Constraints:** `1 ≤ q ≤ 10^6`, `-10^9 ≤ x ≤ 10^9`. A solution that scans the queue on every
`min` will not pass.

**Sample input**
```
8
push 5
push 3
min
pop
push 4
min
pop
min
```

**Sample output**
```
3
3
4
```

---

## 6. Collapse — ~1500

Given a string, repeatedly remove any two **adjacent equal** characters. Repeat until no two
adjacent characters are equal. The final result does not depend on the order of removals.
Print it, or `EMPTY` if nothing remains.

**Constraints:** `1 ≤ n ≤ 10^6`, lowercase letters.

**Sample input**
```
abbaca
```

**Sample output**
```
ca
```

---

## 7. War of Cards — ~1500

Two players split a deck of `n` distinct cards numbered `1..n`; each holds their cards as a
queue with a defined order.

Each round, both players reveal the card at the front of their queue. The player with the
higher card wins the round and places **both** cards at the back of their own queue, the
loser's card first, then their own. A player wins the game when the other has no cards left.

Print the number of rounds played and the winner (`1` or `2`), or `-1` if the game never ends.

**Constraints:** `2 ≤ n ≤ 10`.

**Input**
```
n
k1 followed by k1 cards      (player 1's queue, front first)
k2 followed by k2 cards
```

**Sample input**
```
4
2 1 3
2 4 2
```

**Sample output**
```
6 2
```

---
---

# SPOILERS

**1. Longest Valid Bracket Run.** Stack of **indices**, not characters. Push `-1` as a
sentinel first. On `(`, push the index. On `)`, pop; if the stack is now empty, push the
current index (it becomes the new "last unmatched position" boundary), otherwise the current
valid length is `i - stack.top()`. Track the running maximum. The sentinel and the
push-on-empty are the two things that make this work without special-casing; both are easy to
derive if you keep asking "what does the top of my stack *mean*?" — here it means "the index
just before the current valid run began."

A second solution worth knowing: two linear passes with a counter, left-to-right and then
right-to-left, resetting whenever the counter goes negative. `O(1)` memory.

**2. Next Taller.** The canonical monotonic stack. Scan right to left keeping a stack of
indices whose heights are strictly decreasing from bottom to top. For each `i`, pop while the
top's height is `≤ h_i`; whatever remains on top is the answer (or `0` if empty); then push `i`.

The linearity proof: every index is pushed exactly once and popped at most once, so total work
is `O(n)` despite the inner `while`. And the correctness argument for popping is the thing to
internalise — if `h[j] ≤ h[i]` and `j` is to the right of `i`, then `j` can never be the answer
for anything to the left of `i`, because `i` blocks it and is at least as tall. That sentence,
adapted, is the justification for *every* monotonic stack problem.

Left-to-right also works (you resolve elements as you pop them rather than reading the top);
knowing both directions matters because some problems only admit one.

**3. Largest Rectangle.** For each bar, the widest rectangle of exactly that height extends
left to the first strictly-shorter bar and right to the first strictly-shorter bar. Those are
two monotonic-stack passes — or one pass, resolving each bar's width at the moment it gets
popped, which is the version worth learning.

Single-pass version: keep a stack of indices with increasing heights. When `h_i` is less than
the top, pop `t` and compute `h[t] * (i - stack.top() - 1)` — the width spans from just after
the new top to just before `i`. Append a sentinel `0` at the end so everything flushes.

Equal heights are the classic trap: with the width formula above, ties resolve correctly
because the earlier bar's rectangle gets computed with the full span. Test `[2,2,2]` (answer
`6`) and `[5,5]` before submitting. Also: `n = 10^6` with heights `10^9` means `long long`.

**4. Sliding Window Maximum.** Monotonic deque holding **indices**, values decreasing from
front to back. For each `i`: pop from the back while the back's value is `≤ a_i`, push `i`,
then pop from the front if `front ≤ i - k` (it has slid out of the window). Once `i ≥ k-1`,
the front is the window maximum.

Same proof as problem 2 — a smaller element with a smaller index is dominated forever, so it
can be discarded. Each index enters and leaves once. This is why the structure is a deque and
not a stack: you discard from the back for dominance, and from the front for expiry.

**5. Minimum Queue.** Two stacks, `in` and `out`, each storing pairs of `(value, minimum of
this stack)`. `push` goes to `in`, pushing `(x, min(x, in.top().second))`. `pop` takes from
`out`; if `out` is empty, first move everything from `in` to `out` one at a time, recomputing
the running minimum as you go. `min` is `min(in.top().second, out.top().second)`, skipping
whichever stack is empty.

Every element is moved between stacks at most once, so `q` operations cost `O(q)` total —
amortised, not worst-case, and the distinction matters if you ever need this inside a rollback
or persistent setting. This structure is genuinely useful beyond this problem: a minimum queue
gives you sliding window minimum for free and shows up in optimising certain DP transitions.

**6. Collapse.** A stack, and the process is the algorithm. Scan left to right: if the stack
is non-empty and its top equals the current character, pop; otherwise push. What remains is
the answer, bottom to top.

The reason this is here: the naive reading of the statement is "scan the string, erase a pair,
restart," which is `O(n^2)` at best and involves `vector::erase` in a loop at worst. With
`n = 10^6` that is fatal. Recognising that a *removal process on adjacent elements* is almost
always a stack is the transferable lesson, and it is the same recognition that solves bracket
problems, expression parsing, and a lot of Div. 2 C's that don't look like stack problems at all.

**7. War of Cards.** Straightforward deque simulation, plus one thing: the game genuinely can
loop forever, so you need cycle detection. With `n ≤ 10` the number of distinct states (the
pair of queues) is small enough to store every state seen in a `set<string>` and stop the
moment one repeats.

The alternative bound — "if more than `X` rounds pass, declare `-1`" — works too and is what
most people submit, but you have to justify `X`. Cycle detection needs no magic number and is
the same rho-shape argument as the torus robot in the simulation set. The state space is the
node set; the deterministic round is the edge.

## The recognition table

| Statement shape | Reach for |
|---|---|
| "nearest greater/smaller element on the left/right" | monotonic stack |
| "for every window of length k, the max/min" | monotonic deque |
| "largest rectangle / area under constraints" | monotonic stack |
| "repeatedly remove adjacent pairs satisfying P" | stack |
| "matching, nesting, or valid sequence" | stack of indices |
| "each element interacts with the next surviving one" | stack |
| "the object in the problem is literally a queue of things" | deque + cycle detection |

If you find yourself writing a nested loop where the inner loop scans backwards until some
comparison fails, stop. That is a monotonic stack every single time.
