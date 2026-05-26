#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Custom Queue Implementation (using circular array)
class Queue {
private:
    TreeNode** arr;  // Array to store tree nodes
    int front, rear, capacity, count;

public:
    // Constructor to initialize the queue with a fixed size
    Queue(int size = 100) {
        arr = new TreeNode*[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    // Function to add an element to the queue
    void enqueue(TreeNode* node) {
        if (count == capacity) {
            std::cout << "Queue overflow\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = node;
        count++;
    }

    // Function to remove an element from the queue
    TreeNode* dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow\n";
            return nullptr;
        }

        TreeNode* node = arr[front];
        front = (front + 1) % capacity;
        count--;
        return node;
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return (count == 0);
    }

    // Function to check the size of the queue
    int size() const {
        return count;
    }
};

// Step 1: In-order traversal to collect values in sorted order
void inOrderTraversal(TreeNode* root, std::vector<int>& values) {
    if (!root) return;
    inOrderTraversal(root->left, values);
    values.push_back(root->val);
    inOrderTraversal(root->right, values);
}

// Step 2: Build the min heap using the collected values
void buildMinHeap(TreeNode* root, std::vector<int>& values, int& index) {
    if (!root) return;

    root->val = values[index++];
    buildMinHeap(root->left, values, index);
    buildMinHeap(root->right, values, index);
}

// Main function to convert BST to Min Heap
TreeNode* bstToMinHeap(TreeNode* root) {
    std::vector<int> values;
    inOrderTraversal(root, values); // Collect values in sorted order

    int index = 0;
    buildMinHeap(root, values, index); // Assign values to the tree to form a min heap
    return root;
}

// Corrected helper function to print the tree in level order (BFS) using custom queue
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    Queue q;  // Initialize custom queue
    q.enqueue(root);

    while (!q.isEmpty()) {
        TreeNode* current = q.dequeue();
        std::cout << current->val << " ";  // Print the current node's value

        if (current->left) q.enqueue(current->left);  // Enqueue left child
        if (current->right) q.enqueue(current->right);  // Enqueue right child
    }
}

// Example usage
int main() {
    // Construct a simple BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    std::cout << "Original BST (Level Order): ";
    printLevelOrder(root);
    std::cout << std::endl;

    // Convert to min heap
    bstToMinHeap(root);

    std::cout << "Converted Min Heap (Level Order): ";
    printLevelOrder(root);
    std::cout << std::endl;

    return 0;
}
