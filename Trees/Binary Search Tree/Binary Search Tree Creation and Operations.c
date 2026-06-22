// -- Binary Search Tree (BST) Operations: Insert, Search, Delete, Min, Max -- //

#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
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

// Insert a node into BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a value in BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Find minimum value node in BST
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find maximum value node in BST
Node* findMax(Node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    // Find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found — handle deletion

        // Case 1: No child or one child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children — get inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (Left -> Root -> Right) — gives sorted order for BST
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// MAIN FUNCTION //
int main() {
    Node* root = NULL;

    // Insert nodes into BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("BST Traversals:\n");
    printf("Inorder (sorted):   ");
    inorder(root);   /* Output: 20 30 40 50 60 70 80 */
    printf("\n");

    printf("Preorder:           ");
    preorder(root);  /* Output: 50 30 20 40 70 60 80 */
    printf("\n");

    printf("Postorder:          ");
    postorder(root); /* Output: 20 40 30 60 80 70 50 */
    printf("\n\n");

    // Search for a value
    int key = 40;
    Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in BST\n", key); /* Output: Element 40 found in BST */
    } else {
        printf("Element %d not found in BST\n", key);
    }

    // Find min and max
    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);
    printf("Minimum value in BST: %d\n", minNode->data); /* Output: 20 */
    printf("Maximum value in BST: %d\n", maxNode->data); /* Output: 80 */

    // Delete a node (leaf node)
    printf("\nDeleting 20 (leaf node)...\n");
    root = deleteNode(root, 20);
    printf("Inorder after deletion: ");
    inorder(root);   /* Output: 30 40 50 60 70 80 */
    printf("\n");

    // Delete a node with one child
    printf("Deleting 30 (node with one child)...\n");
    root = deleteNode(root, 30);
    printf("Inorder after deletion: ");
    inorder(root);   /* Output: 40 50 60 70 80 */
    printf("\n");

    // Delete a node with two children
    printf("Deleting 50 (node with two children)...\n");
    root = deleteNode(root, 50);
    printf("Inorder after deletion: ");
    inorder(root);   /* Output: 40 60 70 80 */
    printf("\n");

    return 0;
}
