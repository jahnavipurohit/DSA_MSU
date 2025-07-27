# Part A: Algorithm Writing and Analysis

## 1. Find Maximum and Minimum Element in a List of n Integers

### Algorithm

1. Initialize `max = A[0]`  
2. Initialize `min = A[0]`  
3. For `i` from 1 to `n-1`, do:  
    - If `A[i] > max` then `max = A[i]`  
    - If `A[i] < min` then `min = A[i]`  
4. Return `max` and `min`

### A Priori Analysis

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)  
- **Optimality:** Optimal linear-time solution, very efficient for this problem.

---

## 2. Count the Number of Odd and Even Numbers in an Array of Size n

### Algorithm

1. Initialize `even_count = 0`  
2. Initialize `odd_count = 0`  
3. For `i` from 0 to `n-1`, do:  
    - If `A[i] mod 2 == 0` then  
        → `even_count = even_count + 1`  
    - Else  
        → `odd_count = odd_count + 1`  
4. Return `even_count` and `odd_count`

### A Priori Analysis

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)  
- **Optimality:** This is optimal as it only requires one traversal of the array and minimal additional space.

---

## 3. Reverse a Given Array of Integers of Size n

### Algorithm

1. Initialize `start = 0`  
2. Initialize `end = n - 1`  
3. While `start < end`, do:  
    - Swap `A[start]` and `A[end]`  
    - Increment `start` by 1  
    - Decrement `end` by 1  
4. The array is now reversed

### A Priori Analysis

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)  
- **Optimality:** This is the optimal in-place reversal algorithm with minimal space and time usage.

