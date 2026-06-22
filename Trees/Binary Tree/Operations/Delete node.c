// -- Binary Tree - Delete Node -- //

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

// Find the deepest (rightmost) node
Node* findDeepest(Node* root) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp = NULL;

    while (front < rear) {
        temp = queue[front++];
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    return temp;
}

// Delete deepest node by replacing target with it
void deleteDeepest(Node* root, Node* dNode) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];

        if (temp == dNode) {
            temp = NULL;
            free(dNode);
            return;
        }
        if (temp->left) {
            if (temp->left == dNode) {
                temp->left = NULL;
                free(dNode);
                return;
            }
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            if (temp->right == dNode) {
                temp->right = NULL;
                free(dNode);
                return;
            }
            queue[rear++] = temp->right;
        }
    }
}

// Delete node with given key from binary tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    // If only one node
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        }
        return root;
    }

    // Find target node and deepest node
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* target = NULL;
    Node* temp = NULL;

    while (front < rear) {
        temp = queue[front++];
        if (temp->data == key) target = temp;
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (target == NULL) {
        printf("Node with value %d not found.\n", key);
        return root;
    }

    // Replace target's data with deepest node's data
    Node* deepest = findDeepest(root);
    target->data = deepest->data;
    deleteDeepest(root, deepest);

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

    printf("Before deletion:\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 20);

    printf("After deleting 20:\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}
