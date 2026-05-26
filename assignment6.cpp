#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the LCA of two nodes in a BST
Node* findLCA(Node* root, Node* n1, Node* n2) {
    while (root) {
        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (n1->data < root->data && n2->data < root->data) {
            root = root->left;
        }
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (n1->data > root->data && n2->data > root->data) {
            root = root->right;
        } 
        // If one is smaller and the other is larger, or one equals root, root is LCA
        else {
            return root;
        }
    }
    return nullptr;
}

int main() {
    // Creating a sample BST
    Node* root = new Node(10);
    Node* node5 = new Node(5);
    Node* node20 = new Node(20);
    Node* node3 = new Node(3);
    Node* node7 = new Node(7);
    Node* node30 = new Node(30);

    root->left = node5;
    root->right = node20;
    node5->left = node3;
    node5->right = node7;
    node20->right = node30;

    // Find LCA using node pointers
    Node* lca1 = findLCA(root, node3, node7);
    Node* lca2 = findLCA(root, node5, node20);

    if (lca1) {
        std::cout << "LCA of " << node3->data << " and " << node7->data << " is: " << lca1->data << std::endl;
    } else {
        std::cout << "LCA not found." << std::endl;
    }

    if (lca2) {
        std::cout << "LCA of " << node5->data << " and " << node20->data << " is: " << lca2->data << std::endl;
    } else {
        std::cout << "LCA not found." << std::endl;
    }

    return 0;
}
