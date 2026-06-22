# Trees in C

Trees are hierarchical data structures consisting of nodes connected by edges. Each node has at most one parent and can have multiple children.

**Key concepts:**

- **Binary Tree**: Each node has at most 2 children (left and right)

```
        ┌──── 10 ────┐
        │             │
     ┌──5──┐      ┌──15──┐
     │     │      │     │
   ┌─3─┐ ┌─7─┐ ┌─12─┐ ┌─20─┐
   │   │ │   │ │   │ │   │
  NULL N N N N N N N N N N NULL

  Node = 3 fields: [data | left | right]
```

- **Binary Search Tree (BST)**: Ordered tree where left child < parent < right child

```
        ┌──── 10 ────┐
        │             │
     ┌──5──┐      ┌──15──┐
     │     │      │     │
     3     7     12    20

  All left descendants < 10 < all right descendants
  Same property applies recursively at every node
```

- **Full Binary Tree**: Every node has 0 or 2 children (no node with only 1 child)

```
        ┌─── 1 ───┐
        │         │
     ┌──2──┐   ┌──3──┐
     │     │   │     │
     4     5   6     7

  Internal nodes (1,2,3) all have exactly 2 children
```

- **Complete Binary Tree**: All levels except possibly the last are completely filled

```
        ┌─── 1 ───┐
        │         │
     ┌──2──┐   ┌──3──┐
     │     │   │     │
     4     5   6   NULL

  Nodes added left-to-right; gaps only at the bottom-right
  Used for heap data structures
```

- **Perfect Binary Tree**: All internal nodes have 2 children and all leaves are at the same level

```
        ┌─── 1 ───┐
        │         │
     ┌──2──┐   ┌──3──┐
     │     │   │     │
     4     5   6     7

  Height h = 2, Total nodes = 2^(h+1) - 1 = 7
```

- **Tree Traversals**: Preorder (Root→Left→Right), Inorder (Left→Root→Right), Postorder (Left→Right→Root)

```
  Using BST above:
  Preorder:  10 → 5 → 3 → 7 → 15 → 12 → 20   (Root first)
  Inorder:    3 → 5 → 7 → 10 → 12 → 15 → 20   (Sorted order)
  Postorder:  3 → 7 → 5 → 12 → 20 → 15 → 10   (Root last)
```

- **BST Operations**: Insert, search, delete, find minimum and maximum

```
  Insert 8 into BST:
  ┌──── 10 ────┐           ┌──── 10 ────┐
  │             │           │             │
  ┌──5──┐   ┌──15──┐  →  ┌──5──┐     ┌──15──┐
  │     │   │     │       │     │     │     │
  3     7   12    20      3   ┌─7─┐  12    20
                              │   │
                              6   8
```
