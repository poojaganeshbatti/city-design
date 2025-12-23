#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int value) {
        data = value;
        color = RED;
        left = right = parent = NULL;
    }
};

class RedBlackTree {
private:
    Node* root;

    // Left Rotation
    void rotateLeft(Node* &root, Node* &pt) {
        Node* pt_right = pt->right;

        pt->right = pt_right->left;
        if (pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    // Right Rotation
    void rotateRight(Node* &root, Node* &pt) {
        Node* pt_left = pt->left;

        pt->left = pt_left->right;
        if (pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    // Fix Red-Black Tree violations
    void fixViolation(Node* &root, Node* &pt) {
        Node *parent_pt = NULL;
        Node *grand_parent_pt = NULL;

        while (pt != root && pt->color == RED && pt->parent->color == RED) {
            parent_pt = pt->parent;
            grand_parent_pt = parent_pt->parent;

            // Parent is left child
            if (parent_pt == grand_parent_pt->left) {
                Node* uncle_pt = grand_parent_pt->right;

                // Case 1: Uncle is RED
                if (uncle_pt != NULL && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                // Case 2 & 3
                else {
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            // Parent is right child
            else {
                Node* uncle_pt = grand_parent_pt->left;

                if (uncle_pt != NULL && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else {
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }
        root->color = BLACK;
    }

public:
    RedBlackTree() {
        root = NULL;
    }

    // Insert node
    void insert(int data) {
        Node* pt = new Node(data);

        Node* parent = NULL;
        Node* curr = root;

        while (curr != NULL) {
            parent = curr;
            if (pt->data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        pt->parent = parent;

        if (parent == NULL)
            root = pt;
        else if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;

        fixViolation(root, pt);
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " (" << (root->color == RED ? "R" : "B") << ") ";
        inorder(root->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree tree;

    // Finance use-case: Account / Transaction IDs
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Red-Black Tree Inorder Traversal:\n";
    tree.display();

    return 0;
}
