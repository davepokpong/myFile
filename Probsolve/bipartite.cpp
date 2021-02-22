#include <bits/stdc++.h>

using namespace std;

int color[100010];
bool visited[100010];
queue<int> q;
vector<int> graph[100010];
vector<int>::iterator p;

bool bfs_checkbi(int a){
    visited[a] = true;
    color[a] = 1;
    bool check=false;
    q.push(a);
    while(!q.empty()){
        int temp = q.front();

        for (p=graph[temp].begin(); p!=graph[temp].end(); p++){
            if (color[temp]==1 && color[*p]==0) color[*p]=2;
            if (color[temp]==2 && color[*p]==0) color[*p]=1;
            if (color[temp]==color[*p]) check=true;
            if (visited[*p] == false){
                visited[*p] = true;
                q.push(*p);
            }
        }
        q.pop();
    }
    // if (check) cout << "no\n";
    // else cout << "yes\n";
    return check;
}

int main(){
    
    int n, m, k, u, v;
    bool ans;
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> n >> m;
        ans = false;
        for (int j=0; j<m; j++){
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int j=1; j<=n; j++){
            if (!visited[j]) ans |= bfs_checkbi(j);
            // cout << ans << "\n";
        }

        if (ans) cout << "no\n";
        else cout << "yes\n";

        for (int j=1; j<=n; j++){
            graph[j].clear();
            color[j]=0;
            visited[j]=false;
        }
    }
}