#include<iostream>
using namespace std;

int a[20][20], visited[20], n;

void dfs(int v) {
    cout << v << " ";
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (a[v][i] != 0 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> n;
    
    cout << "Enter graph data in matrix form:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> v;
    
    cout << "DFS Traversal is: \n";
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    dfs(v);

    return 0;
}

