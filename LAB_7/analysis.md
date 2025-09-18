# Queue Data Structure 


1. **Linear Queue (Array):**
   - Simple implementation, but suffers from space wastage after dequeues.

2. **Queue using Linked List:**
   - Dynamic size, no memory wastage, but overhead of pointers.

3. **Circular Queue:**
   - Solves space wastage issue by wrapping indices.

4. **Double-Ended Queue (Deque):**
   - Insert/Delete from both ends; useful for Undo/Redo operations.

5. **Priority Queue:**
   - Elements dequeued based on priority instead of order.
   - Applications: CPU scheduling, OS job management.

6. **Queue using Two Stacks:**
   - Demonstrates queue-stack relationship with trade-offs.

7. **Stack using Two Queues:**
   - Demonstrates stack-queue relationship with trade-offs.

8. **Multiple Queues in One Array:**
   - Efficient memory usage by managing two queues in a single array.

9. **Applications:**
   - **CPU Scheduling (FCFS)**
   - **Print Spooler**
   - **Customer Service with Priority Queue**



## Complexity Analysis

| Experiment | Enqueue | Dequeue | Peek | Display |
|------------|---------|---------|------|---------|
| **Linear Queue (Array)** | O(1) | O(1) | O(1) | O(n) |
| **Queue (Linked List)** | O(1) | O(1) | O(1) | O(n) |
| **Circular Queue** | O(1) | O(1) | O(1) | O(n) |
| **Double-Ended Queue (Deque)** | O(1) | O(1) | O(1) | O(n) |
| **Priority Queue (Unsorted Array)** | O(1) | O(n) | O(n) | O(n) |
| **Queue using Two Stacks** | O(n) | O(1) | O(1) | O(n) |
| **Stack using Two Queues** | O(n) | O(1) | O(1) | O(n) |
| **Multiple Queues in One Array** | O(1) | O(1) | O(1) | O(n) |
| **Applications – CPU Scheduling (FCFS)** | O(1) | O(1) | O(1) | O(n) |
| **Applications – Print Spooler** | O(1) | O(1) | O(1) | O(n) |
| **Applications – Customer Service (Priority Queue)** | O(1) | O(n) | O(n) | O(n) |



