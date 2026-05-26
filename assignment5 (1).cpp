#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function prototypes
void insert(node*& root, int key);
void search(node* root, int key);
node* findPreorderPred(node* root, int key);
node* findInorderPred(node* root, int key);
node* findPostorderPred(node* root, int key);

// Insert a new node in the BST
void insert(node*& root, int key) { 
    if (root == nullptr) {
        root = new node(key);
    } else if (key < root->data) {
        insert(root->left, key);   
    } else {
        insert(root->right, key);
    }
}

// Search for a key in the BST
void search(node* root, int key) { 
    if (root == nullptr) {
        cout << "Key not found!" << "\n"; 
        return;
    }
    if (key == root->data) {
        cout << "Key found!" << "\n"; 
        return;
    }
    if (key < root->data) {
        search(root->left, key); 
    } else {
        search(root->right, key); 
    }
}

// Helper function for preorder predecessor
void preorderHelper(node* root, int key, node*& pred, node*& prev) {
    if (root == nullptr) return;

    if (root->data == key && prev != nullptr) {
        pred = prev;
    }
    prev = root;
    preorderHelper(root->left, key, pred, prev);
    preorderHelper(root->right, key, pred, prev);
}

node* findPreorderPred(node* root, int key) {
    node* pred = nullptr;
    node* prev = nullptr;
    preorderHelper(root, key, pred, prev);
    return pred;
}

// Helper function for inorder predecessor
void inorderHelper(node* root, int key, node*& pred, node*& prev) {
    if (root == nullptr) return;

    inorderHelper(root->left, key, pred, prev);

    if (root->data == key && prev != nullptr) {
        pred = prev;
    }
    prev = root;

    inorderHelper(root->right, key, pred, prev);
}

node* findInorderPred(node* root, int key) {
    node* pred = nullptr;
    node* prev = nullptr;
    inorderHelper(root, key, pred, prev);
    return pred;
}

// Helper function for postorder predecessor
void postorderHelper(node* root, int key, node*& pred, node*& prev) {
    if (root == nullptr) return;

    postorderHelper(root->left, key, pred, prev);
    postorderHelper(root->right, key, pred, prev);

    if (root->data == key && prev != nullptr) {
        pred = prev;
    }
    prev = root;
}

node* findPostorderPred(node* root, int key) {
    node* pred = nullptr;
    node* prev = nullptr;
    postorderHelper(root, key, pred, prev);
    return pred;
}

// Main function
int main() {
    node* root = nullptr;

    // Insert nodes
    insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 3);
    insert(root, 9);
    insert(root, 5);
    insert(root, 8);

    int key = 8;
    search(root, key);

    // Find and display preorder predecessor
    node* preorderP = findPreorderPred(root, key);
    if (preorderP) {
        cout << "Preorder predecessor: " << preorderP->data << "\n";
    } else {
        cout << "No preorder predecessor found!" << "\n";
    }

    // Find and display inorder predecessor
    node* inorderP = findInorderPred(root, key);
    if (inorderP) {
        cout << "Inorder predecessor: " << inorderP->data << "\n";
    } else {
        cout << "No inorder predecessor found!" << "\n";
    }

    // Find and display postorder predecessor
    node* postorderP = findPostorderPred(root, key);
    if (postorderP) {
        cout << "Postorder predecessor: " << postorderP->data << "\n";
    } else {
        cout << "No postorder predecessor found!" << "\n";
    }

    return 0;
}
