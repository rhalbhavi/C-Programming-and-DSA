// -- BST - Delete Node (Leaf, One Child, Two Children, Root) -- //

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Delete node with given key — handles all 3 cases + root deletion
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    // Search for the node
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found

        // Case 1: No child (leaf)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);      // inorder successor
            root->data = temp->data;                 // replace data
            root->right = deleteNode(root->right, temp->data);  // delete successor
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Initial BST inorder: ");
    inorder(root);
    printf("\n\n");

    // Delete leaf node (20)
    root = deleteNode(root, 20);
    printf("After deleting leaf 20: ");
    inorder(root);
    printf("\n");

    // Delete node with one child (30 has only right child 40)
    root = deleteNode(root, 30);
    printf("After deleting 30 (one child): ");
    inorder(root);
    printf("\n");

    // Delete node with two children (70)
    root = deleteNode(root, 70);
    printf("After deleting 70 (two children): ");
    inorder(root);
    printf("\n");

    // Delete root node (50)
    root = deleteNode(root, 50);
    printf("After deleting root 50: ");
    inorder(root);
    printf("\n");

    return 0;
}
