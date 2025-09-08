# Singly Linked List Operations

## 1. Algorithms / Pseudocode

### a) Insert at Beginning
```
Algorithm InsertAtBeginning(head, data):
    newNode ← createNode(data)
    newNode.next ← head
    head ← newNode
    return head
```

### b) Insert at End
```
Algorithm InsertAtEnd(head, data):
    newNode ← createNode(data)
    if head = NULL:
        head ← newNode
        return head
    temp ← head
    while temp.next ≠ NULL:
        temp ← temp.next
    temp.next ← newNode
    return head
```

### c) Insert After a Given Node
```
Algorithm InsertAfter(node, data):
    if node = NULL:
        print "Given node cannot be NULL"
        return
    newNode ← createNode(data)
    newNode.next ← node.next
    node.next ← newNode
```

### d) Insert Before a Given Node
```
Algorithm InsertBefore(head, key, data):
    newNode ← createNode(data)
    if head.data = key:
        newNode.next ← head
        head ← newNode
        return head
    prev ← NULL
    curr ← head
    while curr ≠ NULL and curr.data ≠ key:
        prev ← curr
        curr ← curr.next
    if curr = NULL:
        print "Key not found"
        return head
    prev.next ← newNode
    newNode.next ← curr
    return head
```

### e) Delete from Beginning
```
Algorithm DeleteFromBeginning(head):
    if head = NULL:
        print "List is empty"
        return head
    temp ← head
    head ← head.next
    free(temp)
    return head
```

### f) Delete from End
```
Algorithm DeleteFromEnd(head):
    if head = NULL:
        print "List is empty"
        return head
    if head.next = NULL:
        free(head)
        return NULL
    temp ← head
    while temp.next.next ≠ NULL:
        temp ← temp.next
    free(temp.next)
    temp.next ← NULL
    return head
```

### g) Delete After a Given Node
```
Algorithm DeleteAfter(node):
    if node = NULL or node.next = NULL:
        print "No node to delete"
        return
    temp ← node.next
    node.next ← temp.next
    free(temp)
```

### h) Display Linked List (Traversal)
```
Algorithm DisplayList(head):
    temp ← head
    while temp ≠ NULL:
        print temp.data
        temp ← temp.next
```

### i) Search in Linked List
```
Algorithm Search(head, key):
    temp ← head
    while temp ≠ NULL:
        if temp.data = key:
            return true
        temp ← temp.next
    return false
```

### j) Count Nodes
```
Algorithm CountNodes(head):
    count ← 0
    temp ← head
    while temp ≠ NULL:
        count ← count + 1
        temp ← temp.next
    return count
```

### k) Reverse Linked List
```
Algorithm ReverseList(head):
    prev ← NULL
    curr ← head
    while curr ≠ NULL:
        next ← curr.next
        curr.next ← prev
        prev ← curr
        curr ← next
    head ← prev
    return head
```

---

## 2. Apriori Analysis

| Operation                            | Time Complexity | Space Complexity |
|--------------------------------------|----------------|------------------|
| Insert at Beginning                  | O(1)           | O(1)             |
| Insert at End                        | O(n)           | O(1)             |
| Insert After a Given Node            | O(1)           | O(1)             |
| Insert Before a Given Node           | O(n)           | O(1)             |
| Delete from Beginning                | O(1)           | O(1)             |
| Delete from End                      | O(n)           | O(1)             |
| Delete After a Given Node            | O(1)           | O(1)             |
| Display Linked List (Traversal)      | O(n)           | O(1)             |
| Search in Linked List                | O(n)           | O(1)             |
| Count Nodes                          | O(n)           | O(1)             |
| Reverse Linked List                  | O(n)           | O(1)             |

---

## 3. Optimising Insertion at End
To optimise insertion at the end of a singly linked list, maintain a `tail` pointer that always points to the last node in the list.  
This allows insertion in **O(1)** time instead of **O(n)**, as we do not need to traverse the list to find the last node.

---

## 4. Why Deleting a Node Before a Given Node is Not Possible
In a singly linked list, each node stores only a pointer to its **next** node and has no reference to its **previous** node.  
Therefore, to delete the node before a given node, we would need access to the node before that previous node (its predecessor), which is not possible without starting from the head and traversing the list.
