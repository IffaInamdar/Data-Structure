#include <iostream>
#include <iomanip>
using namespace std;

#define N 8

class Stack {
public:
    int arr[4 * N * N]; // Flattened array for (x, y, move number, move index)
    int top;

    Stack() { top = -1; }

    void push(int x, int y, int move, int moveIdx) {
        arr[++top] = x;
        arr[++top] = y;
        arr[++top] = move;
        arr[++top] = moveIdx;
    }

    void pop(int &x, int &y, int &move, int &moveIdx) {
        moveIdx = arr[top--];
        move = arr[top--];
        y = arr[top--];
        x = arr[top--];
    }

    bool isEmpty() { return top == -1; }
};

bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout << " " << setw(2) << sol[x][y] << " ";
        }
        cout << endl;
    }
}

int solveKT() {
    int sol[N][N];
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    Stack stack;
    int x = 0, y = 0;
    sol[x][y] = 0;
    stack.push(x, y, 1, 0);

    while (!stack.isEmpty()) {
        int move, moveIdx;
        stack.pop(x, y, move, moveIdx);

        if (move == N * N) {
            printSolution(sol);
            return 1;
        }

        bool moved = false;
        for (int k = moveIdx; k < 8; k++) {
            int next_x = x + xMove[k];
            int next_y = y + yMove[k];

            if (isSafe(next_x, next_y, sol)) {
                sol[next_x][next_y] = move;
                stack.push(x, y, move, k + 1); // Save current state and continue from the next move index
                stack.push(next_x, next_y, move + 1, 0); // Move to the next position
                moved = true;
                break;
            }
        }

        if (!moved) {
            sol[x][y] = -1; // Backtrack
        }
    }

    cout << "Solution does not exist" << endl;
    return 0;
}

int main() {
    solveKT();
    return 0;
}
