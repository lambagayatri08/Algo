#include <iostream>
#include <climits>
using namespace std;

// Define the maximum number of items
const int MAX_N = 100;

// Memoization array to store results of subproblems
int memo[MAX_N][MAX_N];

// Recursive method with memoization
int knapSack(int v[], int w[], int n, int W) {
    if (W < 0) //W is negative, exceeded the capacity of knapsack
        return INT_MIN;
    if (n < 0 || W == 0) //considered all items and no more space left
        return 0;
    
    // If result is already computed, return it
    if (memo[n][W] != -1)
        return memo[n][W];
    
    // Include current item and reduce knapsack capacity by weight of the current item
    int include = v[n] + knapSack(v, w, n - 1, W - w[n]);
    // Exclude current item and keep knapsack capacity unchanged
    int exclude = knapSack(v, w, n - 1, W);
    // Choose the maximum value between including and excluding the current item
    memo[n][W] = max(include, exclude);
    
    return memo[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    
    int v[n], w[n];
    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Value of item " << i + 1 << ": ";
        cin >> v[i];
    }
    
    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> w[i];
    }
    
    int W;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    
    // Initialize memoization array with -1
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            memo[i][j] = -1;
    
    cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
    
    return 0;
}
