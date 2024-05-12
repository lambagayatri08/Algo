#include<iostream>
using namespace std;

int a[20][20], visited[20], q[20], n, f = -1, r = -1;

void bfs(int v) {
    for (int i = 0; i < n; i++) {
        if (a[v][i] != 0 && visited[i] == 0) {
            r = r + 1;
            q[r] = i;
            visited[i] = 1;
            cout << " " << i; 
        }
    }
    f = f + 1;
    if (f <= r) {
        bfs(q[f]);
    }
}

int main() {
    int v, i, j;
    cout << "Enter number of vertices: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    cout << "Enter graph data in matrix form:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> v;

    f = r = 0;
    q[r] = v;
    cout << "\nBFS traversal is:\n";
    visited[v] = 1;
    cout << v;
    bfs(v);
    for (int i = 0; i < n; i++) { // Checking if all vertices are visited
        if (visited[i] == 0) {
            cout << "\nBFS is not possible\n";
            return 0;
        }
    }
    return 0;
}
