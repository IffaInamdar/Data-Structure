#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Dummy node to serve as the start of the result list
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (true) {
        // Find the list with the smallest head value
        int minIndex = -1;
        int minValue = INT_MAX;

        // Iterate through the heads of the lists to find the minimum node
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr && lists[i]->val < minValue) {
                minValue = lists[i]->val;
                minIndex = i;
            }
        }

        // If no minimum index is found, all lists are exhausted
        if (minIndex == -1) {
            break;
        }

        // Append the minimum node to the result list
        tail->next = lists[minIndex];
        tail = tail->next;

        // Move the pointer in the list from which the node was taken
        lists[minIndex] = lists[minIndex]->next;
    }

    // Return the merged list
    return dummy->next;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    // Example usage: merging 3 linked lists
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    // Proceed with merging logic as described earlier.
    ListNode* mergedList = mergeKLists(lists);

    // Print or process the merged list.
    printList(mergedList);

    return 0;
}
