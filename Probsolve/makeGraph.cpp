#include<bits/stdc++.h>

using namespace std;

vector<int> graph[100];
bool visited[100];
int layer[100];

void init(){
    int node, edge;
    int nodeA, nodeB;
    int i;
    cin >> node >> edge;

    for(i=0; i<node; i++){
        visited[i] = false;
    }

    for(i=0; i<edge; i++){
        cin >> nodeA >> nodeB;

        graph[nodeA].push_back(nodeB);
        graph[nodeB].push_back(nodeA);
    }
}

void bfs(int s){
    layer[s] = 0;
    visited[s] = true;

    // เอา node มาเข้า queue
    queue<int> q;
    q.push(s);

    cout << "Node is " << s << " in layer " << layer[s] << '\n';
    while(!q.empty()){
        int  u = q.front();
        q.pop();
        // cout << "Node is " << u << " in layer " << layer << '\n';

        // ตามหาลูกๆ
        for(auto it=graph[u].begin(); it!=graph[u].end(); it++){
            if(visited[*it] == false){
                layer[*it] = layer[u] + 1;
                cout << "Node is " << *it << " in layer " << layer[*it] << '\n';
                q.push(*it);
                visited[*it] = true;
            }
        }
    }
}

int main(){
    init();
    bfs(4);
    return 0;
} 