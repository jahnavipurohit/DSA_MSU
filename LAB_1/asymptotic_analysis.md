
# Part B: Asymptotic Analysis

---

## a) Nested Loops

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        printf("*");
    }
}
```

**Time Complexity:**

- **Best-case:** `O(n^2)`  
- **Worst-case:** `O(n^2)`  
- **Average-case:** `O(n^2)`  

**Step-by-step Analysis:**

- Outer loop runs `n` times.
- Inner loop runs `n` times for each iteration of the outer loop.
- Total operations: `n * n = n^2` → **O(n²)**

---

## b) Recursive Function

```c
void func(int n) {
    if (n == 1)
        return;
    func(n/2);
    func(n/2);
}
```

**Time Complexity:**

- **Best-case:** `O(log n)`  
- **Worst-case:** `O(n)`  
- **Average-case:** `O(n)`  

**Step-by-step Analysis:**

- Each call spawns 2 calls with `n/2`.
- Forms a binary recursion tree.
- Number of calls: `2^k` where `k = log n`.
- Total operations: **O(n)**

---

## c) Logarithmic Growth

```c
int i = 1;
while (i < n) {
    printf("%d ", i);
    i = i * 2;
}
```

**Time Complexity:**

- **Best-case:** `O(log n)`  
- **Worst-case:** `O(log n)`  
- **Average-case:** `O(log n)`  

**Step-by-step Analysis:**

- `i` grows exponentially: 1, 2, 4, 8, ...
- Loop runs approximately `log₂(n)` times.
- Total operations: **O(log n)**

---

## d) Triple Nested Loops

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            printf("*");
        }
    }
}
```

**Time Complexity:**

- **Best-case:** `O(n^3)`  
- **Worst-case:** `O(n^3)`  
- **Average-case:** `O(n^3)`  

**Step-by-step Analysis:**

- Outer loop: `n` times
- Middle loop: `n` times
- Inner loop: `n` times
- Total operations: `n * n * n = n^3` → **O(n³)**

---

## e) Recursive Fibonacci

```c
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

**Time Complexity:**

- **Best-case:** `O(n)` (with memoization)  
- **Worst-case:** `O(2ⁿ)`  
- **Average-case:** `O(2ⁿ)`  

**Step-by-step Analysis:**

- Without memoization, calls overlap.
- Forms binary tree of height `n`.
- Total recursive calls: approximately `2ⁿ` → **O(2ⁿ)**

---

## f) Constant Operation

```c
printf("Hello World");
```

**Time Complexity:**

- **Best-case:** `O(1)`  
- **Worst-case:** `O(1)`  
- **Average-case:** `O(1)`  

**Step-by-step Analysis:**

- Executes once, regardless of input size.
- Total operations: **O(1)**

---

## g) Two Separated Loops

```c
for (int i = 0; i < n; i++) {
    printf("*");
}
for (int j = 0; j < n; j++) {
    for (int k = 0; k < n; k++) {
        printf("#");
    }
}
```

**Time Complexity:**

- **Best-case:** `O(n²)`  
- **Worst-case:** `O(n²)`  
- **Average-case:** `O(n²)`  

**Step-by-step Analysis:**

- First loop: `n` operations → `O(n)`
- Second loop: `n * n` operations → `O(n²)`
- Total: `O(n + n²)` → **O(n²)** (since `n²` dominates)

---
