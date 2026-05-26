#include <iostream>
using namespace std;

// Function to calculate the combination C(n, r)
int combination(int n, int r) {
    int result = 1;
    // Calculate nCr without calculating factorials directly
    for (int i = 1; i <= r; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main() {
    int n = 14; // Total moves (right + down) in an 8x8 grid
    int r = 7;  // Moves in one direction (right or down)

    // Calculate the number of unique paths
    int uniquePaths = combination(n, r);
    cout << "The number of unique paths in an 8x8 grid is: " << uniquePaths << endl;

    return 0;
}
