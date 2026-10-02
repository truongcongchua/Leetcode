# LeetCode Weekly Practice

A shared repository for weekly LeetCode practice by:

- [@truongcongchua](https://github.com/truongcongchua)
- [@Oviraptor0710](https://github.com/Oviraptor0710)

The goal of this repository is not only to solve LeetCode problems, but also to practice:

- Data Structures and Algorithms
- Problem-solving and solution explanation
- Git and GitHub workflow
- Conventional Commits
- Pull Requests
- Code Review
- Comparing multiple approaches to the same problem

---

## Workflow

For each LeetCode problem, we follow this workflow:

```text
Create Issue
    ↓
Create Branch
    ↓
Solve Problem
    ↓
Commit Changes
    ↓
Push Branch
    ↓
Create Pull Request
    ↓
Code Review
    ↓
Compare Solutions
    ↓
Merge
    ↓
Close Issue
```

Each LeetCode problem should normally have its own GitHub Issue.

---

## Issues

### Issue Naming

Use the following format:

```text
[Topic][Difficulty] LC <number> - <problem name>
```

Examples:

```text
[RMQ][Easy] LC 303 - Range Sum Query - Immutable
[Segment Tree][Medium] LC 307 - Range Sum Query - Mutable
[DP][Medium] LC 322 - Coin Change
[Graph][Medium] LC 200 - Number of Islands
[Bitmask DP][Hard] LC 847 - Shortest Path Visiting All Nodes
```

### Recommended Issue Structure

```md
## Problem

LeetCode <number> - <problem name>

<LeetCode URL>

## Learning Goals

Describe what we expect to learn from this problem.

For example:

- Understand the main algorithmic pattern
- Recognize when this technique can be used
- Analyze time and space complexity
- Compare alternative approaches

## Tasks

- [ ] Solve independently
- [ ] Analyze time complexity
- [ ] Analyze space complexity
- [ ] Compare solutions
- [ ] Review each other's code

## Discussion Questions

1. Why does this algorithm work?
2. What are the important edge cases?
3. Can the solution be optimized?
4. Is there another approach?
5. When should this pattern be used?

## Progress

### Solutions

- [ ] @truongcongchua solved
- [ ] @Oviraptor0710 solved

### Review

- [ ] @truongcongchua reviewed @Oviraptor0710's solution
- [ ] @Oviraptor0710 reviewed @truongcongchua's solution
- [ ] Compared approaches
```

---

## Branch Naming

Do not work directly on `main`.

Create a separate branch for each person and each problem.

Recommended format:

```text
<username>/<issue-number>-<short-problem-name>
```

Examples:

```text
truongcongchua/12-range-sum-query
Oviraptor0710/12-range-sum-query

truongcongchua/18-coin-change
Oviraptor0710/18-coin-change
```

Create a branch:

```bash
git switch -c truongcongchua/12-range-sum-query
```

or:

```bash
git checkout -b truongcongchua/12-range-sum-query
```

---

## Conventional Commits

This repository follows a simplified version of [Conventional Commits](https://www.conventionalcommits.org/).

### Format

```text
<type>: <description>
```

Optionally, reference the related issue:

```text
<type>: <description> (#issue-number)
```

Example:

```text
solve: implement segment tree solution (#12)
```

### Commit Types

#### `solve`

Use when adding a solution to a LeetCode problem.

```text
solve: add binary search solution
solve: implement segment tree solution
solve: add top-down bitmask dp solution
```

#### `optimize`

Use when improving time complexity, space complexity, pruning, or algorithmic efficiency.

```text
optimize: reduce solution from O(n^2) to O(n log n)
optimize: add pruning to backtracking solution
optimize: replace brute force with binary search
```

#### `fix`

Use when fixing an incorrect solution or edge case.

```text
fix: handle empty input
fix: correct binary search boundary
fix: prevent integer overflow
fix: handle duplicate values in 3sum
```

#### `refactor`

Use when restructuring code without changing the algorithm.

```text
refactor: simplify segment tree query
refactor: extract dfs into helper function
refactor: rename variables for readability
```

#### `docs`

Use for documentation, explanations, notes, or README changes.

```text
docs: add segment tree explanation
docs: add complexity analysis
docs: update weekly progress
docs: add conventional commit guide
```

#### `test`

Use when adding test cases or debugging inputs.

```text
test: add edge cases for binary search
test: add empty array case
test: add large input test
```

#### `chore`

Use for repository maintenance that does not affect solutions.

```text
chore: reorganize folder structure
chore: add gitignore
chore: create week 03 directory
```

### Recommended Commit Style

Prefer small and meaningful commits.

Avoid:

```text
update
fix
code
done
leetcode
change something
final version
```

Prefer:

```text
solve: add brute force solution
optimize: replace brute force with segment tree
refactor: simplify range query function
docs: add complexity analysis
```

A good Git history should show how a solution evolved:

```text
solve: add recursive brute force solution
optimize: add memoization
optimize: convert solution to bitmask dp
docs: add complexity analysis
```

---

## Linking Commits to Issues

Whenever possible, reference the GitHub Issue:

```text
solve: implement range sum query (#12)
```

The Pull Request should be responsible for closing the issue.

---

## Pull Requests

After finishing a solution, push the branch:

```bash
git push -u origin truongcongchua/12-range-sum-query
```

Recommended PR title:

```text
Solve #12 - LC 307 Range Sum Query - Mutable
```

Recommended PR body:

```md
Closes #12

## Approach

Describe the main idea of the solution.

## Complexity

Time: O(...)

Space: O(...)

## What I Learned

- ...
- ...
- ...

## Notes

Mention anything worth discussing during review.
```

Using:

```text
Closes #12
```

will automatically close Issue `#12` after the Pull Request is merged.

Each person should create a separate PR for the same issue so both solutions can be reviewed independently.

---

## Code Review

Each person should review the other person's solution before merging.

Focus mainly on:

```text
Correctness
    ↓
Algorithm
    ↓
Time Complexity
    ↓
Space Complexity
    ↓
Edge Cases
    ↓
Code Readability
```

Useful review questions:

- Why does this approach work?
- Can this part be optimized?
- Is this condition always correct?
- What happens with duplicate values?
- Can this solution cause integer overflow?
- Can we reduce the space complexity?
- Is there another algorithm for this problem?

The main purpose of review is to understand and improve the algorithm, not only formatting.

---

## Comparing Solutions

Different correct approaches are encouraged.

Example:

```text
LC 698 - Partition to K Equal Sum Subsets

@truongcongchua
→ Backtracking + Pruning

@Oviraptor0710
→ Bitmask DP
```

Discuss:

- Which approach is easier to understand?
- Which approach has better worst-case complexity?
- Which approach uses more memory?
- Which one would be easier to explain in an interview?
- Which pattern can be reused in other problems?

---

## Suggested Repository Structure

```text
leetcode-practice/
│
├── README.md
│
├── solutions/
│   │
│   ├── rmq/
│   │   ├── 303-range-sum-query-immutable/
│   │   │   ├── truongcongchua.cpp
│   │   │   └── Oviraptor0710.cpp
│   │   │
│   │   └── 307-range-sum-query-mutable/
│   │       ├── truongcongchua.cpp
│   │       └── Oviraptor0710.cpp
│   │
│   ├── dynamic-programming/
│   ├── graph/
│   ├── tree/
│   ├── binary-search/
│   └── backtracking/
│
└── notes/
    ├── segment-tree.md
    ├── binary-search.md
    ├── dynamic-programming.md
    └── bitmask-dp.md
```

The exact structure can change as the repository grows.

Consistency is more important than having a perfect structure from the beginning.

---

## Weekly Practice

Problems can be grouped into weekly milestones.

Example:

```text
Week 01 - RMQ Fundamentals

#1 LC 303 - Range Sum Query - Immutable
#2 LC 307 - Range Sum Query - Mutable
#3 LC 2407 - Longest Increasing Subsequence II
```

Recommended milestone name:

```text
Week 01 - RMQ & Segment Tree
```

---

## Recommended Labels

### Difficulty

```text
easy
medium
hard
```

### Topic

```text
array
binary-search
backtracking
bitmask
dp
graph
greedy
heap
linked-list
prefix-sum
rmq
segment-tree
sliding-window
stack
tree
two-pointers
```

### Workflow / Purpose

```text
learning
review-needed
discussion
challenge
bonus
```

---

## Important Rules

1. Do not push solutions directly to `main`.
2. Try to solve the problem independently before reading the other person's code.
3. Do not copy a solution without understanding it.
4. Every solution should include time and space complexity analysis.
5. Important or difficult problems should be reviewed before merging.
6. Different approaches to the same problem are encouraged.
7. A problem is considered complete only when both the solution and review are finished.

---

## Example Full Workflow

Suppose Issue `#12` is:

```text
[Segment Tree][Medium] LC 307 - Range Sum Query - Mutable
```

Create a branch:

```bash
git switch -c truongcongchua/12-range-sum-query
```

Implement the first solution:

```bash
git add .
git commit -m "solve: implement segment tree solution (#12)"
```

Improve it:

```bash
git add .
git commit -m "refactor: simplify segment tree query (#12)"
```

Add explanation:

```bash
git add .
git commit -m "docs: add complexity analysis for LC 307 (#12)"
```

Push:

```bash
git push -u origin truongcongchua/12-range-sum-query
```

Create Pull Request:

```text
Solve #12 - LC 307 Range Sum Query - Mutable
```

PR body:

```md
Closes #12

## Approach

Segment Tree with point update and range sum query.

## Complexity

Build: O(n)

Update: O(log n)

Query: O(log n)

Space: O(n)
```

The other person reviews the code.

After both solutions have been discussed:

```text
Approve
    ↓
Merge
    ↓
Issue closed
```

---

## Main Goal

The goal is not simply:

> Solve as many LeetCode problems as possible.

The goal is:

```text
Solve
  ↓
Understand
  ↓
Explain
  ↓
Review
  ↓
Compare
  ↓
Improve
```

A smaller number of well-understood problems is more valuable than a large number of copied or poorly understood solutions.
