// -- Binary Tree - Add Node (Level Order Insertion) -- //

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

// Insert node in level order (fills left to right)
Node* insertNode(Node* root, int data) {
    if (root == NULL) return createNode(data);

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = createNode(data);
            return root;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = createNode(data);
            return root;
        } else {
            queue[rear++] = temp->right;
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

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    printf("Binary Tree after inserting 10, 20, 30, 40, 50:\n");
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
