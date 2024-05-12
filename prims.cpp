#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int V , vector<vector<int>> adj[]){
    //Priority Queue (Min-Heap)
    //Pair{Weight , Node}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //Visited Array
    vector<int>visited(V,0);
    //Pushing the start Node
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if(visited[node] == 1) continue;
        visited[node]=1;
        sum+=wt;

        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgW = it[1];
            if(!visited[adjNode]){
                pq.push({edgW,adjNode});
            }
        }
    }
    return sum;
}
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj[V];

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges in the format 'u v weight':" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int mst_sum = spanningTree(V, adj);
    cout << "The sum of weights in the minimum spanning tree is: " << mst_sum << endl;

    return 0;
}