#include <iostream>
using namespace std;
#define MAX 100
void swap(int* a, int* b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
void heapify(int arr[], int n, int i) {
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < n && arr[left] > arr[largest])
 largest = left;
 if (right < n && arr[right] > arr[largest]) 
 largest = right;
 if (largest != i) { 
 swap(&arr[i], &arr[largest]);
 heapify(arr, n, largest);
 } 
} 
int main() { 
 int arr[MAX] = {3, 5, 6, 2, 4, 1, 8, 7};
 int n = 8;
 // Build max heap 
 for (int i = n / 2 - 1; i >= 0; i--) { 
 heapify(arr, n, i);
 } 
 // Process execution order 
 cout << "Process Execution Order (Process, Priority):" << endl;
 for (int i = 0; i < n; i++) { 
 swap(&arr[0], &arr[n - 1 - i]);
 cout << arr[n - 1 - i] << endl;
 heapify(arr, n - 1 - i, 0);
 } 
 return 0;
} 
