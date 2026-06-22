// -- Binary Tree Creation and Traversal (Preorder, Inorder, Postorder) -- //

#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in level order (Binary Tree)
Node* insertLevelOrder(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Use a queue for level order insertion
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];

        // If left child is empty, insert here
        if (temp->left == NULL) {
            temp->left = createNode(data);
            return root;
        } else {
            queue[rear++] = temp->left;
        }

        // If right child is empty, insert here
        if (temp->right == NULL) {
            temp->right = createNode(data);
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

// Preorder Traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);      // Visit root
    preorder(root->left);            // Traverse left subtree
    preorder(root->right);           // Traverse right subtree
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);             // Traverse left subtree
    printf("%d ", root->data);      // Visit root
    inorder(root->right);            // Traverse right subtree
}

// Postorder Traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);           // Traverse left subtree
    postorder(root->right);          // Traverse right subtree
    printf("%d ", root->data);      // Visit root
}

// MAIN FUNCTION //
int main() {
    Node* root = NULL;

    // Insert nodes into the binary tree
    root = insertLevelOrder(root, 10);
    root = insertLevelOrder(root, 20);
    root = insertLevelOrder(root, 30);
    root = insertLevelOrder(root, 40);
    root = insertLevelOrder(root, 50);
    root = insertLevelOrder(root, 60);
    root = insertLevelOrder(root, 70);

    printf("Binary Tree Traversals:\n\n");

    printf("Preorder traversal (Root -> Left -> Right): ");
    preorder(root); /* Output: 10 20 40 50 30 60 70 */
    printf("\n");

    printf("Inorder traversal (Left -> Root -> Right):  ");
    inorder(root);  /* Output: 40 20 50 10 60 30 70 */
    printf("\n");

    printf("Postorder traversal (Left -> Right -> Root): ");
    postorder(root); /* Output: 40 50 20 60 70 30 10 */
    printf("\n");

    return 0;
}
