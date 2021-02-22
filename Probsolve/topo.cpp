#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100010];
int indeg[100010];
bool visited[100010];
stack<int> res;
int zero_ind = 0;

void dfs(int a) {
    visited[a] = true;
    for (auto p=graph[a].begin(); p!=graph[a].end(); p++){
        if (visited[*p]==false) 
            dfs(*p);
    }
    res.push(a);

}

int main(){
    int n, m, u ,v;

    cin >> n >> m;

    for (int i=0; i<m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    for (int i=1; i<n+1; i++){
        if (visited[i]==false) dfs(i);
        if (indeg[i]==0) zero_ind = 1; //0 indegree
    }

    if (zero_ind==1){
        while (!res.empty()){
            cout << res.top() << "\n";
            res.pop();
        }
    }else
        cout << "no" << "\n";
}