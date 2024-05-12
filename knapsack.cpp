#include <iostream>
#include <climits>
using namespace std;
//recursive me
int knapSack(int v[], int w[], int n, int W) {
    if (W < 0) //W is negative, exceeded the capacity of knapsack
        return INT_MIN;
    if (n < 0 || W == 0) //considered all items and no more space left
        return 0;
    
   // Include current item and reduce knapsack capacity by weight of the current item
    int include = v[n] + knapSack(v, w, n - 1, W - w[n]);
    
    // Exclude current item and keep knapsack capacity unchanged
    int exclude = knapSack(v, w, n - 1, W);
    // Choose the maximum value between including and excluding the current item
    return max(include, exclude);
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
    
    cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
    
    return 0;
}
