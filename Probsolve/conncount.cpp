#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100010];
queue<int> q;
bool visited[100010];
//int layer[100010;

void bfs(int node){
    visited[node] = true;
    //layer[node] = 0;

    q.push(node);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(auto it=graph[tmp].begin(); it!=graph[tmp].end(); it++){
            if(visited[*it] == false){
                //layer[*it] = layer[tmp] + 1;
                q.push(*it);
                visited[*it] = true;
            }
        }
    }
}

int main(){
    int n, m, nodea, nodeb, c=0;

    cin >> n >> m;

    for (int i=0; i<m; i++){
        cin >> nodea >> nodeb;
        
        graph[nodea].push_back(nodeb);
        graph[nodeb].push_back(nodea);
    }

    for (int i=1; i<n+1; i++){
        if (visited[i]==true) continue;
        bfs(i);
        c++;
    }

    cout << c << "\n";

}
