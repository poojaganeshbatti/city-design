#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Utility function to get height
int height(Node* n) {
    return (n == NULL) ? 0 : n->height;
}

// Utility to get maximum
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right Rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get Balance Factor
int getBalance(Node* n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

// Insert into AVL Tree
Node* insert(Node* node, int key) {

    // Normal BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate not allowed

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Check balance
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Educational Institution Use-case:
    // Student Roll Numbers / Course IDs
    int students[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, students[i]);

    cout << "AVL Tree Inorder Traversal:\n";
    inorder(root);

    return 0;
}
