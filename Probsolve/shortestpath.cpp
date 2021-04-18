#include <bits/stdc++.h> 

using namespace std; 
#define INF 0x3f3f3f3f 
  
typedef pair<int, int> iPair; 
vector<iPair> adj[100100]; 

void addEdge(int u, int v, int wt){ 

    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 

void shortestPath(int V, int src) { 
    priority_queue<iPair> pq; 
    int dist[100100];
    int mark[100100];
    
    for (int i=1; i<=V; i++){
        dist[i] = 1<<30;
        mark[i] = 0;
    }

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) {  
        int u = pq.top().second; 
        int wet = pq.top().first*(-1);
        pq.pop(); 
        // if (mark[u]) continue;
        // mark[u] = 1;
        // cout << u << wet << "\n";
        for (auto x : adj[u]){ 

            int v = x.first; 
            int weight = x.second; 
  
            if (dist[v] > wet + weight) { 

                dist[v] = wet + weight; 
                pq.push(make_pair(dist[v]*(-1), v)); 
            } 
        } 
    } 

    // for (int i=0; i<=V; i++){
    //     cout << dist[i] << "\n";
    // }
    cout << dist[V] << "\n";
} 

int main(){
    int n, m, a, b, w;

    cin >> n >> m;
    
    for (int i=0; i<m; i++){
        cin >> a >> b >> w;
        addEdge(a, b, w);
    }
    
    shortestPath(n, 1); 

    return 0; 
} 